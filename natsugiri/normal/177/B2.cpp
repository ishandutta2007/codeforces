#include<iostream>
using namespace std;


int main(){
  long long ans, n;

  cin>>n;

  ans=n;
  
  for(int i=2; i*i<=n; i++){
    for(;n%i==0;){
      ans+=n/i;
      n/=i;
    }
  }
  if(n>1)ans++;

  cout<<ans<<endl;
  
  return 0;
}