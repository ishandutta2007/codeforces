#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int maxn = 1e5 + 85 - 69;
const LL Inf = 1000000000LL * 1000000000LL;
LL val[maxn], dp[maxn], a, b;
int col[maxn], n, q, Max1, Max2;

void solve(){
	for(int i = 0; i < maxn; i++)
		dp[i] = -Inf;
	Max1 = n + 1;
	Max2 = n + 1;
	for(int i = 1; i <= n; i++){
		//cout << i << ' ' << col[i] << ' ';
		if(dp[col[i]] != -Inf)
			dp[col[i]] = max(dp[col[i]], dp[col[i]] + a * val[i]);
		dp[col[i]] = max(dp[col[i]], b * val[i]);
		if(Max1 != n + 1 and Max1 != col[i])
			dp[col[i]] = max(dp[col[i]], dp[Max1] + b * val[i]);
		else if(Max2 != n + 1)
			dp[col[i]] = max(dp[col[i]], dp[Max2] + b * val[i]);

		//Fix Max(s) :'(
		if(dp[col[i]] >= dp[Max1]){
			if(Max1 != col[i])
				swap(Max1, Max2);
			Max1 = col[i];
		}
		else if(dp[col[i]] > dp[Max2]){
			if(Max1 != col[i])
				Max2 = col[i];
		}
		//cout << dp[col[i]] << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
		cin >> val[i];
	for(int i = 1; i <= n; i++)
		cin >> col[i];
	while(q--){
		cin >> a >> b;
		solve();
		cout << max(0LL, dp[Max1]) << '\n';
	}
	return 0;
}