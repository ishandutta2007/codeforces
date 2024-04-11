#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

const ll mod = int(1e9) + 7;

ll ipow(int b, int e) {
	ll ret = 1;
	while (e) {
		if (e&1) (ret*=b)%=mod;
		(b=b*1ll*b%mod); e>>=1;
	}
	return ret;
}

bool pow_safe(ll c, ll b, ll e) {
	if (!c) return 1;
	ll t = int(1e8) / c;
	for(;e--;) {
		t /= b;
		if (!t) return 0;
	}
	return 1;
}

int main()
{
	cppio();
	int tc; cin >> tc;
for(;tc--;) {
	int n, p; cin >> n >> p;
	vector<int> a(n); for(int& x:a) cin >> x;
	if (p == 1) { cout << n%2 << '\n'; continue; }
	sort(all(a));
	int ans = 0;
	int bc = 0; bool toolarge = 0;

	for(int i=n-1; 0<=i;) {
		int j;
		for(j=i-1; 0<=j && a[j]==a[i]; --j);
		int c = i-j;
		if (i == n-1) {
			bc = c%2;
			ans = bc ? ipow(p, a[i]) : 0;
			i = j;
			continue;
		}

		int df = a[i+1]-a[i];
		if (pow_safe(bc, p, df)) {
			bc = bc * ipow(p, df);
		} else {
			toolarge = 1;
		}

		if (bc<=c && !toolarge) {
			c -= bc;
			bc = c%2;
			ans = bc ? ipow(p, a[i]) : 0;
		} else {
			bc -= c;
			ans -= ipow(p, a[i]) * c % mod;
			if (ans<0) ans+=mod;
		}

		i = j;
	}

	cout << ans << '\n';
}
	return 0;
}