#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = (int)1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

const int N = 1000;

int n, q;
vector<ll> a;

vector<int> divi;
vector<ll> sums[N];

bool isprime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

void solve() {
	cin >> n >> q;
	a.resize(n);
	for (auto &i : a) cin >> i;
	divi.clear();
	for (int i = 1; i < n; i++) {
		if (n % i == 0 && isprime(n / i)) divi.push_back(i);
	}
	int m = divi.size();
	multiset<ll> ans;
	for (int i = 0; i < m; i++) {
		int d = divi[i];
		sums[i].clear();
		sums[i].resize(d, 0);
		for (int j = 0; j < n; j++) {
			sums[i][j % d] += a[j];
		}
		for (int j = 0; j < d; j++)
			ans.insert(d * sums[i][j]);
	}
	cout << *ans.rbegin() << '\n';
	while (q--) {
		int p;
		ll x;
		cin >> p >> x;
		--p;
		ll prev = a[p];
		a[p] = x;

		for (int i = 0; i < m; i++) {
			ans.erase(ans.find(divi[i] * sums[i][p % divi[i]]));
			sums[i][p % divi[i]] += (x - prev);
			ans.insert(divi[i] * sums[i][p % divi[i]]);
		}
		cout << *ans.rbegin() << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}