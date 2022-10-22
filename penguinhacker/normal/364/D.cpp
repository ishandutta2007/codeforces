#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mxN=1e6;
int n;
ll a[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	ll ans=1;
	for (int rep=0; rep<11; ++rep) {
		int ind=rng()%n;
		assert(0<=ind&&ind<n);
		ll x=a[ind];
		vector<ll> pf;
		for (ll i=2; i*i<=x; ++i) {
			if (x%i)
				continue;
			while(x%i==0)
				x/=i;
			pf.push_back(i);
		}
		if (x>1)
			pf.push_back(x);
		map<ll, int, greater<ll>> dp;
		for (int i=0; i<n; ++i)
			++dp[__gcd(a[ind], a[i])];
		for (ll p : pf)
			for (auto x : dp)
				if (x.first%p==0)
					dp[x.first/p]+=x.second;
		for (auto x : dp)
			if (x.second*2>=n)
				ans=max(ans, x.first);
	}
	cout << ans;
	return 0;
}