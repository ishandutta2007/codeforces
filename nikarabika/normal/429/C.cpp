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

const int maxn = 12;
int dp[1 << maxn][maxn * 2 + 1];
int sum[1 << maxn][maxn * 2 + 1];
bool can[1 << maxn][maxn * 2 + 1];
int a[maxn];
int n, cnt;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] == 1) cnt++;
	}
	if(cnt <= n / 2){
		cout << "NO" << endl;
		return 0;
	}
	sort(a, a + n);
	reverse(a, a + n);
	n -= cnt;
	memset(dp, -1, sizeof dp);
	for(int i = 0; i <= cnt; i++)
		dp[0][i] = sum[0][i] = i;
	can[0][1] = true;
	for(int mask = 1; mask < (1 << n); mask++){
		for(int i = 0; i <= cnt; i++){
			int bg = -1;
			sum[mask][i] = i + __builtin_popcount(mask);
			for(int j = 0; j < n; j++)
				if((mask >> j) & 1){
					bg = j;
					break;
				}
			can[mask][i] = (dp[mask - (mask & -mask)][i] > 1) and a[bg] - 1 == sum[mask - (mask & -mask)][i];
			//if(mask == 1 and i == 2) cout << sum[0][2] << endl;
			if(can[mask][i])
				dp[mask][i] = 1;
			for(int mask2 = mask; 1; mask2 = mask & (mask2 - 1)){
				//if((mask2 >> bg) & 1)
					for(int j = 0; j <= i; j++)
						if(~dp[mask2][j] and ~dp[mask - mask2][i - j])
							smax(dp[mask][i], dp[mask2][j] + dp[mask - mask2][i - j]);
				if(!mask2) break;
			}
			//cout << mask << ' ' << i << ' ' << dp[mask][i] << ' ' << sum[mask][i] << endl;
		}
	}
	cout << (can[(1 << n) - 1][cnt] ? "YES" : "NO") << endl;
	return 0;
}