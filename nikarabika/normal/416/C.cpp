#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define L first
#define R second

typedef long long int ll;
typedef pair<int, int> pie;

const int maxn = 1e3 + 10;
pair<bool, bool> par[maxn][maxn];
int dp[maxn];
pie r[maxn];
pair<pie, int> a[maxn];
int n, k;
vector<pair<int, int> > ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].L.L >> a[i].L.R;
		a[i].R = i;
	}
	cin >> k;
	for(int i = 1; i <= k; i++){
		cin >> r[i].L;
		r[i].R = i;
	}
	sort(a + 1, a + n + 1);
	sort(r + 1, r + k + 1);

	for(int i = 1; i <= n; i++){
		for(int j = k; j > 0; j--){
			par[i][j] = MP(1, 0);
			if(dp[j - 1] > dp[j]){
				dp[j] = dp[j - 1];
				par[i][j] = MP(0, 1);
			}
			if(a[i].L.L <= r[j].L and dp[j - 1] + a[i].L.R > dp[j]){
				dp[j] = dp[j - 1] + a[i].L.R;
				par[i][j] = MP(1, 1);
			}
		}
	}
	int row = n, col = k;
	while(par[row][col] != MP(false, false)){
		if(par[row][col] == MP(true, true))
			ans.PB(MP(a[row].R, r[col].R));
		pie x = par[row][col];
		row -= x.L;
		col -= x.R;
	}
	cout << ans.size() << ' ' << dp[k] << endl;
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i].L << ' ' << ans[i].R << endl;
	return 0;
}