#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
typedef pair<ld, ld> pdd;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)1e4 + 9;
vector<int> R[N], C[N];

const int M = (int)4e4 + 9;
int ii[M], jj[M];
int dis[M];
map<pii, int> idx;

int dir[4][2] = {{-1,0},{+1,0},{0,-1},{0,+1}};

int main(){
  fastIO;
  int n, m, k;
  cin >> n >> m >> k;
  for(int i = 1; i <= k ; i ++ ){
    cin >> ii[i] >> jj[i];
    R[ii[i]].push_back(i);
    C[jj[i]].push_back(i);
  }
  for(int i = 1; i <= n; i ++ ){
    k ++ ;
    ii[k] = i;
    jj[k] = -1;
  }
  for(int i = 1; i <= m ; i ++ ){
    k ++ ;
    ii[k] = -1;
    jj[k] = i;
  }
  for(int i = 1; i <= k ; i ++ ){
    idx[mp(ii[i],jj[i])] = i;
    dis[i] = -1;
  }
  deque<int> bf;
  bf.push_back(idx[mp(1,1)]);
  dis[idx[mp(1,1)]] = 0;
  int node;
  int ni, nj;
  int ci, cj;
  int id;
  while(!bf.empty()){
    node = bf.front();
    bf.pop_front();
    if(ii[node] == -1){
      for(int p = -1; p <= +1; p ++ ){
        for(auto x : C[jj[node] + p]){
          if(dis[x] == -1 || dis[x] > dis[node]){
            dis[x] = dis[node];
            bf.push_front(x);
          }
        }
        C[jj[node] + p].clear();
      }
    }
    else if(jj[node] == -1){
      for(int p = -1; p <= +1; p ++ ){
        for(auto x : R[ii[node] + p]){
          if(dis[x] == -1 || dis[x] > dis[node]){
            dis[x] = dis[node];
            bf.push_front(x);
          }
        }
        R[ii[node]+p].clear();
      }
    }
    else{
      ci = ii[node];
      cj = jj[node];
      for(int d = 0 ;d < 4; d ++ ){
        ni = ci + dir[d][0];
        nj = cj + dir[d][1];
        if(idx.count(mp(ni, nj))){
          id = idx[mp(ni,nj)];
          if(dis[id] == -1 || dis[id] > dis[node]){
            dis[id] = dis[node];
            bf.push_front(id);
          }
        }
      }
      for(int p = -1; p <= +1; p ++ ){
        if(ci + p >= 1 && ci + p <= n){
          id = idx[mp(ci + p, -1)];
          if(dis[id] == -1 || dis[id] > dis[node] + 1){
            dis[id] = dis[node] + 1;
            bf.push_back(id);
          }
        }
        if(cj + p >= 1 && cj + p <= m){
          id = idx[mp(-1, cj + p)];
          if(dis[id] == -1 || dis[id] > dis[node] + 1){
            dis[id] = dis[node] + 1;
            bf.push_back(id);
          }
        }
      }
    }
  }
  int ans = (int)1e9;
  if(idx.count(mp(n,m))){
    if(dis[idx[mp(n,m)]] != -1) ans = min(ans, dis[idx[mp(n,m)]]);
  }
  if(dis[idx[mp(-1,m)]] != -1) ans = min(ans, dis[idx[mp(-1,m)]]);
  if(dis[idx[mp(n,-1)]] != -1) ans = min(ans, dis[idx[mp(n,-1)]]);
  if(ans == (int)1e9) cout << "-1\n";
  else cout << ans << "\n";
  return 0;
}