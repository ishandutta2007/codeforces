#include <bits/stdc++.h>

using namespace std;

const int maxn = 25 + 2;
char a[maxn][maxn];
int dp[maxn][maxn];
int Max, n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	for(int i = 1; i <= n; i++){
		dp[i][m + 1] = m + 1;
		for(int j = m; j >= 1; j--)
			dp[i][j] = (a[i][j] != '1') * dp[i][j + 1] + (a[i][j] == '1') * j;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			for(int ii = i; ii <= n; ii++){
				for(int jj = j; jj <= m; jj++){
					if(ii - i + jj - j + 2 <= Max)
						continue;
					bool x = true;
					for(int iii = i; iii <= ii; iii++){
						if(dp[iii][j] <= jj){
							x = false;
							break;
						}
					}
					if(x)
						Max = ii + jj - i - j + 2;
				}
			}
		}
	}
	cout << Max * 2 << endl;
	return 0;
}