#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin(),(x).end())
#define len(x) ((ll)(x).size())

const int MOD = 998244353;
const int N = (int)1e5 + 1;
const int M = 201;

int dp[N][M][2];
int opt[M][2];

void add(int &a, int b){
	a += b;
	if(a >= MOD)
		a -= MOD;
}

int ask(int dim ,int l, int r){
	if(r < l)
		return 0;
	return (opt[r][dim] - opt[l - 1][dim] + MOD) % MOD;
}

int main(){
	fastIO;
	int n;
	cin >> n;
	int a;
	cin >> a;
	if(a == -1){
		for(int j = 1; j < M; j ++ ){
			dp[1][j][1] ++ ;
		}
	}
	else{
		dp[1][a][1] ++ ;
	}
	for(int z = 0; z < M; z ++ )
		opt[z][0] = dp[1][z][0], opt[z][1] = dp[1][z][1];
	for(int z = 1; z < M; z ++ ){
		opt[z][1] += opt[z - 1][1];
		opt[z][1] %= MOD;
		opt[z][0] += opt[z - 1][0];
		opt[z][0] %= MOD;
	}
	int y;
	for(int i = 2; i <= n;i ++ ){
		cin >> a;
		if(a == -1){
			// zero state
			for(int z = 1; z < M; z ++ ){
				add(dp[i][z][0], ask(0, z, M - 1));
				add(dp[i][z][0], dp[i - 1][z][1]);
			}
			// one state
			for(int z = 1; z < M; z ++ ){
				add(dp[i][z][1], ask(0, 1, z - 1));
				add(dp[i][z][1], ask(1, 1, z - 1));
			}
		}
		else{
			// zero state
			for(int z = a; z <= a; z ++ ){
				add(dp[i][z][0], ask(0, z, M - 1));
				add(dp[i][z][0], dp[i - 1][z][1]);
			}
			// one state
			for(int z = a; z <= a; z ++ ){
				add(dp[i][z][1], ask(0, 1, z - 1));
				add(dp[i][z][1], ask(1, 1, z - 1));
			}
		}
		for(int z = 0; z < M; z ++ )
			opt[z][0] = dp[i][z][0], opt[z][1] = dp[i][z][1];
		for(int z = 1; z < M; z ++ ){
			opt[z][1] += opt[z - 1][1];
			opt[z][1] %= MOD;
			opt[z][0] += opt[z - 1][0];
			opt[z][0] %= MOD;
		}
	}
	int ans = 0;
	for(int z = 1; z < M; z ++ ){
		add(ans, dp[n][z][0]);
	}
	cout << ans << "\n";
	return 0;
}