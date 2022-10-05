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

int gcd(int x, int y) {
	if (!y) return x;
	return gcd(y, x % y);
}

const int M = 15000001;
int n;
int m[M + 1] = {};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	int g = 0;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		if (i == 0) g = x;
		else g = gcd(g, x);
		m[x]++;
	}
	int mx = 0, tmp;
	for (ll i = 2; g * i <= M; i++) {
		if (i == 2 || i == 3 || (i % 2 != 0 && i % 3 != 0)) {
			tmp = 0;
			for (int j = g * i; j <= M; j += g * i)
				tmp += m[j];
			mx = max(mx, tmp);
		}
	}
	if (mx == 0) finish(-1);
	finish(n - mx);
}