#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <intrin.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve() {
	int n;
	ll u, v;
	cin >> n >> u >> v;
	vector<int> a(n);
	foru(i, 0, n)cin >> a[i];
	bool hard = 1;
	bool brick = 1;
	foru(i, 1, n) {
		if (abs(a[i - 1] - a[i]) > 1)hard = 0;
		if (a[i - 1] != a[i])brick = 0;
	}
	if (!hard) {
		cout << 0 << '\n';
		return;
	}
	if (brick) {
		cout << v + min(u, v) << '\n';
		return;
	}
	else {
		cout << min(u, v) << '\n';
		return;
	}
}


int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}