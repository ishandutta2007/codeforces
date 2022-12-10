//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int solve() {
	int h, n;
	cin >> h >> n;
	vector<pii> vec;
	set<int> s;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		vec.PB(MP(x, 1));
		s.insert(x);
	}
	for (int i = 0; i < n; i++) {
		if (s.find(vec[i].L - 1) == s.end() and vec[i].L - 1 > 0)
			vec.PB(MP(vec[i].L - 1, 0));
		if (s.find(vec[i].L - 2) == s.end() and vec[i].L - 2 > 0)
			vec.PB(MP(vec[i].L - 2, 0));
	}
	sort(all(vec), greater<pii>());
	vec.resize(unique(all(vec)) - vec.begin());
	for (int i = min(2, vec.back().L - 1); i > 0; i--)
		vec.PB(MP(i, 0));
	n = sz(vec);
	int dp[n];
	for (int i = n - 1; i >= 0; i--) {
		int nxt = i + 1;
		while (nxt < n and vec[nxt].R == 0)
			nxt++;
		if (nxt == n or vec[i].L <= 2) {
			dp[i] = 0;
			continue;
		}
		if (vec[i].R) {
			if (vec[i + 1].R)
				dp[i] = dp[i + 2] + 1 - vec[i + 2].R;
			else
				dp[i] = dp[i + 1];
		}
		else {
			dp[i] = dp[nxt] + 1;
			if (nxt + 1 == n)
				dp[i] = 0;
			else
				smin(dp[i], dp[nxt + 1] + 1 - vec[nxt + 1].R);
		}
	}
//	for (int i = 0; i < n; i++)
//		cout << vec[i].L << ',' << vec[i].R << ' ';
//	cout << endl;
//	for (int i = 0; i < n; i++)
//		cout << dp[i] << ' ';
//	cout << endl;
	cout << dp[0] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}