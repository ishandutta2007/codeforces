#include <bits/stdc++.h>
using namespace std;

int n, a[80], slot_cnt = 1;
int cost[80][80][80];
int dp[81][81][81*81];
vector<int> zpos;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n; int initial_cost = 0, prv = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (!a[i]) {
			zpos.push_back(i);
			initial_cost += prv;
			prv++;
		} else {
			slot_cnt++;
			prv = 0;
		}
	}

	int m = zpos.size();
	for (int l = 0; l < m; l++) {
		for (int r = l; r < m; r++) {
			for (int k = 0; k < slot_cnt; k++) {
				int pos = k+l;
				for (int i = l; i <= r; i++) {
					cost[l][r][k] += abs(zpos[i] - pos);
					pos++;
				}
				//cout << l << ' ' << r << ' ' << k << ' ' << cost[l][r][k] << '\n'; 
			}
		}
	}

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= slot_cnt; j++) {
			for (int k = 0; k <= 1600; k++) {
				dp[i][j][k] = initial_cost;
			}
		}
	}
	for (int k = 0; k <= 1600; k++) {
		for (int j = 0; j < slot_cnt; j++) {
			dp[0][j][k] = 0;
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= slot_cnt; j++) {
			for (int k = 0; k <= 1600; k++) {
				dp[i][j][k] = min(dp[i][j][k], dp[i][j-1][k]);
				for (int r = i; r <= m; r++) {
					int cs = cost[i-1][r-1][j-1];
					int len = r-i+1;

					if (cs > k) continue;

					dp[r][j][k] = min(dp[r][j][k], dp[i-1][j-1][k-cs] + len*(len-1)/2);
				}
			}
		}
	}

	for (int i = 0; i <= n*(n-1)/2; i++) {
		int t = min(1600, i);
		cout << m*(m-1)/2 - dp[m][slot_cnt][t] << ' ';
		//cout << dp[m][slot_cnt][t] << '\n';
	}

	return 0;
}