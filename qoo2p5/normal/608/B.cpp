#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-10
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

int n, k;
int a[2000000];
int b[2000000];
int prefix[2000000];

int get_sum(int l, int r) {
	int res = prefix[r];
	if (l > 0) {
		res -= prefix[l - 1];
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;
	n = sz(s);
	for (int i = 0; i < sz(s); i++) {
		if (s[i] == '1') {
			a[i] = 1;
		} else {
			a[i] = 0;
		}
	}
	cin >> s;
	k = sz(s);
	for (int i = 0; i < sz(s); i++) {
		if (s[i] == '1') {
			b[i] = 1;
		} else {
			b[i] = 0;
		}
	}

	prefix[0] = b[0];
	for (int i = 1; i < k; i++) {
		prefix[i] = prefix[i - 1] + b[i];
	}

	int max_shift = k - n;
	ll ans = 0;

	for (int i = 0; i < n; i++) {
		int max_i = i + max_shift;
		if (a[i]) {
			ans += max_shift + 1 - get_sum(i, max_i);
		} else {
			ans += get_sum(i, max_i);
		}
	}

	cout << ans << endl;

    return 0;
}