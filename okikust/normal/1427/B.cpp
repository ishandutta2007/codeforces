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
	int n, m, k, kk, t;
	int x, y, yy, z;
	int s, ans;
	bool v;
	char a[N];
	vi b;
	rep(i, N)a[i] = 0;
	cin >> t;
	rep(tt, t) {
		cin >> n >> k;
		kk = k;
		cin >> a;
		x = 0;
		y = 0;
		z = 0;
		v = false;
		b.clear();
		rep(i, n) {
			if (a[i] == 'W') {
				x++;
				v = true;
			}
			if (v) {
				if (a[i] == 'L')z++;
				else if (z > 0) {
					b.eb(z);
					z = 0;
				}
			}
		}
		rep(i, n - 1) {
			if ((a[i] == 'L') && (a[i + 1] == 'W'))y++;
		}
		if (a[0] == 'W')y++;
		if ((x + k) >= n) {
			cout << (2 * n) - 1 << endl;
			rep(i, n + 1)a[i] = 0;
			continue;
		}
		if (x == 0) {
			cout << max((2 * k) - 1, 0) << endl;
			rep(i, n + 1)a[i] = 0;
			continue;
		}
		sort(all(b));
		yy = y;
		rep(i, yy - 1) {
			if (b[i] <= k) {
				k -= b[i];
				y--;
			}
			else break;
		}
		cout << (2 * (x + kk)) - y << endl;
		rep(i, n + 1)a[i] = 0;
	}

	return 0;
}