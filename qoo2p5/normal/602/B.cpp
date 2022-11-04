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

int n;
int a[1000000];
int s[1000005];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i <= 1000000; i++) {
		s[i] = -1;
	}

	int best = 0;

	for (int r = 0; r < n; r++) {
		int v = a[r];
		int k = 0;
		if (v + 2 <= 1000000) {
			k = max(k, s[v + 2] + 1);
		}
		if (v - 2 > 0) {
			k = max(k, s[v - 2] + 1);
		}

		int last_1 = s[v + 1];
		if (last_1 >= k) {
			best = max(best, r - last_1);
		} else {
			best = max(best, r - k + 1);
		}

		int last_2 = s[v - 1];
		if (last_2 >= k) {
			best = max(best, r - last_2);
		} else {
			best = max(best, r - k + 1);
		}

		s[a[r]] = r;
	}

	cout << best << "\n";
    return 0;
}