#include<iostream>
using namespace std;
int main(){
  int n,x,y;
  cin>>n>>x>>y;
  n/=2;
  if((n==x||n+1==x)&&(n==y||n+1==y))cout<<"NO";
  else cout<<"YES";
  cout<<endl;
  return 0;
}