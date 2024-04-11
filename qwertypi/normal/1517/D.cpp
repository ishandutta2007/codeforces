#include <bits/stdc++.h>
#define int long long
using namespace std;

int A[501][501], B[501][501];
int v[501][501][4];
int dp[20][501][501];

int n, m, k;
	
inline bool in(int i, int j){
	return 0 <= i && i < n && 0 <= j && j < m;
}

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int32_t main(){
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m - 1; j++){
			cin >> A[i][j];
		}
	}
	
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < m; j++){
			cin >> B[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m - 1; j++){
			v[i][j][0] = A[i][j];
			v[i][j + 1][1] = A[i][j];
		}
	}
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < m; j++){
			v[i][j][2] = B[i][j];
			v[i + 1][j][3] = B[i][j];
		}
	}
	if(k % 2 == 1){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cout << -1 << ' ';
			}
			cout << endl;
		}
		return 0;
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int tr = 1; tr <= k / 2; tr++){
				dp[tr][i][j] = (1LL << 60);
			}
		}
	}
	for(int tr = 1; tr <= k / 2; tr++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				for(int dir = 0; dir < 4; dir++){
					if(!in(i + dx[dir], j + dy[dir])) continue;
					dp[tr][i + dx[dir]][j + dy[dir]] = min(dp[tr][i + dx[dir]][j + dy[dir]], dp[tr - 1][i][j] + v[i][j][dir]);
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << dp[k / 2][i][j] * 2 << ' ';
		}
		cout << endl;
	}
	cout << endl;
}