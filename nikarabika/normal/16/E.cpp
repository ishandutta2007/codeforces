//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double LD;
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

const int maxn = 18;
LD dp[1 << maxn];
LD eaten[1 << maxn][maxn];
LD a[maxn][maxn];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
	for(int mask = 0; mask < (1 << n); mask++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if((mask >> j) & 1)
					eaten[mask][i] += a[j][i];//, eated[mask][i] += a[i][j];
	for(int i = 0; i < n; i++){
		dp[(1 << n) - 1] = 1;
		for(int mask = (1 << n) - 2; mask >= (1 << i); mask--){
			dp[mask] = 0;
			LD cnt = LD(__builtin_popcount(mask));
			for(int j = 0; j < n; j++){
				if((mask >> j) & 1)
					continue;
				dp[mask] += eaten[mask][j] * dp[mask ^ (1 << j)] / (cnt * (cnt + 1) / 2);
			}
		}
		cout << fixed << dp[1 << i] << ' ';
	}
	cout << '\n';
	return 0;
}