#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 705;
const int MOD = (int)1e9 + 7;

int dp[N][N][2];

string t;

int powr;

int calc(int Dig){
	memset(dp, 0, sizeof dp);
	dp[0][0][0] = 1;
	int n = t.size();
	int digit;
	int cnt;
	int stat;
	for(int i = 0; i < n ; i ++ ){
		digit = t[i] - '0';
		for(int j = 0; j <= i; j ++ ){
			for(int z = 0; z < 2; z ++ ){
				for(int next_dig = 0; next_dig < 10; next_dig ++ ){
					if(z == 0 && next_dig > digit)
						continue;
					cnt = j + (next_dig >= Dig);
					stat = z | (next_dig < digit);
					dp[i + 1][cnt][stat] += dp[i][j][z];
					dp[i + 1][cnt][stat] %= MOD;
				}
			}
		}
	}
	int ans = 0;
	int powr = 1ll;
	int sum;
	int psum = 0;
	for(int i = 1; i <= n; i ++ ){
		psum = (psum + powr) % MOD;
		sum = (dp[n][i][0] + dp[n][i][1]) % MOD;
		sum = (1ll * sum * psum) % MOD;
		ans = (ans + sum) % MOD;
		powr = (10ll * powr) % MOD;
	}
	return ans;
}

int main(){
	fastIO;
	cin >> t;
	int las = 0;
	int cur;
	int add;
	int ans = 0;
	for(int i = 9 ; i >= 1; i -- ){
		cur = calc(i);
		add = (cur - las + MOD) % MOD;
		add = (1ll * i * add) % MOD;
		ans = (ans + add) % MOD;
		las = cur;
	}
	cout << ans << "\n";
	return 0;
}