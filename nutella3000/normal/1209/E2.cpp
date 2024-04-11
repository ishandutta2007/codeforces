#include <bits/stdc++.h>
using namespace std;
const int max_n = 12;
int a[max_n][max_n];
int dp[max_n][(1 << max_n)], max_sum[max_n][(1 << max_n)];
int n, m;

void scan() {
	cin >> n >> m;
	int b[n][m];
	int Max[m];

	for(int i = 0;i < m;i++) Max[i] = -1;

	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			cin >> b[i][j];
			Max[j] = max(Max[j], b[i][j]);
		}
	}

	bool used[m];
	for(int i = 0;i < m;i++) used[i] = false;

	for(int id1 = 0;id1 < min(n, m);id1++) {
		int id = -1;
		for(int i = 0;i < m;i++) {
			if (used[i]) continue;
			if (id == -1 || Max[i] > Max[id]) id = i;
		}
		used[id] = true;
		for(int j = 0;j < n;j++) a[j][id1] = b[j][id];
	}
	m = min(n, m);

	/*for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}*/
}

void solve() {
	scan();

	for(int i = 0;i < m;i++) {
		for(int mask = 0;mask < (1 << n);mask++) {
			int sum = 0;
			for(int shift = 0;shift < n;shift++) {
				int new_sum = 0;
				for(int j = 0;j < n;j++) {
					if ((mask & (1 << j)) == 0) continue;
					int temp = j + shift;
					if (temp >= n) temp -= n;
					new_sum += a[temp][i];
				}
				sum = max(sum, new_sum);
			}
			max_sum[i][mask] = sum;
		}
	}


	for(int i = 0;i < m;i++) {
		for(int mask = 0;mask < (1 << n);mask++) {

			dp[i][mask] = 0;

			for(int mask1 = mask;mask1 >= 0;mask1 = ((mask1 - 1) & mask)) {	
				int cur = (mask & ((1 << n) - 1 - mask1));
				//for(int j = 1;j < (1 << n);j <<= 1) if ((mask & j) != 0 && (mask1 & j) == 0) cur += j;

				int sum = max_sum[i][cur];

				int temp = 0;
				if (i != 0) temp = dp[i - 1][mask1];

				dp[i][mask] = max(dp[i][mask], temp + sum);

				if (mask1 == 0) break;
			}
		}
	}

	cout << dp[m - 1][(1 << n) - 1] << '\n';
}





int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int t;
    cin >> t;
    while(t--) {
    	solve();
    }

}