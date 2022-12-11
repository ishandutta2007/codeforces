#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)2e5 + 10;
const int AL = 20;

int d[N];
int xx[N];
vector<int> T[N];
ll ans[N];

int subt[N];
bool use[N];

void dfs(int node, int par){
  xx[node]=d[node];
  subt[node]=1;
  for(auto x : T[node]){
    if(x == par || use[x]) continue;
    dfs(x,node);
    subt[node] += subt[x];
  }
}

vector<int> masks;

int X;
int cnt[1 << AL];
vector<int> cur;
vector<int> al;

ll dfs1(int node, int pr){
  cur.push_back(xx[node]);
  ll cc = 0;
  for(auto p : masks){
    cc += cnt[(p ^ xx[node] ^ X)];
  }
  for(auto x : T[node]){
    if(x == pr || use[x]) continue;
    xx[x] = (d[x] ^ xx[node]);
    cc += dfs1(x, node);
  }
  ans[node] += cc;
  return cc;
}

void decomp(int node){
  dfs(node, -1);
  int sz = subt[node];
  int pp = node;
  bool ok = true;
  while(ok){
    ok = false;
    for(auto x : T[node]){
      if(x == pp || use[x]) continue;
      if(subt[x] > sz/2){
        ok=true;
        pp=node;
        node=x;
        break;
      }
    }
  }
  use[node]=true;
  xx[node] = d[node];
  X = xx[node];
  cnt[X] = 1;
  al.push_back(X);
  for(auto x : T[node]){
    if(use[x]) continue;
    cur.clear();
    xx[x] = (xx[node] ^ d[x]);
    ans[node] += dfs1(x, node);
    for(auto y : cur){
      cnt[y] ++ ;
      al.push_back(y);
    }
  }
  
  reverse(T[node].begin(), T[node].end());
  for(auto p : al) cnt[p] = 0;
  al.clear();
  for(auto x : T[node]){
    if(use[x]) continue;
    cur.clear();
    xx[x] = (xx[node] ^ d[x]);
    dfs1(x, node);
    for(auto y : cur){
      cnt[y] ++ ;
      al.push_back(y);
    }
  }
  for(auto p : al) cnt[p] = 0;
  al.clear();
  cur.clear();
  for(auto x : T[node]){
    if(use[x]) continue;
    decomp(x);
  }
}

int main(){
  fastIO;
  int n;
  cin >> n;
  int u, v;
  for(int i = 1; i < n; i ++ ){
    cin >> u >> v;
    T[u].push_back(v);
    T[v].push_back(u);
  }
  char f;
  for(int i = 1; i <= n; i ++ ){
    cin >> f;
    d[i] = (1 << (f - 'a'));
    ans[i]=1;
  }
  masks.push_back(0);
  for(int i = 0 ; i < AL; i ++ )
    masks.push_back(1 << i);
  decomp(1);
  for(int i = 1; i <= n; i ++ ){
    cout << ans[i] << " ";
  }
  return 0;
}