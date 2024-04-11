#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<vector<pii>> nx(n);
  vector<vector<int>> vis(n);
  vector<vector<int>> cyc(n);
  vector<vector<int>> ct(n);
  vector<vector<int>> dis(n);
  vector<vector<int>> can;
  vector<vector<pii>> rch(n);
  for(int i = 0 ; i < n; i ++ ){
    g[i].resize(m);
    nx[i].resize(m);
    cyc[i].resize(m, -1);
    vis[i].resize(m, -1);
    ct[i].resize(m, -1);
    dis[i].resize(m, -1);
    rch[i].resize(m);
    char q;
    for(int j = 0 ; j < m ; j ++ ){
      cin >> q;
      g[i][j] = q - '0';
      g[i][j] ^= 1;
    }
  }
  for(int i = 0 ; i < n; i ++ ){
    char q;
    for(int j = 0 ; j < m ; j ++ ){
      cin >> q;
      if(q == 'L') nx[i][j] = mp(i,j-1);
      if(q == 'R') nx[i][j] = mp(i,j+1);
      if(q == 'U') nx[i][j] = mp(i-1,j);
      if(q == 'D') nx[i][j] = mp(i+1,j);
    }
  }
  int cnt = 0;
  int id;
  int sz;
  int eq;
  int dd;
  for(int i = 0 ; i < n; i ++ ){
    for(int j = 0 ; j < m; j ++ ){
      if(vis[i][j] != -1) continue;
      vector<pii> cur;
      pii tt = mp(i,j);
      while(vis[tt.fi][tt.se] == -1){
        cur.push_back(tt);
        vis[tt.fi][tt.se] = 0;
        tt = nx[tt.fi][tt.se];
      }
      int pq = 0;
      eq = 0;
      for(int k = 0 ; k < cur.size(); k ++ ){
        if(cur[k] == tt)
          eq = k;
      }
      if(vis[tt.fi][tt.se] == 0){
        can.push_back({});
        for(int t = eq; t < cur.size(); t ++ ){
          cyc[cur[t].fi][cur[t].se] = pq;
          vis[cur[t].fi][cur[t].se] = 3;
          ct[cur[t].fi][cur[t].se] = cnt;
          rch[cur[t].fi][cur[t].se] = cur[t];
          dis[cur[t].fi][cur[t].se] = 0;
          pq ++ ;
          can.back().push_back(g[cur[t].fi][cur[t].se]);
        }
        while(cur.size() > eq) cur.pop_back();
        cnt ++ ;
        for(auto x : cur){
          rch[x.fi][x.se] = rch[tt.fi][tt.se];
        }
      }
      else{
        for(auto x : cur){
          rch[x.fi][x.se] = rch[tt.fi][tt.se];
        }
      }
      dd = dis[tt.fi][tt.se];
        for(int j = (int)cur.size() - 1; j >= 0 ; j -- ){
          dd ++ ;
          dis[cur[j].fi][cur[j].se] = dd;
        }
      for(auto x : cur)
        vis[x.fi][x.se] = 3;
    }
  }
  pii ry;
  int pos;
  for(int i = 0 ; i < n; i ++ ){
    for(int j = 0 ; j < m ; j ++ ){
      if(cyc[i][j] == -1){
        ry = rch[i][j];
        id = ct[ry.fi][ry.se];
        pos = (cyc[ry.fi][ry.se] - dis[i][j]) % (int)can[id].size();
        if(pos < 0) pos += can[id].size();
        can[id][pos] |= g[i][j];
      }
    }
  }
  int a0 = 0, a1 = 0;
  for(int i = 0 ; i < cnt ; i ++ ){
    a0 += can[i].size();
    for(auto x : can[i]) a1 += x;
  }
  cout << a0 << " " << a1 << "\n";
}

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0 ;t < tc; t ++ ){
    solve();
  }
  return 0;
}