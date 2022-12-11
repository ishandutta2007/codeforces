#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<ll, ll> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1005;
const int K = 105;

int dp[N][K][2];

int mod;
void add(int &a, int b){
	a = (a + b) % mod;
}

int main(){
	fastIO;
	int n, k;
	cin >> n >> k >> mod;
	dp[0][0][0] = 1;
	int nx_mod;
	int pw = 1;
	int nz;
	for(int i = 0 ;i < n ; i ++ ){
		for(int j = 0 ; j < k; j ++ ){
			for(int z = 0; z < 2; z ++ ){
				for(int nx_dig = (i == n - 1); nx_dig < 10; nx_dig ++ ){
					nx_mod = (nx_dig * pw + j) % k;
					nz = z | (nx_dig > 0 && nx_mod == 0);
					add(dp[i + 1][nx_mod][nz], dp[i][j][z]); 
				}
			}
		}
		pw *= 10;
		pw %= k;
	}
	int answ = 0;
	for(int j = 0 ; j < k ; j ++ )
		add(answ, dp[n][j][1]);
	cout << answ;
	return 0;
}