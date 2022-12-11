#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1005;
int a[N];
int dig[N][N];
bool has[N][N];
int cost[10];
int dp[N+1][N];
int ord[N+1][N];
int idx[N+1][N];
int vl[N];

vector<pii> gg[10];

int main(){
  fastIO;
  for(int i = 0 ; i <= N ; i ++ ){
    for(int j = 0 ; j < N ;j ++ ){
      dp[i][j] = -(int)1e9;
    }
  }
  string t;
  cin >> t;
  int p = N;
  for(int i = t.size() - 1; i >= 0 ; i -- ){
    p -- ;
    if(t[i] == '?') a[p] = -1;
    else a[p] = t[i] - '0';
  }
  
  int pos = p;
  int n;
  cin >> n;
  for(int i = 0 ; i < n ; i ++ ){
    cin >> t;
    p = N;
    for(int j = (int)t.size() - 1; j >= 0; j -- ){
      p -- ;
      dig[i][p] = t[j] - '0';
      has[i][p]=true;
    }
  }
  for(int j = 0 ; j < 10 ; j ++ )
    cin >> cost[j];
  for(int i = 0 ; i < n ; i ++ ){
    ord[N][i] = i;
  }
  int c;
  for(int i = N-1; i >= 0 ; i -- ){
    for(int j = 0 ; j < 10; j ++ ){
      gg[j].clear();
    }
    for(int j = 0 ; j < n; j ++ ){
      gg[dig[j][i]].push_back(mp(ord[i+1][j],j));
    }
    for(int j = 0 ; j < 10 ; j ++ ){
      sort(gg[j].begin(), gg[j].end());
    }
    c = 0;
    for(int j = 9 ; j >= 0 ; j -- ){
      for(auto x : gg[j]){
        ord[i][x.se] = c;
        c ++ ;
      }
    }
  }
  for(int i = 0 ; i < N + 1; i ++ ){
    for(int j = 0 ; j < n ; j ++ ){
      idx[i][ord[i][j]]=j;
    }
  }
  dp[N][0] = 0;
  int add;
  int qid;
  int id;
  int tot;
  int ss;
  for(int i = N-1; i >= 0 ; i -- ){
    vector<int> stg;
    if(a[i] == -1) for(int j = (i == pos); j <= 9; j ++ ) stg.push_back(j);
    else stg.push_back(a[i]);
    for(auto q : stg){
      add = 0;
      for(int j = 0 ; j < n ; j ++ ){
        vl[j] = 0;
      }
      for(int j = 0 ; j < n ; j ++ ){
        ss = (dig[j][i]+q);
        if(ss == 0 && i < pos && !has[j][i]) continue;
        vl[j] = cost[ss%10];
        add += vl[j];
      }
      qid = 0;
      for(int t = 0 ;t <= n; t ++ ){ // :(((((((((((((((((((((((((((((((
        while(qid < n){
          id = idx[i][qid];
          ss = (dig[id][i]+q+(ord[i+1][id]<t));
          if(ss == 0 && i < pos && !has[id][i]) break;
          add -= vl[id];
          vl[id] = cost[ss%10];
          add += vl[id];
          if(ss >= 10) qid ++ ;
          else break;
        }
        dp[i][qid] = max(dp[i][qid], dp[i+1][t]+add);
        if(t < n){
          id = idx[i+1][t];
          ss = (dig[id][i]+q+1);
          add -= vl[id];
          vl[id] = cost[ss%10];
          add += vl[id];
        }
      }
    }
  }
  cout << dp[0][0];
  return 0; 
}