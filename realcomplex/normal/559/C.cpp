#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef double db;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll N = (ll)3e5 + 9;
const ll MOD = (ll)1e9 + 7;

ll f[N];
ll inv[N];

ll powr(ll n, ll k){
	if(k == 0)
		return 1ll;
	ll hf = powr(n, k/2);
	hf = (hf * 1ll * hf) % MOD;
	if(k & 1)
		hf = (hf * 1ll * n) % MOD;
	return hf;
}

ll calc(ll n, ll k){
	ll t = f[n];
	t = (t * 1ll * inv[k]) % MOD;
	t = (t * 1ll * inv[n - k]) % MOD;
	return t;
}

ll ff(ll i1, ll j1, ll i2, ll j2){
	ll a = i2 - i1;
	ll b = j2 - j1;
	return calc(a + b, a);
}

const ll MAXN = 2005;
ll dp[MAXN];


int main(){
	fastIO;
	f[0] = 1ll;
	inv[0] = 1;
	for(ll j = 1; j < N ; j ++ ){
		f[j] = (f[j - 1] * 1ll * j) % MOD;
		inv[j] = powr(f[j], MOD - 2);
	}
	ll h, w, n;
	cin >> h >> w >> n;
	pii bl[n + 1];
	for(ll i = 0 ; i < n; i ++ )
		cin >> bl[i].fi >> bl[i].se;
	bl[n] = mp(h, w);
	sort(bl, bl + n + 1);
	dp[0] = ff(1, 1, bl[0].fi, bl[0].se);
	for(ll i = 1; i <= n; i ++ ){
		dp[i] = ff(1, 1, bl[i].fi, bl[i].se);
		for(ll j = 0; j < i; j ++ ){
			if(bl[i].fi >= bl[j].fi && bl[i].se >= bl[j].se){
				dp[i] = (dp[i] - ((dp[j] * ff(bl[j].fi, bl[j].se, bl[i].fi, bl[i].se)) % MOD) + MOD) % MOD;
			}
		}
	}
	cout << dp[n];
	return 0;
}