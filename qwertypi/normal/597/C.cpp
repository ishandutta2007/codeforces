#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int A[100001];
int dp[100001][11];
 
constexpr int MAXN = 100001;
struct BIT{
	int bit[MAXN];
	void init(){
		for(int i = 0; i < MAXN; i++){
			bit[i] = 0;
		}
	}
	
	void upd(int p, int x){
		while(p < MAXN){
			bit[p] += x;
			p += p & -p;
		}
	}
	int qry(int p){
		int res = 0;
		while(p > 0){
			res += bit[p];
			p -= p & -p;
		}
		return res;
	}
} bit;
 
int32_t main(){
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> A[i];
	}
	for(int i = 1; i <= n; i++){
		dp[i][0] = 1;
	}
	for(int j = 1; j <= k; j++){
		bit.init();
		for(int i = 1; i <= n; i++){
			dp[i][j] = bit.qry(A[i] - 1);
			bit.upd(A[i], dp[i][j - 1]);
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans += dp[i][k];
	}
	cout << ans << endl;
}