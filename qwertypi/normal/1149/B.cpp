#include <bits/stdc++.h>

using namespace std;


string s;
int nv[100002][26];

int a[3] = {0, 0, 0};
int b[3][251];
int dp[251][251][251];

int n, q;
void opp(int r, char c){
	b[r][a[r]++] = c - 'a';
	if(r == 0){
		for(int i = a[0]; i <= a[0]; i++){
			for(int j = 0; j <= a[1]; j++){
				for(int k = 0; k <= a[2]; k++){
					if(i > 0) dp[i][j][k] = min(dp[i][j][k], nv[dp[i - 1][j][k] + 1][b[0][i - 1]]);
					if(j > 0) dp[i][j][k] = min(dp[i][j][k], nv[dp[i][j - 1][k] + 1][b[1][j - 1]]);
					if(k > 0) dp[i][j][k] = min(dp[i][j][k], nv[dp[i][j][k - 1] + 1][b[2][k - 1]]);
				}
			}
		}
	}else if(r == 1){
		for(int i = 0; i <= a[0]; i++){
			for(int j = a[1]; j <= a[1]; j++){
				for(int k = 0; k <= a[2]; k++){
					if(i > 0) dp[i][j][k] = min(dp[i][j][k], nv[dp[i - 1][j][k] + 1][b[0][i - 1]]);
					if(j > 0) dp[i][j][k] = min(dp[i][j][k], nv[dp[i][j - 1][k] + 1][b[1][j - 1]]);
					if(k > 0) dp[i][j][k] = min(dp[i][j][k], nv[dp[i][j][k - 1] + 1][b[2][k - 1]]);
				}
			}
		}
	}else if(r == 2){
		for(int i = 0; i <= a[0]; i++){
			for(int j = 0; j <= a[1]; j++){
				for(int k = a[2]; k <= a[2]; k++){
					if(i > 0) dp[i][j][k] = min(dp[i][j][k], nv[dp[i - 1][j][k] + 1][b[0][i - 1]]);
					if(j > 0) dp[i][j][k] = min(dp[i][j][k], nv[dp[i][j - 1][k] + 1][b[1][j - 1]]);
					if(k > 0) dp[i][j][k] = min(dp[i][j][k], nv[dp[i][j][k - 1] + 1][b[2][k - 1]]);
				}
			}
		}
	}
	}

void opm(int r){
	if(r == 0){
		for(int i = a[0]; i <= a[0]; i++){
			for(int j = 0; j <= a[1]; j++){
				for(int k = 0; k <= a[2]; k++){
					dp[i][j][k] = n;
				}
			}
		}
	}else if(r == 1){
		for(int i = 0; i <= a[0]; i++){
			for(int j = a[1]; j <= a[1]; j++){
				for(int k = 0; k <= a[2]; k++){
					dp[i][j][k] = n;
				}
			}
		}
	}else if(r == 2){
		for(int i = 0; i <= a[0]; i++){
			for(int j = 0; j <= a[1]; j++){
				for(int k = a[2]; k <= a[2]; k++){
					dp[i][j][k] = n;
				}
			}
		}
	}
	a[r]--;
}

int main(){
	cin >> n >> q;
	cin >> s;
	for(int i = 0; i < 26; i++) nv[n + 1][i] = nv[n][i] = n;
	for(int i = n - 1; i >= 0; i--){
		for(int j = 0; j < 26; j++) nv[i][j] = nv[i + 1][j];
		nv[i][s[i] - 'a'] = i;
	}
	for(int i = 0; i <= 250; i++){
		for(int j = 0; j <= 250; j++){
			for(int k = 0; k <= 250; k++){
				dp[i][j][k] = n;
			}
		}
	}
	dp[0][0][0] = -1;
	for(int i = 0; i < q; i++){
		char c, d; int k;
		cin >> c >> k;
		k--;
		if(c == '+') cin >> d;
		if(c == '+'){
			opp(k, d); 
		}else{
			opm(k);
		}
		cout << (dp[a[0]][a[1]][a[2]] < n ? "YES" : "NO") << endl;
	}
}