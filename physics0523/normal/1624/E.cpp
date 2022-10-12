#include<bits/stdc++.h>

using namespace std;

typedef struct{
  int l,r,i;
}seg;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;

    int n,m;
    cin >> n >> m;
    map<string,seg> mp;
    map<string,bool> fl;
    for(int i=0;i<n;i++){
      string s;
      cin >> s;
      for(int j=2;j<m;j++){
        string tg;
        tg.push_back(s[j-2]);
        tg.push_back(s[j-1]);
        tg.push_back(s[j]);
        mp[tg]={j-1,j+1,i+1};
        fl[tg]=true;
      }
      for(int j=1;j<m;j++){
        string tg;
        tg.push_back(s[j-1]);
        tg.push_back(s[j]);
        mp[tg]={j,j+1,i+1};
        fl[tg]=true;
      }
    }
    string s;
    cin >> s;

    if(m==1){cout << "-1\n";continue;}
    vector<seg> dp(m+1,{-1,-1,-1});
    dp[0]={0,0,0};
    for(int i=0;i<m;i++){
      if(dp[i].l<0){continue;}
      if(i+2<m){
        string tg;
        tg.push_back(s[i]);
        tg.push_back(s[i+1]);
        tg.push_back(s[i+2]);
        if(fl[tg]){
          dp[i+3]=mp[tg];
        }
      }
      if(i+1<m){
        string tg;
        tg.push_back(s[i]);
        tg.push_back(s[i+1]);
        if(fl[tg]){
          dp[i+2]=mp[tg];
        }
      }
    }
    if(dp[m].l<0){cout << "-1\n";continue;}
    vector<seg> res;
    int pt=m;
    while(pt>0){
      res.push_back(dp[pt]);
      pt-=(dp[pt].r-dp[pt].l+1);
    }
    reverse(res.begin(),res.end());
    cout << res.size() << '\n';
    for(auto &nx : res){cout << nx.l << ' ' << nx.r << ' ' << nx.i << '\n';}
  }
  return 0;
}