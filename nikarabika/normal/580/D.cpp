//sobskdrbhvk
//remember the flying, the bird dies ):(
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

const int maxn = 19;
LL dp[1<<maxn][maxn];
LL a[maxn],
   mat[maxn][maxn];
int n, m, k;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < k; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		fi--, se--;
		mat[fi][se] = th;
	}
	memset(dp, -63, sizeof dp);
	LL ans = 0;
	for(int mask = 1; mask < (1 << n); mask++){
		if(__builtin_popcount(mask) == 1)
			dp[mask][__builtin_ctz(mask)] = a[__builtin_ctz(mask)];
		for(int i = 0; i < n; i++) if((mask >> i) & 1){
			for(int j = 0; j < n; j++)
				if((i^j) and ((mask >> j) & 1))
					smax(dp[mask][i], dp[mask^(1<<i)][j] + a[i] + mat[i][j]);
			if(__builtin_popcount(mask) == m)
				smax(ans, dp[mask][i]);
		}
	}
	cout << ans << endl;
	return 0;
}