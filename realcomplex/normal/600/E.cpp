#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;
typedef pair<int,ll> pii;
typedef double db;

#define int ll

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

const int N = (int)1e5 + 91;

vector<int> T[N];

map<int, int> cnt[N];
map<int, ll> sum[N];

int col[N];
int ans[N];

void add(int node, int cl, int k){
  int x = cnt[node][cl];
  sum[node][x] -= cl;
  cnt[node][cl] += k;
  x = cnt[node][cl];
  sum[node][x] += cl;
}

void merge(int a, int b){
  if(cnt[a].size() < cnt[b].size()){
    swap(cnt[a], cnt[b]);
    swap(sum[a], sum[b]);
  }
  for(auto x : cnt[b]){
    add(a, x.fi, x.se);
  }
  cnt[b].clear();
  sum[b].clear();
}

void dfs(int u, int par){
  for(auto x : T[u]){
    if(x != par){
      dfs(x, u);
      merge(u, x);
    }
  }
  add(u, col[u], 1);
  auto it = sum[u].end();
  --it;
  ans[u] = it -> se;
}

signed main(){
  fastIO;
  int n;
  cin >> n;
  for(int i = 1;i <= n;i ++ )
    cin >> col[i];
  int u, v;
  for(int i = 1;i < n;i ++ ){
    cin >> u >> v;
    T[u].push_back(v);
    T[v].push_back(u);
  }
  dfs(1, -1);
  for(int i = 1;i <= n; i ++ ){
    cout << ans[i] << " ";
  }
  return 0;
}