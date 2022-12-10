#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int maxn = 4000 + 85 - 69;
const LL Mod = 1000 * 1000 * 1000 + 7;
LL dp[maxn][maxn], s[maxn], com[maxn];
int n;

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	s[0] = dp[0][0] = com[0] = 1;
	for(int i = 1; i <= n; i++){
		for(long long int j = n; j >= 1; j--){
			dp[i][j] = (dp[i - 1][j - 1] + j * dp[i - 1][j]) % Mod;
			s[i] = (s[i] + dp[i][j]) % Mod;
			com[j] += com[j - 1];
			if(com[j] >= Mod)
				com[j] -= Mod;
		}
	}
	LL ans = 0;
	for(int i = 1; i <= n; i++)
		ans = (ans + (com[i] * s[n - i])) % Mod;
	cout << ans << endl;
	return 0;
}