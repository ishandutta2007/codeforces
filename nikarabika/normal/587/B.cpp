#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define PB push_back
#define sz(x) ((int)(x).size())

const int maxn = 1e6 + 10;
LL **dp;
LL n, l, k;
LL a[maxn];
LL dp_sum[maxn];
vector<LL> all;
LL allcnt[maxn];
const LL Mod = 1000LL * 1000LL * 1000LL + 7;
LL ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> l >> k;
	dp = new LL*[k + 10];
	for(int i = 0; i < k + 10; i++)
		dp[i] = new LL[n + 10];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		all.PB(a[i]);
	}
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());
	for(int i = 0; i < n; i++){
		int id = lower_bound(all.begin(), all.end(), a[i]) - all.begin();
		allcnt[id]++;
	}
	for(int j = 0; j < sz(all); j++)
		dp[1][j] = 1;
	dp_sum[1] = n;
	for(int i = 2; i <= k; i++){
		for(int j = 0; j < sz(all); j++){
			dp[i][j] = (((dp[i - 1][j] * allcnt[j]) % Mod) + ((j > 0) ? dp[i][j - 1] : 0)) % Mod;;
			dp_sum[i] = (dp_sum[i] + (dp[i][j] * allcnt[j])) % Mod;
		}
	}
	for(LL i = 1; i <= k and i <= (l + n - 1) / n; i++){
		ans = (ans + dp_sum[i] * max(0LL, ((l / n) - i + 1) % Mod)) % Mod;
		for(int ii = 0; ii < l % n; ii++){
			int id = lower_bound(all.begin(), all.end(), a[ii]) - all.begin();
			ans = (ans + dp[i][id]) % Mod;
		}
	}
	cout << ans << endl;
	return 0;
}