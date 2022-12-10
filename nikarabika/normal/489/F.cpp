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

const int maxn = 500 + 10;
LL dp[maxn][maxn],
   c[maxn][6],
   cnt[maxn],
   Mod;
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> Mod;
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++){
			char c;
			cin >> c;
			cnt[j] += c - '0';
		}
	int c1 = 0, c2 = 0;
	for(int i = 0; i < n; i++)
		if(cnt[i] == 0) c2++;
		else if(cnt[i] == 1) c1++;
	c[0][0] = 1;
	for(int i = 1; i < maxn; i++){
		c[i][0] = 1;
		for(int j = 1; j <= 5; j++)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % Mod;
	}
	dp[0][0] = 1;
	for(int j = 0; j < maxn; j++)
		for(int i = 0; i < maxn; i++) if(i + j){
			//2-2
			if(j >= 2 and i + 2 < maxn)
				dp[i][j] += dp[i + 2][j - 2] * c[j][2];
			//2-1
			if(i >= 1 and j >= 1)
				dp[i][j] += dp[i][j - 1] * i * j;
			//1-1
			if(i >= 2)
				dp[i][j] += dp[i - 2][j] * c[i][2];
			dp[i][j] %= Mod;
		}
	cout << dp[c1][c2] << endl;
	return 0;
}