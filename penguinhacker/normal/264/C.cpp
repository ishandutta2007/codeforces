#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
const ll INF=1ll<<60;

template<class T> ostream& operator<< (ostream& out, ar<T, 2> &x) {
	return out << "[" << x[0] << ", " << x[1] << "]";
}

int n, c[100000], v[100000];
ll a, b, dp[100000];

void solve() {
	fill(dp, dp+n, -INF);
	ar<ll, 2> best1={0, -1}, best2={0, -2};
	cin >> a >> b;
	for (int i=0; i<n; ++i) {
		ll cur;
		if (c[i]!=best1[1]) {
			cur=best1[0]+v[i]*b;
		}
		else {
			cur=best2[0]+v[i]*b;
		}
		cur=max(cur, dp[c[i]]+a*v[i]);
		dp[c[i]]=max(dp[c[i]], cur);
		if (dp[c[i]]>best1[0]&&c[i]!=best1[1]) {
			best2=best1;
			best1={dp[c[i]], c[i]};
		}
		else if (c[i]==best1[1]) {
			best1[0]=dp[c[i]];
		}
		else if (dp[c[i]]>best2[0]) {
			best2={dp[c[i]], c[i]};
		}
		assert(best1[0]>=best2[0]);
	}
	cout << best1[0] << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> n >> q;
	for (int i=0; i<n; ++i)
		cin >> v[i];
	for (int i=0; i<n; ++i)
		cin >> c[i], --c[i];
	while(q--) {
		solve();
	}
	return 0;
}