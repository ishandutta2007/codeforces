#include <bits/stdc++.h>
#define long long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e9 + 7;
const int max_n = 5e5 + 1, max_m = 5e5 + 1, max_k = 30;
int n, m, k;
int after[max_k][max_n], num[max_k][max_n];
int mod = 998244353;
int le[max_k][max_n];


void solve1() {
	cin >> n >> k >> m;
	for(int i = 0;i < k;i++) {
		for(int j = 0;j < n;j++) {
			num[i][j] = -1;
			after[i][j] = j + 1;
			le[i][j] = -1;
		}
	}

	for(int q = 0;q < m;q++) {
		int l, r, temp1;
		cin >> l >> r >> temp1;
		l--;r--;
		for(int w = 0;w < k;w++) {
			if ((temp1 & (1 << w)) == 0) {
				le[w][r] = max(le[w][r], l);
				continue;
			}

			int v = l;
			while(v <= r) {
				num[w][v] = 1;
				int to = after[w][v];
				//cout << q << " " << v << " " << to << " ";
				after[w][v] = after[w][r];
				//cout << w << " " << to << '\n';
				v = to;
			}
		}
	}
}


long dp[max_n];

long get(int id) {
	if (id == -1) return 1;
	return dp[id];
}

long solve2(int i) {

	int maxim = 0;
	long sum = 0;
	if (num[i][0] == -1) sum = 1;


	for(int j = 0;j < n;j++) {
		if (num[i][j] == 1 && le[i][j] == j) {
			dp[j] = 0;
		}else if (le[i][j] == -1) {
			dp[j] = get(j - 1) % mod;
			if (num[i][j] == -1) dp[j] = 2 * dp[j] % mod;
		}else {
			while(maxim < le[i][j]) {
				if (num[i][maxim] == -1) sum -= get(maxim - 1);
				maxim++;
				//cout << sum << " " << maxim << '\n';
			}


			/*dp[j] = 0;
			for(int k = j;k >= maxim;k--) {
				if (num[i][k] == -1) dp[j] += get(k - 1);
			}*/
			dp[j] = sum;
			dp[j] %= mod;
		}

		if (j + 1 == n || num[i][j + 1] == -1) sum += dp[j];

	}

	/*cout << i << '\n' << '\n';
	for(int j = 0;j < n;j++) cout << le[i][j] << " ";
	cout << '\n';
	for(int j = 0;j < n;j++) cout << num[i][j] << " ";
	cout << '\n';
	for(int j = 0;j < n;j++) cout << dp[j] << " ";
	cout << '\n' << '\n';*/

	return dp[n - 1];
}

void solve() {
	solve1();
	int res = 1;
	for(int i = 0;i < k;i++) res = res * solve2(i) % mod;

	cout << res;
}



 
 
signed main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 	cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);


 	solve();
}