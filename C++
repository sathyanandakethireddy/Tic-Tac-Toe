#include <iostream>
#include <string.h>
using namespace std;
string n1;
string n2;
int row,col;
bool tie;
char arr[3][3]={{'1','2','3'},
{'4','5','6'},
{'7','8','9'}};
char token='X';
char token2;
void Players()
{
    cout<<"Enter Player1 Name :";
    cin>>n1;
    cout<<"Enter the Player2 Name :";
    cin>>n2;
    
}
void Display()
{
    cout << "           |           |           " << endl;
    cout << "     " << arr[0][0] << "     |     " << arr[0][1] << "     |     " << arr[0][2] << "     " << endl;
    cout << "___________|___________|___________" << endl;
    cout << "           |           |           " << endl;
    cout << "     " << arr[1][0] << "     |     " << arr[1][1] << "     |     " << arr[1][2] << "     " << endl;
    cout << "___________|___________|___________" << endl;
    cout << "           |           |           " << endl;
    cout << "     " << arr[2][0] << "     |     " << arr[2][1] << "     |     " << arr[2][2] << "     " << endl;
    cout << "           |           |           " << endl;
  
}
void Inputs()
{
   char ch;
   cout<<"Please Enter The Valid Inputs 0-9"<<endl;
   if(token=='X')
   {
      cout<<"Player "<<n1<<": ";
      cin>>ch;
   }
   if(token=='0')
   {
      cout<<"Player "<<n2<<": ";
      cin>>ch;
   }

   if(ch >='1' && ch<='9')
   {
      if(ch=='1'){row=0;col=0;}
      else if(ch=='2'){row=0;col=1;}
      else if(ch=='3'){row=0;col=2;}
      else if(ch=='4'){row=1;col=0;}
      else if(ch=='5'){row=1;col=1;}
      else if(ch=='6'){row=1;col=2;}
      else if(ch=='7'){row=2;col=0;}
      else if(ch=='8'){row=2;col=1;}
      else if(ch=='9'){row=2;col=2;}

   }
   else
   {
     cout<<"Enter Valued is Invalid Input"<<endl;
   }
   if(arr[row][col]=='X' || arr[row][col]=='0')
   {
      cout<<"This Cell is Already Filled,Please Enter Different Cell"<<endl;
      Inputs();
   }
   if(arr[row][col]!='X' && arr[row][col]!='0')
   {
      arr[row][col]=token=='X' ? 'X' : '0';
      token=token=='X' ? '0':'X';
   }
}
int function3()
{
   for(int i=0;i<3;i++)
   {
      if((arr[i][0]==arr[i][1] && arr[i][0]==arr[i][2]) )
      {
         token2=arr[i][0];
         return true;
      }
      if (arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i]) 
      {
         token2 = arr[0][i];
         return true;
      }
   }
   if(arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2])
   {
      token2=arr[0][0];
      return true;
   }
   if(arr[0][2]==arr[1][1] && arr[1][1]==arr[2][0])
   {
      token2=arr[0][2];
      return true;
   }
   for(int i=0;i<3;i++)
   {
     for(int j=0;j<3;j++)
     {
       if(arr[i][j]!='X' && arr[i][j]!='0')
       {
          return false;
       }
     }
   }
   tie =true;
   return true;
}
int main()
{
  Players();
  while(!function3())
  {
   Inputs();
   Display();
  }
  if(token2=='X')
  {
    cout<<"Player "<<n1<<" Won The Game"<<endl;
  }
  if(token2=='0')
  {
    cout<<"Player "<<n2<<" Won The Game"<<endl;
  }
  if(tie)
  {
    cout<<"Game is Tie,Try Again"<<endl;
  }
}
