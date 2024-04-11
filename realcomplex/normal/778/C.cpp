#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const ll N = (ll)3e5 + 9;
const ll AL = 27;
const ll MOD = 172701284053681ll;

ll f[N];


ll mult(ll a, ll b){ 
  return (a * 1ll * b) % MOD;
}

ll add(ll a, ll b){
  a += b;
  if(a < 0) a += MOD;
  a%=MOD;
  return a;
}

ll dep[N];
ll hsh[N];
vector<pii> T[N];
ll par[N];
ll subt[N];

void dfs(ll u){
  subt[u] = 1;
  for(auto x : T[u]){
    if(x.fi == par[u]) continue;
    par[x.fi] = u;
    dep[x.fi] = dep[u] + 1;
    hsh[x.fi] = add(hsh[u], mult(x.se, f[dep[x.fi]]));
    dfs(x.fi);
    subt[u] += subt[x.fi];
  }
}

set<ll> hashes[N];

ll dist[N];

void dfs1(ll u){
  ll mx = -1;
  ll chr = -1;
  set<ll> R;
  for(auto x : T[u]){
    if(x.fi == par[u]) continue;
    dfs1(x.fi);
    if(mx == -1 || subt[x.fi] > subt[mx])
      mx = x.fi, chr = x.se;
  }
  if(mx == -1){
    hashes[u].insert(hsh[u]);
    return;
  }
  vector<ll> ad, del, ar;
  ll nm;
  for(auto x : T[u]){
    if(x.fi == par[u] || x.fi == mx) continue;
    for(auto y : hashes[x.fi]){
      nm = add(y,add(mult(chr,f[dep[u] + 1]),-mult(x.se,f[dep[u]+1])));
      ar.push_back(nm);
      if(!hashes[mx].count(nm))
        del.push_back(nm);
      ad.push_back(y);
    }
    hashes[x.fi].clear();
  }
  swap(R, hashes[mx]);
  for(auto x : ar)
    R.insert(x);
  dist[u] = R.size() - R.count(add(mult(chr,f[dep[u]+1]), hsh[u]));
  swap(R, hashes[u]);
  R.clear();
  hashes[mx].clear();
  for(auto x : del)
    hashes[u].erase(x);
  for(auto x : ad)
    hashes[u].insert(x);
  hashes[u].insert(hsh[u]);
}

vector<ll> lis[N];

int main(){
  fastIO;
  f[0] = 1;
  for(ll i = 1 ; i < N ; i ++ )
    f[i] = mult(f[i - 1], AL);
  ll n;
  cin >> n;
  ll a, b;
  char ch;
  for(ll i = 1; i < n ; i ++ ){
    cin >> a >> b >> ch;
    T[a].push_back(mp(b,ch-'a'+1));
    T[b].push_back(mp(a,ch-'a'+1));
  }
  par[1] = -1;
  dfs(1);
  dfs1(1);
  for(ll i = 1; i <= n; i ++ )
    lis[dep[i]].push_back(i);
  ll res = n;
  ll id = -1;
  ll cur;
  for(ll i = 1; i <= n; i ++ ){
    if(lis[i].empty()) break;
    cur = n;
    for(auto x : lis[i - 1]){
      cur -= subt[x];
      cur += dist[x] + 1;
    }
    if(cur < res){
      res = cur;
      id = i;
    }
  }
  cout << res << "\n" << id << "\n";
  return 0;
}