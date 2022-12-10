//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 8 * 9 * 5 * 7 * 11 * 13 + 10;
LL dp[maxn],
	pd[maxn];
LL a, b, k;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> b >> a >> k;
	LL len = 1;
	for(int i = 1; i <= k; i++)
		len = len / __gcd(len, 1LL * i) * i;
	for(int i = 1; i < len; i++){
		dp[i] = dp[i - 1] + 1;
		for(int j = 2; j <= k; j++)
			smin(dp[i], dp[i - (i % j)] + 1);
	}
	memset(pd, 63, sizeof pd);
	pd[a % len] = 0;
	for(int i = a % len + 1; i < len; i++){
		pd[i] = pd[i - 1] + 1;
		for(int j = 2; j <= k; j++)
			smin(pd[i], pd[i - (i % j)] + 1);
	}
	if(a / len == b / len){
		cout << pd[b % len] << endl;
		return 0;
	}
	LL ans = dp[b % len] + 1 + pd[len - 1];
	LL posa = a / len,
	   posb = b / len - 1;
	ans += (dp[len - 1] + 1) * (posb - posa);
	cout << ans << '\n';
	return 0;
}