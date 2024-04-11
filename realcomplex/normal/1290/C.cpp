#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 9;

int c[N];
int par[N];
int sz[N];
set<int> f[2][N];
bool ok[2][N];
vector<int> T[N];

int res = 0;

int fin(int x){
  if(x==par[x])
    return x;
  return par[x]=fin(par[x]);
}

void unite(int a, int b, int eq){ 
  int u = fin(a);
  int v = fin(b);
  if(u==v) return;
  if(sz[u] > sz[v]){
    swap(a,b);
    swap(u,v);
  }
  int low = (int)1e9;
  for(int i = 0 ; i < 2; i ++ )
    if(ok[i][u])low = min(low, (int)f[i][u].size());
  res -= low;
  low=(int)1e9;
  for(int i = 0 ; i < 2; i ++ )
    if(ok[i][v])low = min(low, (int)f[i][v].size());
  res -= low;
  int l[2], r[2];
  l[0]=l[1]=-1;
  r[0]=r[1]=-1;
  for(int i = 0; i < 2; i ++ ){
    if(ok[i][u]){
      l[i]=f[i][u].count(a);
    }
    if(ok[i][v]){
      r[i]=f[i][v].count(b);
    }
  }
  for(int i = 0 ; i < 2; i ++ ){
    if(r[i]==-1) continue;
    ok[i][v]=false;
    for(int j = 0 ; j < 2; j ++ ){
      if(l[j]==-1) continue;
      if((r[i] ^ l[j]) == eq){
        ok[i][v]=true;
        for(auto x : f[j][u])
          f[i][v].insert(x);
        f[j][u].clear();
      }
    }
  }
  for(int i = 0 ; i < 2; i ++ )
    f[i][u].clear();
  low = (int)1e9;
  for(int i = 0 ; i < 2; i ++ )
    if(ok[i][v])low = min(low, (int)f[i][v].size());
  res += low;
  sz[v] += sz[u];
  par[u] = v;
}

void setv(int a, int x){
  int u = fin(a);
  int low = (int)1e9;
  for(int i = 0 ; i < 2; i ++ )
    if(ok[i][u])low = min(low, (int)f[i][u].size());
  res -= low;
  for(int i = 0 ; i < 2; i ++ ){
    if(ok[i][u] && f[i][u].count(a) != x){
      f[i][u].clear();
      ok[i][u]=false;
    }
  }
  low = (int)1e9;
  for(int i = 0 ; i < 2; i ++ )
    if(ok[i][u])low = min(low, (int)f[i][u].size());
  res += low;
}

int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  char q;
  for(int i = 1; i <= n; i ++ ){
    cin >> q;
    c[i] = q - '0';
  }
  int k;
  int x;
  for(int i = 1; i <= m ; i ++ ){
    cin >> k;
    for(int j = 0 ; j < k ; j ++ ){
      cin >> x;
      T[x].push_back(i);
    }
    sz[i]=1;
    par[i]=i;
  }
  for(int i = 1; i <= m; i ++ ){
    f[1][i].insert(i);
    ok[0][i]=ok[1][i]=true;
  }
  for(int i = 1; i <= n; i ++ ){
    if(T[i].size() == 1)
      setv(T[i][0], 1-c[i]);
    else if(T[i].size() == 2){
      unite(T[i][0],T[i][1],1-c[i]);
    }
    cout << res << "\n";
  }
  return 0;
}