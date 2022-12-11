#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
vector<int> st[N];

map<pii, vector<int>> con;

vector<int> T[N];
bool use[N];
int dep[N];
int subt[N];

void dfs(int u, int par){
  subt[u]=1;
  for(auto x : T[u]){
    if(x==par || use[x]) continue;
    dfs(x, u);
    subt[u] += subt[x];
  }
}

int fin(int node){
  dfs(node, -1);
  int cur = node;
  int pi = -1;
  bool ok = true;
  while(ok){
    ok=false;
    for(auto x : T[cur]){
      if(x == pi || use[x]) continue;
      if(2*subt[x] >= subt[node]){
        pi=cur;
        cur=x;
        ok=true;
        break;
      }
    }
  }
  return cur;
}

void dec(int node, int di){
  node = fin(node);
  use[node]=true;
  dep[node]=di;
  for(auto x : T[node]){
    if(!use[x])
      dec(x, di+1);
  }
}

int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  int a[m], b[m];
  pii dd[m];
  int low;
  for(int i = 0 ; i < m ; i ++ ){
    cin >> a[i] >> b[i];
    if(a[i] > b[i]) swap(a[i], b[i]);
    low = min(b[i]-a[i]-1,n-(b[i]-a[i]+1));
    dd[i] = mp(low, i);
  }
  sort(dd, dd + m);
  set<int> rem;
  for(int i = 1; i <= n; i ++ )
    rem.insert(i);
  int q = m + 1;
  int li, ri;
  for(int i = 0 ; i < m ; i ++ ){
    li = a[dd[i].se];
    ri = b[dd[i].se];
    if(ri - li - 1 <= n - (ri - li + 1)){
      st[i].push_back(li);
      st[i].push_back(ri);
      auto it = rem.upper_bound(li);
      while(*it < ri){
        st[i].push_back(*it);
        it = rem.erase(it);
      }
    }
    else{
      st[i].push_back(li);
      st[i].push_back(ri);
      auto it = rem.lower_bound(li);
      while(1){
        if(it == rem.begin()){
          it = rem.end();
          --it;
        }
        else{
          --it;
        }
        if(*it == ri) break;
        st[i].push_back(*it);
      }
      for(auto x : st[i])
        if(x!=li && x!=ri) rem.erase(x);
    }
  }
  for(auto x : rem) st[m].push_back(x);
  for(int i = 0 ;i <= m ; i ++ ){
    sort(st[i].begin(), st[i].end());
    reverse(st[i].begin(), st[i].end());
  }
  sort(st, st + q); 
  int k;
  int u, v;
  for(int i = 0 ; i < q; i ++ ){
    k = st[i].size();
    for(int j = 0 ; j < k; j ++ ){
      u = st[i][j];
      v = st[i][(j+1)%k];
      if(u > v) swap(u,v);
      con[mp(u,v)].push_back(i);
    }
  }
  for(auto x : con){
    if(x.se.size() == 2){
      u = x.se[0];
      v = x.se[1];
      T[u].push_back(v);
      T[v].push_back(u);
    }
  }
  dec(0,1);
  for(int i = 0 ; i < q; i ++ )
    cout << dep[i] << " ";
  return 0;
}