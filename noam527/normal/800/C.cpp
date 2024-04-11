#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

int gcd(int x, int y, int &a, int &b) {
	if (y == 0) {
		a = 1;
		b = 0;
		return x;
	}
	int t = x / y;
	int g = gcd(y, x % y, a, b);
	int tmp = a - b * t;
	a = b;
	b = tmp;
	return g;
}

int gcd(int x, int y) {
	int a, b;
	return gcd(x, y, a, b);
}

int inv(int x, int mod) {
	int a, b;
	gcd(x, mod, a, b);
	return (a + mod) % mod;
}

int findprod(int from, int to, int mod) {
	int g = gcd(from, mod);
	from /= g, to /= g, mod /= g;
	return (ll)to * inv(from, mod) % mod;
}

int n, m;
int dp[200005] = {};
int to[200005] = {};
set<int> can[200005];
vector<int> pr;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	if (m == 1) {
		cout << "1\n0\n";
		return 0;
	}
	for (int i = 0; i < m; i++) {
		dp[gcd(i, m)]++;
		can[gcd(i, m)].insert(i);
	}
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		dp[gcd(x, m)]--;
		can[gcd(x, m)].erase(x);
	}
	int mm = m;
	for (int i = 2; mm > 1; i++) {
		if (mm % i == 0) {
			pr.push_back(i);
			while (mm % i == 0) mm /= i;
		}
	}

	if (OO) {
		cout << "pr: ";
		for (const auto &i : pr) cout << i << " "; cout << endl;
		for (int i = 1; i <= m; i++) {
			if (m % i == 0) {
				cout << i << ":\n";
				for (const auto &x : can[i]) cout << x << " "; cout << endl;
			}
		}
	}
	to[m] = -1;
	for (int i = m - 1; i >= 1; i--) {
		if (m % i == 0) {
			to[i] = -1;
			for (const auto &p : pr) {
				if ((ll)i * p <= m && m % (i * p) == 0) {
					if (dp[i] < can[i].size() + dp[i * p]) {
						to[i] = i * p;
						dp[i] = can[i].size() + dp[i * p];
					}
				}
			}
		}
	}
	vector<int> arr;
	int g = 1;
	while (g != -1) {
		for (const auto &i : can[g]) arr.push_back(i);
		g = to[g];
	}
	cout << arr.size() << endl;
	if (OO) {
		for (const auto &i : arr) cout << i << " "; cout << endl;
	}
	if (arr.size() >= 1) {
		cout << arr[0] << " ";
		for (int i = 1; i < arr.size(); i++)
			cout << findprod(arr[i - 1], arr[i], m) << " ";
		cout << endl;
	}
}