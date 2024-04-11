#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

ll n, m, k, x;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> k;
	x = 2 * n * m;
	if (x % k != 0) finish("NO");

	ll d1, d2, X, Y;
	for (int i = 1; i * i <= k; i++)
		if (k % i == 0) {
			int cnt = 0;
			d1 = i;
			d2 = k / i;
			if (n % d1 == 0) X = n / d1;
			else if (2 * n % d1 == 0) X = 2 * n / d1, cnt++;
			else cnt = inf;

			if (m % d2 == 0) Y = m / d2;
			else if (2 * m % d2 == 0) Y = 2 * m / d2, cnt++;
			else cnt = inf;

			if (cnt == 0) {
				if (2 * X <= n) X *= 2, cnt = 1;
				else if (2 * Y <= m) Y *= 2, cnt = 1;
				if (cnt != 1) cnt = inf;
			}
			if (cnt < inf) {
				cout << "YES" << endl;
				cout << "0 0" << endl;
				cout << X << " 0" << endl;
				cout << "0 " << Y << endl;
				return 0;
			}
			
			cnt = 0;
			d1 = k / i;
			d2 = i;
			if (n % d1 == 0) X = n / d1;
			else if (2 * n % d1 == 0) X = 2 * n / d1, cnt++;
			else cnt = inf;

			if (m % d2 == 0) Y = m / d2;
			else if (2 * m % d2 == 0) Y = 2 * m / d2, cnt++;
			else cnt = inf;

			if (cnt == 0) {
				if (2 * X <= n) X *= 2, cnt = 1;
				else if (2 * Y <= m) Y *= 2, cnt = 1;
				if (cnt != 1) cnt = inf;
			}
			if (cnt < inf) {
				cout << "YES" << endl;
				cout << "0 0" << endl;
				cout << X << " 0" << endl;
				cout << "0 " << Y << endl;
				return 0;
			}
			
		}
	finish("NO");
}