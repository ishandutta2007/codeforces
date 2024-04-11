#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

typedef long long LL;
#define MOD 1000000007


string s,t;

LL d[5005][5005];

int main(){
  cin>>s>>t;
  int n=s.size(),m=t.size();
  d[0][0]=1;
  for(int i=0;i<=n;i++)d[i][0]=1;
  for(int j=0;j<=m;j++)d[0][j]=1;
  
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      d[i][j]=d[i][j-1];
      if(s[i-1]==t[j-1])d[i][j]=(d[i][j]+d[i-1][j-1])%MOD;
    }
    d[i][m]=(d[i][m]+d[i-1][m])%MOD;
  }
  cout<<(d[n][m]-n-1+MOD)%MOD<<endl;

  return 0;
}