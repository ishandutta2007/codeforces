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

const int N = (int)3e5 + 91;
int p[N];
int sz[N];
int nx[N];

void init(){
  for(int i = 0;i < N ;i ++ )
    p[i] = i, sz[i] = 1, nx[i] = i+1;
}

int fin(int u){
  if(u == p[u])
    return u;
  return p[u] = fin(p[u]);
}

void merge(int a, int b){
  a = fin(a);
  b = fin(b);
  if(a == b)
    return;
  if(sz[a] > sz[b])
    swap(a, b);
  sz[b] += sz[a];
  p[a] = b;
  nx[b] = max(nx[a], nx[b]);
}

int ret[N];

int main(){
  fastIO;
  init();
  int n, m;
  cin >> n >> m;
  int l, r, x;
  int p;
  int y;
  int z;
  for(int i = 0;i < m;i ++ ){
    cin >> l >> r >> x;
    p = l;
    while(p <= r){
      z = fin(p);
      if(ret[p] == 0)
        if(p != x) ret[p] = x; 
      y = nx[z];
      if(p + 1 < r and p != x and (p + 1) != x)
        merge(p, p + 1);
      if(p - 1 > l and p != x and (p - 1) != x)
        merge(p, p - 1);
      p = y;
    }
  }
  for(int i = 1; i <= n;i ++ )
    cout << ret[i] << " ";
  return 0;
}