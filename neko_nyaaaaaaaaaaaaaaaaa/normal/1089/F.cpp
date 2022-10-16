#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("input.txt", "r", stdin);
#define output_file freopen("output.txt", "w", stdout);
using namespace std;

#define int __int128
int gcdExtended(int a, int b, int &x, int &y) {
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}

	int x1, y1;
	int gcd = gcdExtended(b%a, a, x1, y1);

	x = y1 - (b/a) * x1;
	y = x1;

	return gcd;
}

void solve()
{
	long long n; cin >> n;
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) {
			int a = i, b = n/i;
			int A = n*b, B = n*a, C = n*a*b - a*b;
			int g = __gcd(A, B);
			if (C % g) continue;

			int x = 0, y = 0, d = C/g;
			gcdExtended(A, B, x, y);
			x *= d; y *= d;

			cerr << (long long)x << ' ' << (long long)a << '\n' << (long long)y << ' ' << (long long)b << '\n';

			if (x <= 0) {
				int k = -x/(B/g);
				x += (B/g)*k; y -= (A/g)*k;
				while (x <= 0) x += B/g, y -= A/g;
			}
			cerr << (long long)x << ' ' << (long long)a << '\n' << (long long)y << ' ' << (long long)b << '\n';
			if (y <= 0) {
				int k = -y/(A/g);
				x -= (B/g)*k; y += (A/g)*k;
				while (y <= 0) x -= B/g, y += A/g;
			}
			cerr << (long long)x << ' ' << (long long)a << '\n' << (long long)y << ' ' << (long long)b << '\n';

			cout << "YES\n2\n";
			cout << (long long)x << ' ' << (long long)a << '\n' << (long long)y << ' ' << (long long)b << '\n';
			return;
		}
	}
	cout << "NO\n";
}
signed main()
{
	//ios_base::sync_with_stdio(false), cin.tie(NULL);
	int testcase = 1;
	//cin >> testcase;
	while (testcase--)
	{
		solve();
	}
	
}