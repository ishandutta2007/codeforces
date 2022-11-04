#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <memory.h>
#include <iomanip>
#include <set>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;

#define rep(i, s, t) for (auto i = (s); i < (t); ++(i))
#define per(i, s, t) for (auto i = (s); i >= (t); --(i))
#define sz(x) ((int) x.size())
#define all(x) (x).begin(), (x).end()

void run();

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	run();
#ifdef _DEBUG
	cerr << "OK" << endl;
	while (1);
#endif
	return 0;
}

const int N = (int) 2e5 + 123;

int n;
ll s[N], g[N];
ll l[N], r[N];
ll ans[N];

void run() {
	cin >> n;
	ll was = 0;
	rep(i, 1, n + 1) {
		cin >> s[i] >> g[i];
		was += s[i];
	}
	l[0] = -LINF;
	r[0] = LINF;
	rep(i, 1, n + 1) {
		l[i] = max(l[i - 1] - 1, s[i]);
		r[i] = min(r[i - 1] + 1, s[i] + g[i]);
		if (l[i] > r[i]) {
			cout << "-1\n";
			return;
		}
	}
	ll res = 0;
	ans[n] = r[n];
	res += ans[n];
	per(i, n - 1, 1) {
		ans[i] = min(r[i], ans[i + 1] + 1);
		res += ans[i];
	}
	cout << res - was << "\n";
	rep(i, 1, n + 1) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}