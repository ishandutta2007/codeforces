#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 16;
const int MX = N * N + 5;

int dp[1 << N][MX]; 


int main(){
	fastIO;
	int n;
	cin >> n;
	int a[n], b[n];
	int col[n];
	char d;
	for(int i = 0 ; i < n; i ++ ){
		cin >> d >> a[i] >> b[i];
		col[i] = (d == 'R');
	}
	for(int i = 0 ; i < (1 << N) ; i ++  ){
		for(int j = 0 ;j < MX ; j ++ )
			dp[i][j] = -1;
	}
	dp[0][0] = 0;
	int reds, blues;
	int nrd, nbl;
	for(int i = 0 ; i < (1 << N); i ++ ){
		reds = 0, blues = 0;
		for(int j = 0 ; j < n ; j ++ ){
			if(i & (1 << j)){
				if(col[j] == 1)
					reds ++  ;
				else
					blues ++ ;
			}
		}
		for(int j = 0 ; j < MX ; j ++ ){
			if(dp[i][j] == -1)
				continue;
			for(int nx = 0; nx < n ; nx ++ ){
				if(i & (1 << nx))
					continue;
				nrd = j + min(reds, a[nx]);
				nbl = dp[i][j] + min(blues, b[nx]);
				dp[i | (1 << nx)][nrd] = max(dp[i | (1 << nx)][nrd], nbl);
			}
		}
	}
	int ta = 0, tb = 0;
	for(int i = 0 ; i < n ; i ++ )
		ta += a[i], tb += b[i];
	int ans = max(ta,  tb);
	for(int i = 0 ; i < (1 << n); i ++ ){
		for(int j = 0 ; j < MX; j ++ ){
			if(dp[i][j] != -1){
				ans = min(ans, max(ta - j, tb - dp[i][j]));
			}
		}
	}
	cout << ans + n << "\n";
	return 0;
}