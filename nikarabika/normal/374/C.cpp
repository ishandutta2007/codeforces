#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define L first
#define R second

typedef pair<int, int> pie;

const int maxn = 1e3 + 85 - 69;
int dp[maxn][maxn], mark[maxn][maxn];
char a[maxn][maxn];
int n, m, ans;
pie move[4] = {MP(0, 1), MP(0, -1), MP(1, 0), MP(-1, 0)};

bool isadj(pie x, pie y){
	switch(a[x.L][x.R]){
		case 'D':
			return a[y.L][y.R] == 'I';
		case 'I':
			return a[y.L][y.R] == 'M';
		case 'M':
			return a[y.L][y.R] == 'A';
		case 'A':
			return a[y.L][y.R] == 'D';
	}
}

void dfs(pie x){
	mark[x.L][x.R] = 1;
	dp[x.L][x.R] = 1;
	for(int i = 0; i < 4; i++){
		pie y = MP(x.L + move[i].L, x.R + move[i].R);
		if(y.L > 0 and y.L <= n and y.R > 0 and y.R <= m and isadj(x, y)){
			if(mark[y.L][y.R] == 0)
				dfs(y);
			if(mark[y.L][y.R] == 1){
				cout << "Poor Inna!" << endl;
				exit(0);
			}
			else
				dp[x.L][x.R] = max(dp[x.L][x.R], dp[y.L][y.R] + 1);
		}
	}
	mark[x.L][x.R] = 2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(!mark[i][j] and a[i][j] == 'D')
				dfs(MP(i, j));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(a[i][j] == 'D')
				ans = max(ans, dp[i][j]);
	if(ans / 4 == 0)
		cout << "Poor Dima!" << endl;
	else
		cout << ans / 4 << endl;
	return 0;
}