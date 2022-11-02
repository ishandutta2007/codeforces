#include <bits/stdc++.h>
using namespace std;
  
//#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e9 + 7;
const int max_n = 15;

int n, a[max_n];
int sum[1 << max_n];
int dp[max_n + 1][1 << max_n][max_n + 1];
pii p[max_n + 1][1 << max_n][max_n + 1];

void solve() {
	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];

	for(int i = 0;i < (1 << n);i++) {
		sum[i] = 0;
		for(int j = 0;j < n;j++) {
			if (i & (1 << j)) sum[i] += a[j];
		}
	}


	//cout << "sum" << endl;

	for(int i = 0;i <= n;i++) for(int j = 0;j < (1 << n);j++) for(int k = 0;k <= n;k++) 
		dp[i][j][k] = inf;


	dp[0][0][0] = 0;

	for(int cnt = 0;cnt < n;cnt++) {
		for(int mask = 0;mask < (1 << n);mask++) {
			for(int pos = 0;pos <= n;pos++) {

				if (dp[cnt][mask][pos] >= inf) continue;

				int fmask = ((1 << n) - 1) ^ mask;
				for(int nmask = fmask;nmask;nmask = (nmask - 1) & fmask) {
					if (sum[nmask] <= dp[cnt][mask][pos]) continue;
					if ((nmask >> pos) == 0) continue;

					int npos = pos + 1 + __builtin_ctz(nmask >> pos);

					if (dp[cnt + 1][mask | nmask][npos] > sum[nmask]) {
						dp[cnt + 1][mask | nmask][npos] = sum[nmask];
						p[cnt + 1][mask | nmask][npos] = {mask, pos};
					}
				} 
			}
		}
	}

	//cout << "dp" << endl;

	
	vector<pii> res;

	int cnt = 0;
	int mask = (1 << n) - 1;
	int pos = 0;
	for(int i = 0;i <= n;i++) {
		for(int j = 0;j <= n;j++) {
			if (dp[i][mask][j] < inf) {
				cnt = i;
				pos = j;
			}
		}
	}

	while(cnt > 0) {
		int pmask = p[cnt][mask][pos].first;
		int ppos = p[cnt][mask][pos].second;
		int nmask = mask ^ pmask;

		for(int i = 0;i < n;i++) {
			if (!(nmask & (1 << i))) continue;
			if (i != pos - 1) res.emplace_back(i, pos - 1);
		}

		cnt--;
		mask = pmask;
		pos = ppos;
	}

	//for(auto i : res) cout << i.first << " " << i.second << endl;

	cout << res.size() << endl;

	for(int i = 0;i < sz(res);i++) {
		int from = res[i].first;
		int to = res[i].second;
		for(int j = 0;j < i;j++) from -= res[j].first < res[i].first;
		for(int j = 0;j < i;j++) to -= res[j].first < res[i].second;
		cout << from + 1 << " " << to + 1 << endl;
	}
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