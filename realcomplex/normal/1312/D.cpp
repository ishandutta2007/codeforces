#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
const ll MOD = 998244353;

ll pow(ll x, ll k){
  if(k == 0)
    return 1ll;
  ll p = pow(x,k/2);
  p = (p * 1ll * p) % MOD;
  if(k % 2)
    p = (p * 1ll * x) % MOD;
  return p;
}

ll fac[N];

ll compute(ll n, ll k){
  ll x = fac[n];
  x = (x * 1ll * pow(fac[k],MOD-2)) % MOD;
  x = (x * 1ll * pow(fac[n - k], MOD-2)) % MOD;
  return x;
}

int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  fac[0] = 1ll;
  for(int i = 1; i < N ; i ++ ){
    fac[i] = (fac[i - 1] * 1ll * i) % MOD;
  }
  ll ans = 0;
  ll cur;
  for(int k = n - 1; k <= m ; k ++ ){
    cur = compute(k-1,n-2);
    cur = (cur * pow(2ll,(ll)n-2)) % MOD;
    cur = (cur * 1ll * (n - 2)) % MOD;
    ans = (ans + cur) % MOD;
  }
  ans = (ans * pow(2ll,MOD-2)) % MOD; // wtf??
  cout << ans;
  return 0;
}