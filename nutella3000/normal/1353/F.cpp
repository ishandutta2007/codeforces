#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e18 + 7;
const int max_n = 101;
int n, m, a[max_n][max_n];
vector<int> b;

void scan() {
	b.clear();
	cin >> n >> m;
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			cin >> a[i][j];
			a[i][j] -= i + j;
			b.emplace_back(a[i][j]);
		}
	}
	sort(b.begin(), b.end());
}

int f(int num) {
	vector<vector<int>> dp(n, vector<int>(m, inf));

	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			if (i == 0 && j == 0) {
				if (a[0][0] >= num) dp[0][0] = a[0][0] - num;
				continue;
			}

			if (a[i][j] < num) continue;
			int res = inf;
			if (i != 0) res = min(res, dp[i - 1][j]);
			if (j != 0) res = min(res, dp[i][j - 1]);
			res += a[i][j] - num;
			dp[i][j] = min(dp[i][j], res);
		}
	}
	return dp[n - 1][m - 1];
}

void solve() {
	scan();
	int res = inf;
	/*int l = -1;
	int r = b.size();
	while(r - l > 1) {
		int mid = ((l + r) >> 1);

		int new_res = f(b[mid]);

		if (new_res >= inf) r = mid;
		else{
			l = mid;
			res = new_res;
		}
	}*/
	for(int i : b) res = min(res, f(i));

	cout << res << endl;
}




signed main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
  	#endif
 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
    	solve();
    }
}