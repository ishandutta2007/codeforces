#include<iostream>
using namespace std;
int main(){
  int n,i;
  long long x,y;
  cin>>n>>x>>y;
  if((y-n+1)*(y-n+1)+(n-1)<x||n>y)cout<<-1<<endl;
  else{
  cout<<y-n+1<<endl;
  for(i=1;i<n;i++){
    cout<<1<<endl;
  }
  }
  return 0;
}