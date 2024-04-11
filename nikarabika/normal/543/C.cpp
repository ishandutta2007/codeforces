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

const int maxn = 20,
	  maxal = 26,
	  maxmask = 1 << maxn;
int dp[maxmask],
	a[maxn][maxn],
	MAX[maxal],
	COS[maxal],
	MASK[maxal];
vector<pii> cost[maxn];
string s[maxn];
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> s[i];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			cost[i].PB(MP(1 << i, a[i][j]));
		}
	for(int j = 0; j < m; j++){
		memset(MAX, 0, sizeof MAX);
		memset(COS, 0, sizeof COS);
		memset(MASK, 0, sizeof MASK);
		for(int i = 0; i < n; i++){
			smax(MAX[s[i][j] - 'a'], a[i][j]);
			COS[s[i][j] - 'a'] += a[i][j];
			MASK[s[i][j] - 'a'] += 1 << i;
		}
		for(int i = 0; i < 26; i++)
			for(int k = 0; k < 20; k++)
				if((MASK[i] >> k) & 1)
					cost[k].PB(MP(MASK[i], COS[i] - MAX[i]));
	}
	memset(dp, 63, sizeof dp);
	dp[0] = 0;
	for(int mask = 1; mask < (1 << n); mask++){
		int id = 0;
		while(!((mask >> id) & 1)) id++;
		for(auto e : cost[id])
			smin(dp[mask], dp[mask & (((1 << n) - 1) ^ e.L)] + e.R);
	}
	cout << dp[(1 << n) - 1] << '\n';
	return 0;
}