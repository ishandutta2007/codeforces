#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)4e5 + 10;
const int K = (1 << 8);
const int inf = (int)1e9;
vector<int> ids[N];

int dp[N][K];

int popcount(int x){
  return __builtin_popcount(x);
}

int main(){
  fastIO;
  int n, useless, k;
  cin >> n >> useless >> k;
  vector<int> pp;
  vector<pii> tt(n);
  pp.push_back(0);
  for(int i = 0 ; i < n; i ++ ){
    cin >> tt[i].fi >> tt[i].se;
    pp.push_back(tt[i].fi);
    pp.push_back(tt[i].se);
  }
  sort(pp.begin(), pp.end());
  pp.resize(unique(pp.begin(), pp.end()) - pp.begin());
  vector<pii> segs;
  for(int i = 0 ; i < pp.size(); i ++ ){
    segs.push_back(mp(pp[i], pp[i]));
    if(i + 1 < pp.size() && pp[i] + 1 <= pp[i + 1] - 1){
      segs.push_back(mp(pp[i] + 1, pp[i + 1] - 1));
    }
  }
  int m = segs.size();
  int x, y;
  for(int i = 0 ; i < n; i ++ ){
    x = tt[i].fi;
    y = tt[i].se;
    x = lower_bound(segs.begin(), segs.end(), mp(x, -1)) - segs.begin();
    while(x < m){
      if(segs[x].fi > y) break;
      ids[x].push_back(i);
      x ++ ;
    }
  }
  for(int i = 0 ; i < n; i ++ ){
    for(int j = 0 ; j < (1 << k) ; j ++ ){
      dp[i][j] = -inf;
    }
  }
  dp[0][0]=0;
  int s1;
  int s2;
  int ans = 0;
  int orr;
  int o1, o2;
  for(int i = 0 ; i + 1 < m ; i ++ ){
    s1 = ids[i].size();
    vector<int> keep;
    for(int p = 0 ; p < s1; p  ++ ){
      keep.push_back(-1);
      for(int q = 0; q < ids[i + 1].size(); q ++ ){
        if(ids[i + 1][q] == ids[i][p])
          keep.back() = q;
      }
    }
    for(int m1 = 0; m1 < (1 << s1); m1 ++ ){
      if(dp[i][m1] == -inf) continue;
      orr = 0;
      for(int j = 0 ; j < s1; j ++ ){
        if(keep[j] != -1){
          if((m1 & (1 << j))){
            orr |= (1 << keep[j]);
          }
        }
      }
      dp[i + 1][orr] = max(dp[i + 1][orr], dp[i][m1]);
    }
    vector<int> k1;
    vector<int> k2;
    bool is;
    for(int p = 0 ; p < (int)ids[i + 1].size(); p ++ ){
      is = false;
      for(int q = 0; q < ids[i].size(); q ++ ){
        if(ids[i][q]==ids[i+1][p])
          is=true;
      }
      if(is)
        k1.push_back(p);
      else
        k2.push_back(p);
    }
    for(int p = 0 ; p < (1 << (int)k1.size()); p ++ ){
      for(int q = 0; q < (1 << (int)k2.size()); q ++ ){
        o1 = 0;
        o2 = 0;
        for(int d = 0; d < k1.size(); d ++ ){
          if((p & (1 << d)))o1 |= (1 << k1[d]);
        }
        for(int d = 0; d < k2.size(); d ++ ){
          if((q & (1 << d)))o2 |= (1 << k2[d]);
        }
        dp[i + 1][(o1 | o2)] = max(dp[i + 1][(o1 | o2)], dp[i + 1][o1]);
        // i feel this will result in TLE
      }
    }
    for(int t = 0; t < (1 << (int)ids[i + 1].size()); t ++ ){
      if(dp[i + 1][t] == -inf) continue;
      dp[i + 1][t] += (segs[i + 1].se - segs[i + 1].fi + 1) * (popcount(t) & 1);
      ans = max(ans, dp[i + 1][t]);
    }
  }
  cout << ans << "\n";
  return 0;
}