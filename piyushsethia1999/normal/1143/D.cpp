#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int n, k;

int mi = 1000000000000ll;
int ma = 0;

void solve(int a, int b) {
	int to = n * k;
	for (int i = 0; i < to; i += k) {
		int y = (i - b + to - a + to) % to;

		if (y == 0) {
			y = 1;
		} else {
			y = (to) / __gcd(to, y);
		}
		ma = max(ma, y);
		mi = min(mi, y);
		y = (i + b - a + to) % to;

		if (y == 0) {
			y = 1;
		} else {
			y = (to) / __gcd(to, y);
		}
		ma = max(ma, y);
		mi = min(mi, y);

	}
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	cin >> n;
	cin >> k;
	int a; cin >> a;
	int b; cin >> b;
	int fi = a;
	solve(fi, b);
	fi = n * k - a;
	solve(fi, b);
	cout << mi << " " << ma;
}