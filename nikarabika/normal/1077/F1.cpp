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

const int maxn = 5e3 + 10;
const LL INF = 5e13;
LL dp[maxn][maxn],
   a[maxn];
int n, k, x;
deque<short> dq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i < maxn; i++)
		fill(dp[i], dp[i] + maxn, -INF);
	cin >> n >> k >> x;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int j = 0; j < n; j++)
		if (j < k)
			dp[1][j] = a[j];
	for (int i = 2; i <= x; i++) {
		dq.clear();
		for (int j = i - 1; j < n; j++) {
			if (sz(dq) and dq.front() == j - k - 1)
				dq.pop_front();
			while (sz(dq) and dp[i - 1][dq.back()] <= dp[i - 1][j - 1])
				dq.pop_back();
			dq.push_back(j - 1);
			dp[i][j] = dp[i - 1][dq.front()] + a[j];
		}
	}
	LL ans = -INF;
	for (int j = n - k; j < n; j++)
		smax(ans, dp[x][j]);
	if (ans < 0)
		cout << -1 << endl;
	else
		cout << ans << endl;
	return 0;
}