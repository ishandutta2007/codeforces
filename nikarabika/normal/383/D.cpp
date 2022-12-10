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

const int MAX = 10000,
	  maxn = 1000,
	  Mod = 1e9 + 7;
int a[maxn], n;
int dparr[2][MAX * 2 + 10];
int *dp[2] = {dparr[0] + MAX + 5, dparr[1] + MAX + 5};
int ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++){
		int cur = i&1,
			pre = i&1^1;
		for(int j = -MAX; j <= +MAX; j++){
			dp[cur][j] = 0;
			if(j - a[i] >= -MAX) dp[cur][j] += dp[pre][j - a[i]];
			if(j + a[i] <= +MAX) dp[cur][j] += dp[pre][j + a[i]];
		}
		dp[cur][+a[i]]++;
		dp[cur][-a[i]]++;
		for(int j = -MAX; j <= +MAX; j++)
			dp[cur][j] %= Mod;
		ans = (ans + dp[cur][0]) % Mod;
	}
	cout << ans << endl;
	return 0;
}