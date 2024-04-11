#include<cstdio>
#include<iostream>
using namespace std;
int main(){
  int i,n,m,k,a;
  long long ans,t;
  cin>>n>>m>>k;
  if(n/2+1>m||n%2==0){
    cout<<0<<endl;
    return 0;
  }
  t=m/(n/2+1);
  ans=t*k;
  for(i=0;i<n;i++){
    cin>>a;
    ans=ans>a?a:ans;
    cin>>a;
  }
  cout<<ans<<endl;
  return 0;
}