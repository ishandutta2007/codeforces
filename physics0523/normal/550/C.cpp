#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<string> dp(8);
  vector<bool> fl(8,false);
  string s;
  cin >> s;
  int l=s.size();

  for(int i=0;i<l;i++){
    vector<string> ndp=dp;
    vector<bool> nfl=fl;
    int cur=s[i]-'0';
    for(int j=0;j<8;j++){
      if(fl[j]){
        int tg=(10*j+cur)%8;
        if(!nfl[tg]){
          nfl[tg]=true;
          ndp[tg]=dp[j]+to_string(cur);
        }
      }
    }
    if(!nfl[cur%8]){
      nfl[cur%8]=true;
      ndp[cur%8]=to_string(cur);
    }
    dp=ndp;
    fl=nfl;
  }

  if(fl[0]){cout << "YES\n" << dp[0] << '\n';}
  else{cout << "NO\n";}
  return 0;
}