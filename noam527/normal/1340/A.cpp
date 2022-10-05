#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n;
vector<int> a, pos;

void solve() {
	cin >> n;
	a.resize(n);
	pos.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		--a[i];
		pos[a[i]] = i;
	}
	int nxt = n - 1;
	int at = 0;
	while (at < n) {
		int cnt = 0;
		for (int i = at; i <= at + nxt - pos[at]; i++) {
			cnt++;
			if (pos[i] != pos[at] + i - at) {
				cout << "No\n";
				return;
			}
		}
		at += cnt, nxt -= cnt;
	}
	cout << "Yes\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}