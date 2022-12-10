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

const int maxn = 1e3 + 85 - 69;
int n, m;
bool row[maxn],
	 col[maxn];
bool a[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		row[fi] = true;
		col[se] = true;
		a[fi][se] = true;
	}
	int ans = (n & 1) and (!row[n/2] or !col[n/2]);
	for(int i = 1; i < n / 2; i++){
		int ii = n - i - 1;
		int cnt = 0 + a[i][i] + a[i][ii] + a[ii][i] + a[ii][ii],
			cnt2 = 0 + row[i] + row[ii] + col[i] + col[ii];
		if(cnt > 2)
			continue;
		ans += 4 - cnt2;
	}
	cout << ans << '\n';
	return 0;
}