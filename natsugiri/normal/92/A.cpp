#include<iostream>
using namespace std;
int main(){
  int n,m,i;
  cin>>n>>m;
  n=n*(n+1)/2;
  m%=n;
  for(i=1;m-i>=0&&i<=n;i++)m-=i;
  cout<<m<<endl;
  return 0;
}