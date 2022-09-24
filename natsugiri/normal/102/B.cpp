#include<iostream>
#include<string>
using namespace std;
int main(){
  string str;
  int n,i,t,ans;
  cin>>str;
  n=0;
  for(i=0;i<str.size();i++){
    n+=str[i]-'0';
  }
  ans=1;
  for(;n>9;){
    ans++;
    for(t=0;n;n/=10){
      t+=n%10;
    }
    n=t;
  }
  if(str.size()==1)ans=0;
  cout<<ans<<endl;
  return 0;
}