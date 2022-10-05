#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n, k;
int a[100005];

bool always(int l, int r) {
	int mn[2] = { md, md };
	int mx[2] = { -md, -md };
	for (int i = l; i <= r; i++) {
		mn[a[i]] = min(mn[a[i]], i);
		mx[a[i]] = max(mx[a[i]], i);
	}
	if (mx[0] - mn[0] < k && mx[1] - mn[1] < k) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		a[i] = c - '0';
	}
	int mn[2] = { md, md };
	int mx[2] = { -md, -md };
	for (int i = 0; i < n; i++) {
		mn[a[i]] = min(mn[a[i]], i);
		mx[a[i]] = max(mx[a[i]], i);
	}
	if (mn[0] == md || mn[1] == md) {
		finish("tokitsukaze");
	}
	if (mx[0] - mn[0] < k || mx[1] - mn[1] < k) {
		finish("tokitsukaze");
	}
	if (!always(k, n - 1) || !always(0, k - 1)) {
		finish("once again");
	}
	if (mx[0] - mn[0] > k || mx[1] - mn[1] > k) {
		finish("once again");
	}
	finish("quailty");
}