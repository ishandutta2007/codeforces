//sobskdrbhvk!
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

const int maxn = 2000 + 85 - 69;
const LL Inf = 1000LL * 1000 * 1000 * 1000 * 1000;
int dp[maxn],
	a[maxn],
	d[maxn],
	n, k;

bool check(LL diff){
	int ret = n;
	for(int i = 1; i <= n; i++){
		dp[i] = i;
		LL sum = 0;
		for(int j = i; j > 0; j--){
			sum += d[j];
			if(abs(sum) <= diff * (i - j + 1))
				smin(dp[i], i - j + dp[j - 1]);
			LL tmp = sum % 1;
			sum += tmp;
		}
		smin(ret, dp[i] + n - i);
	}
	return ret <= k;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	if(n <= 1){
		cout << 0;
		return 0;
	}
	--n;
	for(int i = 0; i < n; i++)
		d[i + 1] = a[i + 1] - a[i];
	LL lo, hi;
	for(lo = -1, hi = 1LL*2000*1000*1000; hi - lo > 1;){
		int mid = (lo + hi) >> 1;
		if(check(mid))
			hi = mid;
		else
			lo = mid;
	}
	cout << hi << '\n';
	return 0;
}