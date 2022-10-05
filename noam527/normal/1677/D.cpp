#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

void operation(vector<int> &b) {
	int n = b.size();
	for (int i = 0; i < n - 1; i++)
		if (b[i] > b[i + 1])
			swap(b[i], b[i + 1]);
}
void vof(vector<int> &b) {
	for (int i = 0; i < b.size(); i++) {
		int x = 0;
		for (int j = 0; j < i; j++)
			if (b[j] > b[i])
				x++;
		cout << x << " ";
	}
	cout << '\n';
}

int n, k;
vector<int> a;

void solve() {
	cin >> n >> k;
	a.resize(n);
	for (auto &i : a) cin >> i;
	for (int i = 0; i < k; i++) {
		if (a.back() > 0) {
			cout << "0\n";
			return;
		}
		a.pop_back();
	}
	ll ans = 1;
	for (int i = 2; i <= k; i++)
		ans = ans * i % md;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == 0) {
			ans = ans * (k + 1) % md;
		}
		if (a[i] == -1) {
			ans = ans * (k + 1 + i) % md;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}