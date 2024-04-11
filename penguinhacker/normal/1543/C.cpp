#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

long double v;

void rd(long double& x) {
	if (x<1e-11)
		x=0;
}

long double dfs(long double c, long double m, long double dp, int d) {
	rd(c), rd(m), rd(dp);
	if (dp==0)
		return 0;
	long double res=(1-c-m)*(d+1)*dp;
	for (int k=0; k<2; ++k) {
		long double s=min(c, v);
		if (m>0)
			res+=dfs(c-s, m+0.5*s, dp*c, d+1);
		else
			res+=dfs(c-s, 0, dp*c, d+1);
		swap(c, m);
	}
	return res;
}

void solve() {
	long double c, m, p;
	cin >> c >> m >> p >> v;
	cout << dfs(c, m, 1, 0) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}