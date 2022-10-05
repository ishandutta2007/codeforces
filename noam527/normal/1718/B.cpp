#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = (int)1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

int k;

void solve() {
	cin >> k;
	vector<int> s;
	ll sum = 0;
	for (int i = 0; i < k; i++) {
		int c;
		cin >> c;
		s.push_back(c);
		sum += c;
	}
	if (sum == 1) {
		cout << "YES\n";
		return;
	}
	vector<ll> fib = { 1, 1 };
	ll fsum = 2;
	while (fsum < sum) {
		fib.push_back(fib[fib.size() - 2] + fib.back());
		fsum += fib.back();
	}
	if (fsum > sum) {
		cout << "NO\n";
		return;
	}
	int lasti = -1;
	for (int i = fib.size() - 1; i >= 0; i--) {
		ll x = fib[i];
		int at = -1;
		ll have = -1;
		for (int j = 0; j < k; j++) {
			if (have < s[j] && j != lasti) {
				have = s[j];
				at = j;
			}
		}
		lasti = at;
		if (x > have) {
			cout << "NO\n";
			return;
		}
		s[at] -= x;
	}
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}