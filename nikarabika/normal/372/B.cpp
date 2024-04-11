#include <bits/stdc++.h>

using namespace std;

const int maxn = 40 + 5;
char a[maxn][maxn];
int dp[maxn][maxn], ps[maxn][maxn][maxn][maxn];
int n, m, q;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	for(int i = 1; i <= n; i++){
		dp[i][m + 1] = m + 1;
		for(int j = m; j >= 1; j--)
			dp[i][j] = (a[i][j] == '1') * j + (a[i][j] == '0') * dp[i][j + 1];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			int Min = 1e5;
			for(int ii = i; ii <= n; ii++){
				Min = min(Min, dp[ii][j]);
				for(int jj = j; jj < Min; jj++)
					ps[i][j][ii][jj]++;
			}
		}
	}
	/*
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cout << i << ' ' << j << '\n';
			for(int ii = 1; ii <= n; ii++){
				for(int jj = 1; jj <= m; jj++)
					cout << ps[i][j][ii][jj] << ' ';
				cout << endl;
			}
		}
	}
	*/
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			for(int ii = i; ii <= n; ii++)
				for(int jj = j; jj <= m; jj++)
					ps[i][j][ii][jj] += ps[i][j][ii][jj - 1] + ps[i][j][ii - 1][jj] - ps[i][j][ii - 1][jj - 1];
	for(int i = n; i >= 1; i--)
		for(int j = m; j >= 1; j--)
			for(int ii = i; ii <= n; ii++)
				for(int jj = j; jj <= m; jj++)
					ps[i][j][ii][jj] += ps[i + 1][j][ii][jj] + ps[i][j + 1][ii][jj] - ps[i + 1][j + 1][ii][jj];
	
	while(q--){
		int i, j, ii, jj;
		cin >> i >> j >> ii >> jj;
		cout << ps[i][j][ii][jj] << '\n';
	}
	return 0;
}