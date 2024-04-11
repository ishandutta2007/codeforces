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

const int maxn = 1e5 + 85 - 69;
const int maxsq = 320;
char a[maxn][10];
int dx[256], dy[256];
pii dp[maxn][10];
int mark[maxn][10];
int n, m, q;

pii dfs(int r, int c, int id){
	if(r < id * maxsq or r >= min(n, (id + 1) * maxsq) or c < 0 or c >= m)
		return MP(r, c);
	if(mark[r][c] == 1)
		return MP(-1, -1);
	if(mark[r][c] == 2)
		return dp[r][c];
	mark[r][c] = 1;
	dp[r][c] = dfs(r + dx[a[r][c]], c + dy[a[r][c]], id);
	mark[r][c] = 2;
	return dp[r][c];
}

pii get_ans(int r, int c){
	while(r >= 0 and r < n and c >= 0 and c < m){
		int x = r, y = c;
		r = dp[x][y].L, c = dp[x][y].R;
	}
	return MP(r, c);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	dy['>'] = 1;
	dx['^'] = dy['<'] = -1;
	cin >> n >> m >> q;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	for(int i = 0; i < n; i += maxsq)
		for(int ii = i; ii < min(n, i + maxsq); ii++)
			for(int jj = 0; jj < m; jj++)
				if(!mark[ii][jj])
					dfs(ii, jj, i / maxsq);
	while(q--){
		char ty;
		cin >> ty;
		if(ty == 'A'){
			int fi, se;
			cin >> fi >> se;
			fi--, se--;
			pii ret = get_ans(fi, se);
			if(ret == MP(-1, -1))
				cout << "-1 -1" << '\n';
			else
				cout << ret.L + 1 << ' ' << ret.R + 1 << '\n';
		}
		else{
			int fi, se;
			char c;
			cin >> fi >> se >> c;
			fi--, se--;
			a[fi][se] = c;
			int id = fi / maxsq;
			for(int i = id * maxsq; i < min((id + 1) * maxsq, n); i++)
				for(int j = 0; j < m; j++)
					mark[i][j] = false;
			for(int i = id * maxsq; i < min((id + 1) * maxsq, n); i++)
				for(int j = 0; j < m; j++)
					if(!mark[i][j])
						dfs(i, j, id);
		}
	}
	cerr << "Jan-e Madaret Accept sho :))" << '\n';
	return 0;
}