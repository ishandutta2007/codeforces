#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m,res=-1e9;
    vector<int> rar;
    cin >> n >> m;
    vector<int> tg(n);
    for(auto &nx : tg){cin >> nx;}
    vector<string> s(n);
    for(auto &nx : s){cin >> nx;}
    for(int i=0;i<(1<<n);i++){
      vector<pair<int,int>> pv;
      for(int j=0;j<m;j++){
        int cs=0;
        for(int k=0;k<n;k++){
          if(s[k][j]=='0'){continue;}
          if(i&(1<<k)){cs++;}
          else{cs--;}
        }
        pv.push_back({cs,j});
      }
      sort(pv.begin(),pv.end());
      vector<int> ass(m);
      for(int j=0;j<m;j++){ass[pv[j].second]=j+1;}
      int cr=0;
      for(int j=0;j<n;j++){
        int cp=0;
        for(int k=0;k<m;k++){
          if(s[j][k]=='1'){cp+=ass[k];}
        }
        cr+=abs(tg[j]-cp);
      }
      if(res<cr){
        res=cr;
        rar=ass;
      }
    }
    for(int i=0;i<m;i++){
      if(i){cout << ' ';}
      cout << rar[i];
    }cout << '\n';
  }
  return 0;
}