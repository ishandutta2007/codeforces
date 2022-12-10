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

const int maxn = 5000 + 85 - 69;
const LL Mod = 1000 * 1000 * 1000 + 7;
LL dp[2][maxn];
LL ans;
string s, t;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t;
	s = '*' + s;
	t = '*' + t;
	int n = sz(s),
		m = sz(t);
	for(int i = 1; i < m; i++){
		int cur = i&1,
			pre = i&1^1;
		for(int j = 1; j < n; j++){
			dp[cur][j] = dp[pre][j] + (dp[pre][j - 1] + 1) * (s[j] == t[i]);
			if(dp[cur][j] >= Mod)
				dp[cur][j] -= Mod;
		}
	}
	int cur = m&1^1;
	for(int j = 1; j < n; j++)
		ans = (ans + dp[cur][j]) % Mod;
	cout << ans << endl;
	return 0;
}