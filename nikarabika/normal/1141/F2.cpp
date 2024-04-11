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

const int maxn = 1500;
int dp[maxn][maxn];
pii par[maxn][maxn];
int a[maxn],
	s[maxn],
	n;
unordered_map<int, pii> last;

pii get(int sum) {
	auto res = last[sum];
	res.L--;
	res.R--;
	return res;
}

void update(int sum, int l, int r) {
	l++, r++;
	if (l > last[sum].L)
		last[sum] = MP(l, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], s[i + 1] = s[i] + a[i];
	int ans = 0;
	int le, ri;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int cursum = s[j + 1] - s[i];
			pii seg = get(cursum);
			if (seg.L != -1)
				dp[i][j] = dp[seg.L][seg.R] + 1;
			else
				dp[i][j] = 1;
			par[i][j] = seg;
			if (dp[i][j] > ans) {
				ans = dp[i][j];
				le = i, ri = j;
			}
		}
		for (int j = 0; j <= i; j++)
			update(s[i + 1] - s[j], j, i);
	}
	cout << ans << '\n';
	while (le >= 0) {
		cout << le + 1 << ' ' << ri + 1 << '\n';
		auto nxt = par[le][ri];
		le = nxt.L, ri = nxt.R;
	}
	return 0;
}