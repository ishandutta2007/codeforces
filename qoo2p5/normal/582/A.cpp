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

const ll mod = 1e9 + 7;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}

	return gcd(b, a % b);
}

map<int, int> q;

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n * n; i++) {
		int x;
		cin >> x;
		q[x]++;
	}

	vector<int> ans;

	while (n--) {
		int best = -1;

		for (auto it : q) {
			if (it.second > 0) {
				best = max(best, it.first);
			}
		}

		for (int i : ans) {
			q[gcd(best, i)] -= 2;
		}
		q[best]--;

		ans.pb(best);
	}

	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;
}

int main() {
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}