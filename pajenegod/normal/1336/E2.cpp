#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,popcnt,sse4.1,sse4.2,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<17, mod = 998244353 , lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll C=53,full = (1ll<<C)-1;
#define get(x, y) (((x)>>(y))&1)
ll shuffle(ll a, ll msk) {
	ll y = 1,  x = 1ll<<__builtin_popcountll(msk), r = 0;
	for(int i = 0; i < C; i++) {
		if(get(msk, i)) swap(x, y);
		r |= get(a, i)*x;
		x<<=1;
		if(get(msk, i)) swap(x, y);
	}
	return r;
}
ll n, m, basis[60], sz;
vi hv;
void add(ll x) {
	for(int i = C; i--;) {
		if(!((x>>i)&1)) continue;
		if(basis[i]) x ^= basis[i];
		else {
			basis[i] = x;break;
		}
	}
}
ll good = 0;
void post() {
	for(int i = 0; i < C; i++) {
		if(!basis[i]) {
			good|=1ll<<i;
			continue;
		}
		for(int j = i; j--;) {
			if(!basis[j]) continue;
			basis[i] = min(basis[i], basis[i]^basis[j]);
		}
		hv.pb(basis[i]);
	}
}
alignas(ll) ll ans[60];//aligned
int dp[54][1<<21];
void solve() {
	dp[0][0] = 1;
	int cur = 0;
	ll mx = (1ll<<sz)-1;
	for(int i = 0; i < C; i++) {
		if(!basis[i]) continue;
		ll x = shuffle(basis[i], good);
		x &= mx;
		for(int cnt = i+1; cnt--;) {
			for(int j = 0; j <= mx; j++) {
			    if(dp[cnt][j]) {
				dp[cnt+1][j^x] += dp[cnt][j];
				if(dp[cnt+1][j^x]>=mod) dp[cnt+1][j^x] -= mod;
			    }
			}
		}
	}
	for(int cnt = hv.size()+1; cnt--;) {
		for(int j = 0; j <= mx; j++) {
			int t = cnt + __builtin_popcount(j);
			ans[t] += dp[cnt][j];
			if(ans[t]>=mod) ans[t] -= mod;
		}
	}
}
alignas(ll) ll a[1<<16], b[1<<16];
void baka() {
	if(hv.size() < 6) {//for very small basis
	    for(int i = 0; i < 1<<hv.size(); i++) {
		    ll cur = 0;
	    	for(int j = 0; j < hv.size(); j++) {
     			if((i>>j)&1) {
	    			cur ^= hv[j];
		    	}
		    }
		    ans[__builtin_popcountll(cur)]++;
	    }
		return;
	}
	int x = min((int)hv.size(), 16);
	int y = max(0, (int)hv.size()-16);
	for(int i = 0; i < 1<<x; i++) {
		for(int j = 0; j < x; j++)
			if((i>>j)&1) a[i] ^= hv[j];
	}
	for(int i = 0; i < 1<<y; i++) {
		for(int j = 0; j < y; j++)
			if((i>>j)&1) b[i] ^= hv[16+j];
	}
	#define pcnt __builtin_popcountll
	#pragma GCC ivdep
	for(int i = (1<<hv.size())-1;i>0;i-=16) {
		++ans[pcnt(a[i&((1<<16)-1)]^b[i>>16])];
		++ans[pcnt(a[i&((1<<16)-1)^1]^b[i>>16])];
		++ans[pcnt(a[i&((1<<16)-1)^2]^b[i>>16])];
		++ans[pcnt(a[i&((1<<16)-1)^3]^b[i>>16])];
		++ans[pcnt(a[i&((1<<16)-1)^4]^b[i>>16])];
		++ans[pcnt(a[i&((1<<16)-1)^5]^b[i>>16])];
		++ans[pcnt(a[i&((1<<16)-1)^6]^b[i>>16])];
		++ans[pcnt(a[i&((1<<16)-1)^7]^b[i>>16])];
		++ans[pcnt(a[i&((1<<16)-1)^8]^b[i>>16])];
		++ans[pcnt(a[i&((1<<16)-1)^9]^b[i>>16])];
		++ans[pcnt(a[i&((1<<16)-1)^10]^b[i>>16])];
		++ans[pcnt(a[i&((1<<16)-1)^11]^b[i>>16])];
		++ans[pcnt(a[i&((1<<16)-1)^12]^b[i>>16])];
		++ans[pcnt(a[i&((1<<16)-1)^13]^b[i>>16])];
		++ans[pcnt(a[i&((1<<16)-1)^14]^b[i>>16])];
		++ans[pcnt(a[i&((1<<16)-1)^15]^b[i>>16])];
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(ll t, i = 1; i <= n; i++) {
		cin >> t;
		add(t);
	}
	post();
	sz = __builtin_popcountll(good);
	if(sz<22) {
		solve();
	} else {
		baka();
	}
	ll q = 1;
	for(int i = hv.size(); i < n; i++) q = q*2ll%mod;
	for(int i = 0; i <= m; i++) cout << ans[i]*q%mod << " ";
	return 0;
}