#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define smin(x, y) (x) = min((x), (y))

LL dp[31][31][51];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 1; i <= 30; i++){
		for(int j = 1; j <= 30; j++){
			for(int k = 1; k <= min(i * j, 50); k++){
				if(k == i * j){
					dp[i][j][k] = 0;
					continue;
				}
				dp[i][j][k] = 1LL * 1000000 * 1000000 * 1000000;
				for(int ii = 1; ii + 1 <= i; ii++){
					for(int kk = 0; kk <= min(k, ii * j); kk++){
						if(k - kk > (i - ii) * j)
							continue;
						smin(dp[i][j][k], dp[ii][j][kk] + dp[i - ii][j][k - kk] + j * j);
					}
				}
				for(int jj = 1; jj + 1 <= j; jj++){
					for(int kk = 0; kk <= min(k, i * jj); kk++){
						if(k - kk > i * (j - jj))
							continue;
						smin(dp[i][j][k], dp[i][jj][kk] + dp[i][j - jj][k - kk] + i * i);
					}
				}
			}
		}
	}
	int t;
	cin >> t;
	while(t--){
		int fi, se, th;
		cin >> fi >> se >> th;
		cout << dp[fi][se][th] << '\n';
	}
	return 0;
}