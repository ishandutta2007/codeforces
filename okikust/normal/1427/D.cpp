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
	int n;
	int p[100];
	vi a;
	vi na;
	vi b;
	vi ans;
	vector<vi> ansb;
	int sz, x;
	int cx, cy, cz;
	bool v;
	cin >> n;
	rep(i, n) {
		cin >> x;
		a.eb(x);
	}
	while (true) {
		v = false;
		rep(i, n) {
			p[a[i] - 1] = i;
		}
		rep(i, n - 1) {
			if (p[i] > p[i + 1]) {
				cx = p[i + 1];
				cy = p[i + 1] + 1;
				while (a[cy] == i + 2 - p[i + 1] + cy)cy++;
				cz = p[i] + 1;
				b.clear();
				if (cx > 0)b.eb(cx);
				if ((cy - cx) > 0)b.eb(cy - cx);
				if ((cz - cy) > 0)b.eb(cz - cy);
				if ((n - cz) > 0)b.eb(n - cz);
				sz = b.size();
				ans.eb(sz);
				ansb.push_back(b);
				na.clear();
				rep2(j, cz, n - 1)na.eb(a[j]);
				rep2(j, cy, cz - 1)na.eb(a[j]);
				rep2(j, cx, cy - 1)na.eb(a[j]);
				rep2(j, 0, cx - 1)na.eb(a[j]);
				a = na;
				v = true;
				break;
			}
		}
		if (!v)break;
	}
	n = ans.size();
	cout << n << endl;
	rep(i, n) {
		cout << ans[i];
		rep(j, ans[i])cout << " " << ansb[i][j];
		cout << endl;
	}

	return 0;
}