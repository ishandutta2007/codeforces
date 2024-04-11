#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
const int MOD = (int) 1e9 + 7;
const ll LINF = (ll) 1e18 + 123;

#define sz(x) (int) (x).size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

void run();

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#endif
	run();
	return 0;
}

// == BEGIN SOLUTION == //

const int N = (int) 5e5 + 123;

int n;
bool a[N];

void run() {
	cin >> n;
	int ans = 0;
	int cur = 0;
	for (int i = 0; i < 2 * n; i++) {
		int x;
		cin >> x;
		if (a[x]) {
			a[x] = 0;
			cur--;
		} else {
			a[x] = 1;
			cur++;
		}
		ans = max(ans, cur);
	}
	cout << ans << '\n';
}