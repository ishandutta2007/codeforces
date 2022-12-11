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

const int N = (int)1e5 + 9;
vector<pii> T[N];

int p[N];
int sz[N];

void init(){
  for(int i = 0;i < N; i ++ ){
    p[i] = i;
    sz[i] = 1;
  }
}

int fin(int u){
  if(p[u] == u)
    return u;
  return p[u] = fin(p[u]);
}

bool unite(int a, int b){
  a = fin(a);
  b = fin(b);
  if(a == b)
    return false;
  if(sz[a] > sz[b])
    swap(a, b);
  sz[b] += sz[a];
  p[a] = b;
  return true;
}

bool check(int a, int b){
  return fin(a) == fin(b);
}

map<string, int> word;

int xor_sum[N];
bool vis[N];

void dfs(int u){
  if(vis[u]) return;
  vis[u] = true;
  for(auto x : T[u]){
    if(!vis[x.fi]){
      xor_sum[x.fi] = xor_sum[u] ^ x.se;
      dfs(x.fi);
    }
  }
}

int main(){
  fastIO;
  init();
  int n, m, q;
  cin >> n >> m >> q;
  string k;
  for(int i = 0;i < n;i ++ ){
    cin >> k;
    word[k] = i + 1;
  }
  int t[m];
  string x, y;
  int a[m], b[m];
  int ans[m];
  for(int i = 0;i < m; i ++ ){
    ans[i] = -1;
    /* -1 - no answer 
     *  1 - yes
     *  0 - no
     */
  }
  for(int i = 0;i < m; i ++ ){
    cin >> t[i] >> x >> y;
    a[i] = word[x];
    b[i] = word[y];
    if(t[i] == 1)
      t[i] = 0;
    else
      t[i] = 1;
    if(unite(a[i], b[i])){
      ans[i] = 1;
      T[a[i]].push_back(mp(b[i], t[i]));
      T[b[i]].push_back(mp(a[i], t[i]));
    }
  } 
  for(int i = 1;i <= n;i ++ ) dfs(i);
  for(int i = 0;i < m;i ++ ){
    if(ans[i] == -1){
      if(xor_sum[a[i]] ^ xor_sum[b[i]] == t[i]){
        ans[i] = 1;
      }
      else{
        ans[i] = 0;
      }
    }
    cout << (ans[i]?"YES":"NO") << "\n";
  }

  for(int i = 0; i < q;i ++ ){
    cin >> x >> y;
    if(!check(word[x], word[y])){
      cout << "3\n";
    }
    else{
      cout << (xor_sum[word[x]] ^ xor_sum[word[y]] == 0?1:2) << "\n";
    }
  }
  return 0;
}