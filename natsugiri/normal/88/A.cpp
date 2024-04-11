#include<iostream>
#include<string>

using namespace std;
int code(string s){
  int n;
  if(s[0]>='C'&&s[0]<'F')n=(s[0]-'C')*2;
  if(s[0]>'E'&&s[0]<'H')n=5+(s[0]-'F')*2;
  if(s[0]=='A')n=9;
  if(s[0]=='B')n=10;
  if(s[0]=='H')n=11;
  if(s.size()>1)n++;
  return n;
}
int main(){
  string a,b,c;
  int x,y,z,i,j;
  cin>>a>>b>>c;
  x=code(a);
  y=code(b);
  z=code(c);
  if(x>y){
    i=x;
    j=y;
    if(z>x)i=z;
    if(y>z)j=z;
  }else{
    i=y;
    j=x;
    if(z>y)i=z;
    if(x>z)j=z;
  }
  y=x+y+z-i-j;
  x=j;z=i;
  i=y-x;
  j=z-y;
if((i==4&&j==3)||(i==3&&j==5)||(i==5&&j==4))cout<<"major";
  else if((i==3&&j==4)||(i==4&&j==5)||(i==5&&j==3))cout<<"minor";
  else cout<<"strange";
  cout<<endl;
  return 0;
}