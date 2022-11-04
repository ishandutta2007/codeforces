#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-10
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

int n, t;
string s1, s2;
char ans[100000];

char diff(char a, char b) {
	for (char c = 'a'; c <= 'z'; c++) {
		if (c != a && c != b) {
			return c;
		}
	}

	return 'a';
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> t;
	cin >> s1 >> s2;

	int k = 0;
	int eq = n - t;
	for (int i = 0; i < n; i++) {
		if (s1[i] == s2[i]) {
			if (eq) {
				ans[i] = s1[i];
				eq--;
			} else {
				ans[i] = diff(s1[i], s2[i]);
			}
			k++;
		}
	}

	if (2 * eq > n - k) {
		cout << -1 << endl;
		return 0;
	}

	int eq1 = eq;
	int eq2 = eq;
	for (int i = 0; i < n; i++) {
		if (s1[i] != s2[i]) {
			if (eq1) {
				ans[i] = s1[i];
				eq1--;
			} else if (eq2) {
				ans[i] = s2[i];
				eq2--;
			} else {
				ans[i] = diff(s1[i], s2[i]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i];
	}
	cout << "\n";

	return 0;
}