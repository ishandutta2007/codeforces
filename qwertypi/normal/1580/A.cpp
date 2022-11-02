#include <bits/stdc++.h>

using namespace std;

bool A[400][400];

int rows[401][401], cols[401][401];
int p2[401][401];

int check_row(int r, int c1, int c2){
	return c2 - c1 + 1 - (rows[r][c2 + 1] - rows[r][c1]);
}

int check_col(int c, int r1, int r2){
	return r2 - r1 + 1 - (cols[r2 + 1][c] - cols[r1][c]);
}

int check_rect(int r1, int r2, int c1, int c2){
	return p2[r2 + 1][c2 + 1] + p2[r1][c1] - p2[r2 + 1][c1] - p2[r1][c2 + 1];
}

int check(int r1, int r2, int c1, int c2){
	// cout << r1 << ' ' << r2 << ' ' << c1 << ' ' << c2 << endl;
	return check_row(r1, c1 + 1, c2 - 1) + check_row(r2, c1 + 1, c2 - 1) +
		   check_col(c1, r1 + 1, r2 - 1) + check_col(c2, r1 + 1, r2 - 1) +
		   check_rect(r1 + 1, r2 - 1, c1 + 1, c2 - 1);
}

int L[401], pL[401], R[401], pR[401];
void solve(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c; cin >> c;
			A[i][j] = c == '1';
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			p2[i + 1][j + 1] = p2[i][j + 1] + p2[i + 1][j] - p2[i][j] + A[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			rows[i][j + 1] = rows[i][j] + A[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cols[i + 1][j] = cols[i][j] + A[i][j];
		}
	}
	
	int ans = (1 << 30);
	for(int r1 = 0; r1 < n; r1++){
		for(int r2 = r1 + 4; r2 < n; r2++){
			for(int c1 = 0; c1 < m; c1++){
				for(int c2 = c1 + 3; c2 < m; c2++){
					if(check_rect(r1 + 1, r2 - 1, c1 + 1, c2 - 1) >= min(ans, 26) ||
					   check_row(r1, c1 + 1, c2 - 1) + check_row(r2, c1 + 1, c2 - 1) >= min(ans, 26)) break;
					ans = min(ans, check(r1, r2, c1, c2));
				}
			}
		} 
	}
	cout << ans << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}