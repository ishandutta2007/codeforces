#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

const int N = 2e5 + 5;

int n;
vector<int> a;
int cnt[N] = {};

void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i, --i;
	for (int i = 0; i < n; i++)
		cnt[a[i]]++;
	int mx = *max_element(cnt, cnt + N);
	int f = -1;
	for (int i = 0; i < n; i++) {
		if (cnt[i] == mx) {
			if (f != -1) {
				cout << n << '\n';
				return;
			}
			f = i;
		}
	}
	int ans = 0;
	vector<int> fi(2 * n + 5);
	// aight
	for (int x = 0; x < 100; x++) {
		if (x == f) continue;
		for (auto &i : fi) i = -2;
		fi[0 + n] = -1;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == f) sum++;
			else if (a[i] == x) sum--;
			if (fi[sum + n] == -2)
				fi[sum + n] = i;
			else ans = max(ans, i - fi[sum + n]);
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}