#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll ;
typedef double db;
typedef pair<int, ll> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define int ll

const int N = (int)1e5 + 1;
const int K = 101;
const int MOD = 998244353;

int dp[N][K];
int a[N];

int cnt[N][K];

int qry(int t, int l, int r){
	return cnt[r][t] - cnt[l - 1][t];
}

signed main(){
	fastIO;
	int n, k, ln;
	cin >> n >> k >> ln;
	if(ln == 1){
		cout << 0 << "\n";
		return 0;
	}
	for(int i = 1 ; i <= n; i ++ ){
		cin >> a[i];
		if(a[i] == -1)
			a[i] = 0;
		cnt[i][a[i]] = 1;
		for(int j = 0 ; j <= k ; j ++ ){
			cnt[i][j] += cnt[i - 1][j];
		}
	}
	if(a[1] == 0){
		for(int i = 1; i <= k; i ++ )
			dp[1][i] = 1;
	}
	else{
		dp[1][a[1]] = 1;
	}
	int sum;
	int no;
	int bef;
	int check;
	for(int i = 2; i <= n; i ++ ){
		sum = 0;
		for(int j = 1; j <= k ; j ++ ){
			sum += dp[i - 1][j];
			sum %= MOD;
		}
		if(a[i] == 0){
			for(int j = 1; j <= k ; j ++ )
				dp[i][j] = sum;
		}
		else{
			dp[i][a[i]] = sum;
		}
		if(ln == i){
			for(int j = 1; j <= k ; j ++ ){
				if(qry(j, 1, i) + qry(0, 1, i) == ln){
					dp[i][j] += MOD - 1;
					dp[i][j] %= MOD ;
				}
			}
		}
		else if(i > ln){
			bef = 0;
			for(int j = 1; j <= k ; j ++ ){
				bef += dp[i - ln][j];
				bef %= MOD;
			}
			for(int j = 1; j <= k ; j ++ ){
				check = qry(j, i - ln + 1, i) + qry(0, i - ln + 1, i);
				if(check == ln){
					bef -= dp[i - ln][j];
					bef += MOD;
					bef %= MOD;
					dp[i][j] -= bef;
					dp[i][j] += MOD;
					dp[i][j] %= MOD;
					bef += dp[i - ln][j];
					bef += MOD;
					bef %= MOD;
				}
			}
		}
	}
	int ret = 0;
	for(int i = 1; i <= k ; i ++ ){
		ret += dp[n][i];
		ret %= MOD;
	}
	cout << ret << "\n";
	return 0;
}