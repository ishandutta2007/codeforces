#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n;
vector<int> a, b;
vector<int> to, side;

void solve() {
	cin >> n;
	a.resize(n);
	b.resize(n);
	to.resize(2 * n);
	side.resize(2 * n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		--a[i], --b[i];
	}
	for (int i = 0; i < n; i++) {
		side[a[i]] = 0;
		side[b[i]] = 1;
		to[a[i]] = b[i];
		to[b[i]] = a[i];
	}
	for (int i = 0; i < n; i++) {
		if (to[i] < n) {
			cout << "-1\n";
			return;
		}
	}
	for (int i = n; i < 2 * n; i++) {
		if (to[i] >= n) {
			cout << "-1\n";
			return;
		}
	}


	// enough
	vector<int> resa(n), resb(n);
	int la = 0, ra = n - 1, lb = 0, rb = n - 1;

	vector<int> have(2 * n, 0);
	int ans = 0;
	int l = 0, r = 2 * n - 1;
	while (l < r) {
		int choice = 0, total = 0;
		int L = l, R = r;
		
		total = 1;
		R = to[l];
		choice += side[l];
		have[l] = have[to[l]] = 1;
		resa[la++] = l, resb[lb++] = to[l];
		while (l < L || R < r) {
			if (l < L) {
				if (!have[l]) {
					total++;
					R = min(R, to[l]);
					choice += side[l];
					have[l] = have[to[l]] = 1;
					resa[la++] = l, resb[lb++] = to[l];
				}
				l++;
			}
			else {
				if (!have[r]) {
					total++;
					L = max(L, to[r]);
					choice += side[r];
					have[r] = have[to[r]] = 1;
					resa[ra--] = r, resb[rb--] = to[r];
				}
				r--;
			}
		}
		ans += min(choice, total - choice);
		l++, r--;
	}
	for (int i = 0; i + 1 < n; i++) {
		if (resa[i] > resa[i + 1]) {
			cout << "-1\n";
			return;
		}
	}
	for (int i = 0; i + 1 < n; i++) {
		if (resb[i] < resb[i + 1]) {
			cout << "-1\n";
			return;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
//	cin >> tst;
	while (tst--) solve();
}