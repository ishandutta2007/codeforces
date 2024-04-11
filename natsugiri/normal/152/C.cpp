#include<string>
#include<iostream>
using namespace std;

int main(){
  int n,m,i,j,t,a[26];
  string s[100];
  long long ans=1,MOD=1000000007;
  cin>>n>>m;
  for(i=0;i<n;i++)cin>>s[i];
  for(j=0;j<m;j++){
    t=0;
    for(i=0;i<26;i++)a[i]=0;
    for(i=0;i<n;i++){
      a[s[i][j]-'A']++;
    }
    for(i=0;i<26;i++)if(a[i])t++;
    ans=ans*t%MOD;
  }
  
  cout<<ans<<endl;
  return 0;
}