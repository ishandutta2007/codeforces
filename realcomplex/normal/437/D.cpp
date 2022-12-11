#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

typedef long double db;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

const int N = (int)1e5 + 9;

int pi[N];
int rnk[N];
int answer[N];

void init(){
  for(int i = 0;i < N; i ++ ){
    pi[i] = i;
    rnk[i] = 1ll;
    answer[i] = 0ll;
  }
}

int fin(int u){
  if(u == pi[u])
    return u;
  return pi[u] = fin(pi[u]);
}

void merge(int u, int v, int mlt){
  u = fin(u);
  v = fin(v);
  if(u == v)
    return;
  if(rnk[u] < rnk[v])
    swap(u, v);
  answer[u] += answer[v] + rnk[u] * rnk[v] * mlt;
  rnk[u] += rnk[v];
  pi[v] = u;
}

int ax[N];

signed main(){
  fastIO;
  init();
  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= n;i ++ ){
    cin >> ax[i];
  }
  int u[m], v[m];
  pii low[m];
  for(int i = 0;i < m;i ++ ){
    cin >> u[i] >> v[i];
    low[i].fi = min(ax[u[i]], ax[v[i]]);
    low[i].se = i;
  }
  sort(low, low + m);
  reverse(low, low + m);
  for(int i = 0;i < m;i ++ ){
    merge(u[low[i].se], v[low[i].se], low[i].fi);
  }
  cout << fixed << setprecision(6) << (db(answer[fin(1)]) * 2.0 / db(n * (n - 1)));
  return 0;
}