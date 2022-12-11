#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

const int N = (int)3e5 + 912;

vector<int> T[N];
int nex[N];
int rnk[N];
int diameter[N];


void init(){
  for(int i = 0;i < N; i ++ ){
    nex[i] = i;
    rnk[i] = 1;
  }
}

int fin(int u){
  if(u == nex[u])
    return u;
  return nex[u] = fin(nex[u]);
}

void merge1(int a, int b){
  a = fin(a);
  b = fin(b);
  if(a == b)
    return;
  if(rnk[a] > rnk[b])
    swap(a, b);
  rnk[b] += rnk[a];
  nex[a] = b;
}

void merge2(int a, int b){
  a = fin(a);
  b = fin(b);
  if(a == b)
    return;
  if(rnk[a] > rnk[b]) 
    swap(a, b);
  rnk[b] += rnk[a];
  nex[a] = b;
  diameter[b] = max({diameter[a], diameter[b], (diameter[a] + 1)/2 + (diameter[b] + 1)/2 + 1});
}

int mxd;
int idx;
bool check[N];

void dfs(int u, int par, int depth){
  if(depth > mxd)
    mxd = depth, idx = u;
  check[u] = true;
  for(auto x : T[u])
    if(x != par)
      dfs(x, u, depth + 1);
}

int finDiameter(int u){
  mxd = idx = -1;
  dfs(u, -1, 0);
  u = idx;
  mxd = idx = -1;
  dfs(u, -1, 0);
  return mxd;
}

int main(){
  fastIO;
  init();
  int n, m, q;
  cin >> n >> m >> q;
  int ai, bi;
  for(int i = 0;i < m;i ++ ){
    cin >> ai >> bi;
    T[ai].push_back(bi);
    T[bi].push_back(ai);
    merge1(ai, bi);
  }
  int ac;
  for(int i = 1;i <= n;i ++ ){
    if(!check[i]){
      ac = fin(i);
      diameter[ac] = finDiameter(ac);
    }
  }
  int t, xi, yi;
  for(int i = 0;i < q;i ++ ){
    cin >> t;
    if(t == 1){
      cin >> xi;
      xi = fin(xi);
      cout << diameter[xi] << "\n";
    }
    else{
      cin >> xi >> yi;
      merge2(xi, yi);
    }
  }
  return 0;
}