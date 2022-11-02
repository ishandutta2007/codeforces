#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define ll long long
#define eb emplace_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define N 210000
#define MOD 998244353 //1000000007
#define pll pair<ll,ll>


int main() {
	int r, n, z, m, mm, d;
	int a[N];
	int t[N];
	int x[N];
	int y[N];
	int ans = 0;
	cin >> r >> n;
	a[0] = 0;
	t[0] = 0;
	x[0] = 1;
	y[0] = 1;
	z = 0;
	mm = -1;
	rep(i, n) {
		cin >> t[i + 1] >> x[i + 1] >> y[i + 1];
		while ((t[i + 1] - t[z]) > (2 * r)) {
			mm = max(mm, a[z]);
			z++;
		}
		m = mm;
		rep2(j, z, i) {
			d = (t[i + 1] - t[j]) - abs(x[i + 1] - x[j]) - abs(y[i + 1] - y[j]);
			if (d >= 0)m = max(m, a[j]);
		}
		if (m < 0)a[i + 1] = -1;
		else a[i + 1] = m + 1;
		ans = max(ans, a[i + 1]);
	}
	cout << ans << endl;
	return 0;
}