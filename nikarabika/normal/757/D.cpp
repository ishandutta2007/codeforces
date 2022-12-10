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

const int maxn = 75 + 2;
const int Mod = 1e9 + 7;
int dp[maxn][1<<20];
int n;
string s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n
		>> s;
	reverse(all(s));
	s = '*' + s;
	for(int i = 0; i <= n; i++)
		dp[i][0] = 1;
	for(int i = 0; i < n; i++){
		int num = 0;
		if(s[i + 1] == '0')
			for(int mask = 1; mask < (1 << 20); mask++){
				int &DP = dp[i + 1][mask];
				DP += dp[i][mask];
				if(DP >= Mod) DP -= Mod;
			}
		for(int j = 1; j <= 5 and i + j <= n; j++){
			if(s[i + j] - '0')
				num += 1 << (j-1);
			if(s[i + j] == '1' and num <= 20)
				for(int mask = 0; mask < (1 << 20); mask++){
					int &DP = dp[i + j][mask|(1<<(num - 1))];
					DP += dp[i][mask];
					if(DP >= Mod) DP -= Mod;
				}
		}
	}
	int ans = 0;
	for(int i = 0; i <= n; i++)
		for(int ii = 1; ii <= 20; ii++)
			ans = (ans + dp[i][(1 << ii) - 1]) % Mod;
	cout << ans << '\n';
	return 0;
}