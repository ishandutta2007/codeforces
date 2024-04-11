#include<iostream>
using namespace std;
int main(){
  int n,m,a,b;
  cin>>n>>m>>a>>b;
  if((a-1)/m==(b-1)/m)cout<<1<<endl;
  else if(m==1)cout<<1<<endl;
  else if(a%m==1&&b%m==0)cout<<1<<endl;
  else if(a%m==1&&b==n)cout<<1<<endl;
  else if(a%m==1||b%m==0)cout<<2<<endl;
  else if((a-1)%m-1==(b-1)%m)cout<<2<<endl;
  else if((a-1)/m+1==(b-1)/m)cout<<2<<endl;
  else if(b==n)cout<<2<<endl;
  else cout<<3<<endl;
  return 0;
}