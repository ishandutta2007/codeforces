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

const int maxn = 4000 + 10,
	  maxk = 800 + 10;
LL dp[maxk][maxn];
LL a[maxn][maxn];
int n, m;
string str;

int cost(int i, int j){
	return 1LL*a[j][j] - a[i][j] - a[j][i] + a[i][i];
}

void solve(int row, int l, int r, int st, int en){
	if(r <= l) return;
	int mid = (l + r) >> 1;
	int pos = -1;
	for(int i = st; i <= en; i++)
		if(i < mid)
			if(dp[row - 1][i] + cost(i, mid) <= dp[row][mid])
				dp[row][mid] = dp[row - 1][i] + cost(i, mid), pos = i;
	solve(row, l, mid, st, pos);
	solve(row, mid + 1, r, pos, en);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	getline(cin, str);	
	for(int i = 1; i <= n; i++){
		getline(cin, str);
		for(int j = 1; j <= n; j++){
			a[i][j] = str[2 * j - 2] - '0';
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		}
	}
	memset(dp, 63, sizeof dp);
	dp[0][0] = 0;
	for(int i = 1; i <= m; i++)
		solve(i, i, n + 1, 0, n);
	cout << dp[m][n]/2 << endl;
	return 0;
}