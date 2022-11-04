#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))

using namespace std;

const int INF = 1e9;
const int MAXN = 2005;

int dp[2][2 * MAXN + 1][MAXN + 1];

int main() {
#ifdef HOME
	ifstream cin("C.in");
	ofstream cout("C.out");
#endif
	int i, n, m;
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	vector<int> l(n + 1), s(n + 1);
	for(i = 1; i <= n; i++) {
		cin >> l[i];
	}
	for(i = 1; i <= n; i++) {
		cin >> s[i];
	}
	vector<int> c(n + m + 2);
	for(i = 1; i <= n + m; i++) {
		cin >> c[i];
	}
	reverse(next(l.begin()), l.end());
	reverse(next(s.begin()), s.end());
	vector<int> fr(n + m + 1);
	for(i = 1; i <= n; i++) {
		fr[l[i]]++;
	}
	for(i = 1; i <= n + m; i++) {
		fr[i] += fr[i - 1] / 2;
	}
	for(int k = 0; k <= n + m; k++) {
		for(int cnt = 0; cnt <= fr[k]; cnt++) {
			dp[0][k][cnt] = -INF;
		}
	}
	dp[0][0][0] = 0;
	int ans = 0;
	for(i = 0; i <= n; i++) {
		for(int k = 0; k <= n + m; k++) {
			for(int cnt = 0; cnt <= fr[k]; cnt++) {
				dp[1 - (i & 1)][k][cnt] = -INF;
			}
		}
		for(int k = 0; k <= n + m; k++) {
			for(int cnt = 0; cnt <= fr[k]; cnt++) {
				int cur = dp[i & 1][k][cnt];
				if(cur == -INF) {
					continue;
				}
				dp[i & 1][k + 1][cnt / 2] = max(dp[i & 1][k + 1][cnt / 2], cur + c[k + 1] * (cnt / 2));
				if(i < n) {
					dp[1 - (i & 1)][k][cnt] = max(dp[1 - (i & 1)][k][cnt], cur);
					if(l[i + 1] == k) {
						dp[1 - (i & 1)][k][cnt + 1] = max(dp[1 - (i & 1)][k][cnt + 1], cur + c[l[i + 1]] - s[i + 1]);
					}
					if(l[i + 1] > k && cnt <= 1) {
						dp[1 - (i & 1)][l[i + 1]][1] = max(dp[1 - (i & 1)][l[i + 1]][1], cur + c[l[i + 1]] - s[i + 1]);	
					}
				}
			}
		}
		for(int k = 0; k <= n + m; k++) {
			ans = max(ans, dp[i & 1][k][1]);
		}
	}
	cout << ans;

	return 0;
}