#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ld inf = (ld)1e18;

bool Q;

struct Line{
  ll ai;
  ll bi;
  mutable ld ri;
  bool operator< (const Line &T) const {
    if(Q) return ai < T.ai;
    else return ri < T.ri;
  }
};

struct Hull : multiset<Line>{
  ld inter(iterator p1, iterator p2){
    return ((p1->bi)-(p2->bi))/((p2->ai)-(p1->ai));
  }
  bool hlf(iterator it){
    return (it != begin());
  }
  bool hnx(iterator it){
    it ++ ;
    return (it != end());
  }
  bool bad(iterator cur){
    if(!hlf(cur) || !hnx(cur)) return false;
    auto pi = cur;
    auto ni = cur;
    pi -- ;
    ni ++ ;
    return inter(pi, ni) <= inter(pi, cur);
  }
  void add(ll ki, ll b){
    Q = true;
    Line cur = {ki, b, inf};
    auto it = lower_bound(cur);
    if(it != end()){
      if(it->ai == cur.ai){
        if(it->bi >= cur.bi){
          return;
        }
        else{
          erase(it);
        }
      }
    }
    auto p = insert(cur);
    it = p;
    it ++ ;
    while(it != end() && bad(it)){
      it=erase(it);
    }
    while(p != begin()){
      it = p;
      it -- ;
      if(bad(it)) erase(it);
      else break;
    }
    if(bad(p)){
      erase(p);
      return;
    }
    if(hnx(p)){
      it = p;
      it ++ ;
      if(it == end()) 
        p->ri = inf;
      else
        p->ri = inter(p,it);
    }
    if(hlf(p)){
      it = p;
      it -- ;
      it->ri = inter(p, it);
    }
  }
  ll query(ld xi){
    Q = false;
    auto it = lower_bound({0,0,xi});
    return (it->ai) * xi + (it->bi);
  }
};

const int N = 150010;
vector<int> T[N];
ll a[N];
bool is[N];
int subt[N];

void dfs(int u, int par){
  subt[u]=1;
  for(auto x : T[u]){
    if(x == par || is[x]) continue;
    dfs(x, u);
    subt[u]+=subt[x];
  }
}


struct P{ 
  ll sa;
  ll bi;
  ll sum;
  ll dep;
};

ll ANS;

vector<vector<P>> cc;

void dfs1(int u, int par, ll dep, ll sa, ll bi, ll sum){
  sum += a[u];
  bi += dep * 1ll * a[u];
  sa += sum;
  ANS = max(ANS, sa);
  ANS = max(ANS, bi + sum);
  cc.back().push_back({sa, bi, sum, dep});
  for(auto x : T[u]){
    if(x == par || is[x]) continue;
    dfs1(x, u, dep + 1, sa, bi, sum);
  }
}

void decomp(int node){
  dfs(node,-1);
  int pv = -1;
  bool ok = true;
  int sz = subt[node];
  while(ok){
    ok = false;
    for(auto x : T[node]){
      if(x == pv || is[x]) continue;
      if(subt[x] > sz/2){
        pv=node;
        node = x;
        ok=true;
        break;
      }
    }
  }
  is[node]=true;
  cc.clear();
  for(auto x : T[node]){
    if(!is[x]){
      cc.push_back({});
      dfs1(x, node, 1, a[node], 0, a[node]);
    }
  }
  Hull cur;
  for(auto u : cc){
    for(auto v : u){
      if(!cur.empty())
        ANS = max(ANS, v.bi + cur.query(v.sum));
    }
    for(auto v : u){
      cur.add(v.dep + 1, v.sa - (v.dep + 1) * a[node]);
    }
  }
  cur.clear();
  reverse(cc.begin(), cc.end());
  for(auto u : cc){
    for(auto v : u){
      if(!cur.empty()){
        ANS = max(ANS, v.bi + cur.query(v.sum));
      }
    }
    for(auto v : u){
      cur.add(v.dep + 1, v.sa - (v.dep + 1) * a[node]);
    }
  }
  for(auto x : T[node]){
    if(!is[x]) decomp(x);
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
  for(int i = 1; i <= n; i ++ ){
    cin >> a[i];
    ANS = max(ANS, a[i]);
  }
  decomp(1);
  cout << ANS << "\n";
  return 0;
}