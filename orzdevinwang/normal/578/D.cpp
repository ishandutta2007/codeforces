#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 7;
int n, S, now[N], nxt[N];
ll dp[N][4][3], ans; 
bool mp[26];
char s[N]; 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> S, cin >> (s + 1);
	dp[0][0][0] = 1;
	for(int i = 1; i <= n; i++) {
		memset(mp, 0, sizeof(mp));
		for(int j = max(i - 1, 1); j <= min(i + 1, n); j++) mp[s[j] - 'a'] = 1;
		for(int j = 0; j < 4; j++) {
			for(int k = 0; k <= 1; k++) if(dp[i - 1][j][k]) { 
				now[i - 1] = i - 1 - k, now[i] = now[i - 1] + (j >> 1 & 1);
				if(i - 2 > 0) now[i - 2] = now[i - 1] - (j & 1); 
				int to1 = -1, to2;
				for(char t_i = 'a'; t_i <= 'a' + S - 1; t_i++) {
					if(!mp[t_i - 'a'] && ~to1) {
						dp[i][to1][to2] += dp[i - 1][j][k];
						continue;
					}
					int msk = 0;
					for(int wz = max(i - 1, 1); wz <= i + 1; wz++) nxt[wz] = max(max(now[wz], now[wz - 1] + (s[wz] == t_i)), nxt[wz - 1]);
					for(int wz = max(i - 1, 0); wz <= i; wz++) if(nxt[wz] ^ nxt[wz + 1]) msk |= (1 << (wz - i + 1));
					dp[i][msk][i - nxt[i]] += dp[i - 1][j][k];
					if(!mp[t_i - 'a']) to1 = msk, to2 = i - nxt[i];
				}
			}
		}
	}
	for(int i = 0; i < 4; i++) ans += dp[n][i][1];
	cout << ans << "\n";
	return 0;
}