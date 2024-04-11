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

struct item {
	int a, b, id;

	item() {}
	item(int a, int b, int id) : a(a), b(b), id(id) {}

	bool operator<(const item &other) const {
		return a < other.a;
	}
};

int n;
vector<item> p;
int dp[200000];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		p.pb(item(a, b, i));
	}

	sort(p.begin(), p.end());

	dp[0] = 0;
	for (int i = 1; i < n; i++) {
		int left = p[i].a - p[i].b;
		auto it = lower_bound(p.begin(), p.end(), item(left, -1, -1));
		if (it == p.begin()) {
			dp[i] = i;
		} else {
			it--;
			int id = it - p.begin();
			dp[i] = dp[id] + (i - id - 1);
		}
	}

	int ans = n;

	for (int i = 0; i < n; i++) {
		ans = min(ans, dp[i] + n - i - 1);
	}

	cout << ans << endl;

    return 0;
}