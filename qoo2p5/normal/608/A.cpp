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

int n, s;
int t[1001];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		int f, x;
		cin >> f >> x;
		t[f] = max(t[f], x);
	}

	int cur_t = 0;
	for (int i = s; i >= 0; i--) {
		if (cur_t < t[i]) {
			cur_t = t[i];
		}

		cur_t++;
	}

	cout << cur_t - 1 << endl;

    return 0;
}