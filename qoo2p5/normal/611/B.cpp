#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define sz(x) (int) x.size()
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs((a) - (b)) < EPS
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 +  7;
const ld EPS = 1e-14;

#define TASKNAME ""

int main() {
	ios::sync_with_stdio(false);
#ifndef DEBUG
	if (TASKNAME != "") {
		freopen(TASKNAME ".in", "r", stdin);
		freopen(TASKNAME ".out", "w", stdout);
	}
#else
	//freopen("input.txt", "r", stdin);
#endif

	ull l, r;
	cin >> l >> r;
	int ans = 0;

	for (int bit_cnt = 1; bit_cnt < 63; bit_cnt++) {
		for (int where = bit_cnt - 1; where >= 0; where--) {
			ull num = 0;
			for (int i = 0; i < bit_cnt + 1; i++) {
				if (i != where) {
					num += (1ULL << i);
				}
			}

			if (l <= num && num <= r) {
				ans++;
			}
		}
	}

	cout << ans << endl;

	return 0;
}