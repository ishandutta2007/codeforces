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

const int maxn = 210;
int dp[maxn][maxn][maxn];
int n, cnt[3];
map<char, int> mp;

int DP(int i, int j, int k){
	if(dp[i][j][k] != -1)
		return dp[i][j][k];
	if(i + j + k == 1){
		if(i == 1)
			return dp[i][j][k] = 1;
		if(j == 1)
			return dp[i][j][k] = 2;
		if(k == 1)
			return dp[i][j][k] = 4;
	}
	int &cur = dp[i][j][k];
	cur = 0;
	if(i and j)
		cur |= DP(i - 1, j - 1, k + 1);
	if(i and k)
		cur |= DP(i - 1, j + 1, k - 1);
	if(j and k)
		cur |= DP(i + 1, j - 1, k - 1);
	if(i >= 2)
		cur |= DP(i - 1, j, k);
	if(j >= 2)
		cur |= DP(i, j - 1, k);
	if(k >= 2)
		cur |= DP(i, j, k - 1);
	return cur;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(dp, -1, sizeof dp);
	mp['B'] = 0, mp['G'] = 1, mp['R'] = 2;
	cin >> n;
	for(int i = 0; i < n; i++){
		char c;
		cin >> c;
		cnt[mp[c]]++;
	}

	if(DP(cnt[0], cnt[1], cnt[2]) & 1)
		cout << 'B';
	if(DP(cnt[0], cnt[1], cnt[2]) & 2)
		cout << 'G';
	if(DP(cnt[0], cnt[1], cnt[2]) & 4)
		cout << 'R';
	cout << endl;
	return 0;
}