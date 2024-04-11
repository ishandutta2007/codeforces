#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int n=s.size();
  vector<long long> seq(n+1);
  seq[0]=1;
  seq[1]=1;
  for(int i=2;i<=n;i++){seq[i]=(seq[i-1]+seq[i-2])%mod;}
  long long res=1;
  for(int i=0;i<n;i++){
    if(s[i]=='w' || s[i]=='m'){res=0;}
  }
  s.push_back('*');
  int c=1;
  for(int i=1;i<=n;i++){
    if(s[i-1]!=s[i]){
      if(s[i-1]=='u' || s[i-1]=='n'){res*=seq[c];res%=mod;}
      c=1;
    }
    else{c++;}
  }
  cout << res << '\n';
  return 0;
}