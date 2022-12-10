#include <bits/stdc++.h>

using namespace std;

#define F(x) x * (x + 1) / 2

typedef long long int ll;

const ll maxr = 2e5 + 10, D = 1e9 + 7;
int r, g, h;
int dp[2][maxr];

void seth(ll x){
	ll lo = 1, hi = x + 1;
	while(hi - lo > 1){
		ll mid = (lo + hi) >> 1;
		if(F(mid) <= x)
			lo = mid;
		else
			hi = mid;
	}
	h = lo;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> r >> g;
	seth(r + g);
	dp[1][1] = 1;
	if(g)
		dp[1][0] = 1;
	int hh = h - 1;
	for(int i = 2; i <= h; i++){
		int x = F(i);
		for(int j = 0; j <= r; j++){
			dp[i & 1][j] = 0;
			if(j >= i)
				dp[i & 1][j] += dp[(i - 1) & 1][j - i];
			if(g - x + j >= 0)
				dp[i & 1][j] += dp[(i - 1) & 1][j];
			dp[i & 1][j] %= D;
		}
	}
	int ans = 0;
	for(int j = 0; j <= r; j++){
		ans += dp[h & 1][j];
		ans %= D;
	}
	cout << ans << endl;
	return 0;
}