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

const int maxn = 100,
	  maxq = 1e5 + 85 - 69;
int dis[maxn][maxn],
	mat[maxn][maxn],
	a[maxn][maxn][maxn],
	ans[maxq],
	n, m, r;
vector<pair<pii, int> > vec[maxn];

void solve(int sou){
	memset(dis, 63, sizeof dis);
	dis[sou][0] = 0;
	for(int j = 0; j < n; j++)
		for(int i = 0; i < n; i++)
			for(int k = 0; k < n; k++)
				smin(dis[k][j + 1], dis[i][j] + mat[i][k]);
	for(int i = 0; i < n; i++)
		for(int j = 1; j <= n; j++)
			smin(dis[i][j], dis[i][j - 1]);
	for(auto quer : vec[sou])
		ans[quer.R] = dis[quer.L.L][quer.L.R];
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> r;
	for(int i = 0; i < m; i++)
		for(int ii = 0; ii < n; ii++)
			for(int jj = 0; jj < n; jj++)
				cin >> a[i][ii][jj];
	for(int i = 0; i < m; i++)
		for(int kk = 0; kk < n; kk++)
			for(int ii = 0; ii < n; ii++)
				for(int jj = 0; jj < n; jj++)
					smin(a[i][ii][jj], a[i][ii][kk] + a[i][kk][jj]);
	memset(mat, 63, sizeof mat);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < m; k++)
				smin(mat[i][j], a[k][i][j]);
	for(int i = 0; i < r; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		fi--, se--;
		vec[fi].PB(MP(MP(se, min(n, th+1)), i));
	}
	for(int i = 0; i < n; i++)
		solve(i);
	for(int i = 0; i < r; i++)
		cout << ans[i] << '\n';
	return 0;
}