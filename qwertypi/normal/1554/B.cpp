#include <bits/stdc++.h>
#define int long long
#define inf (1LL << 60)
using namespace std;

int A[100001];
int dp[1 << 18], dp2[1 << 18];
void upd(int idx, int val){
	// cout << "upd: " << idx << ' ' << val << endl;
	if(dp[idx] == val || dp2[idx] == val) return;
	if(dp[idx] < val){
		dp2[idx] = dp[idx];
		dp[idx] = val;
	}else if(dp2[idx] < val){
		dp2[idx] = val;
	}
}

int qry(int idx, int except){
	// cout << "qry: " << idx << ' ' << except << endl;
	if(dp[idx] == except && dp2[idx] == except && except != 0) assert(0 == 1);
	return (dp[idx] == except) ? dp2[idx] : dp[idx];
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int N, k;
		cin >> N >> k;
		int n = N, d = 0;
		while(n) n /= 2, d++;
		d++;
		fill(dp, dp + (1LL << d), -inf);
		fill(dp2, dp2 + (1LL << d), -inf);
		for(int i = 1; i <= N; i++){
			cin >> A[i];
		}
		int ans = -(1LL << 60);
		for(int i = 1; i <= N; i++){
			if(dp[A[i]] != -inf) ans = max(ans, i * dp[A[i]] - k * A[i]);
			upd(A[i], i);
		}
		for(int i = 0; i < (1LL << d); i++){
			for(int j = 0; j < d; j++){
				if(i & (1LL << j)){
					if(dp[i ^ (1LL << j)] != -inf){
						assert(dp[i ^ (1LL << j)] != qry(i, dp[i ^ (1LL << j)]));
						if(qry(i, dp[i ^ (1LL << j)]) != -inf) ans = max(ans, dp[i ^ (1LL << j)] * qry(i, dp[i ^ (1LL << j)]) - k * i);
						upd(i, dp[i ^ (1LL << j)]);
					}
					if(dp2[i ^ (1LL << j)] != -inf){
						assert(dp2[i ^ (1LL << j)] != qry(i, dp2[i ^ (1LL << j)]));
						if(qry(i, dp2[i ^ (1LL << j)]) != -inf) ans = max(ans, dp2[i ^ (1LL << j)] * qry(i, dp2[i ^ (1LL << j)]) - k * i);
						upd(i, dp2[i ^ (1LL << j)]);
					}
				}
			}
		} 
		cout << ans << endl;
	}
}