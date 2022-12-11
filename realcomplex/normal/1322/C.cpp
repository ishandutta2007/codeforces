#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)5e5 + 10;

ll ri[N];
ll xr[N];

void solve(){
  int n, m;
  cin >> n >> m;
  vector<ll> c(n);
  for(int i = 0 ; i < n; i ++ ){
    cin >> c[i];
    ri[i] = ((rng() % (ll)1e18) + (ll)1e18) % (ll)1e18;
    xr[i] = 0;
  }
  int u, v;
  map<ll, ll> pp;
  for(int i = 0 ; i < m; i ++ ){
    cin >> u >> v;
    u--;
    v--;
    xr[v] ^= ri[u];
  }
  for(int i = 0 ; i < n; i ++ )
    if(xr[i] != 0)pp[xr[i]] += c[i] ;
  ll gc = 0;
  for(auto p : pp)
    gc = __gcd(p.se, gc);
  cout << gc << "\n";
}

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0; t < tc; t ++ )
    solve();
  return 0;
}