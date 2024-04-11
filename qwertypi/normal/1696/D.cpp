#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int A[250001];
int dp[250001];
int mx[20][250001], mn[20][250001];

void build(int n){
	for(int i = 0; i < n; i++){
		mx[0][i] = mn[0][i] = A[i];
	}
	for(int j = 1; j < 20; j++){
		for(int i = 0; i <= n - (1 << j); i++){
			mx[j][i] = max(mx[j - 1][i], mx[j - 1][i + (1 << j - 1)]);
			mn[j][i] = min(mn[j - 1][i], mn[j - 1][i + (1 << j - 1)]);
		}
	}
}

int qry_mx(int l, int r){
	if(l > r) return -(1 << 30);
	int k = floor(log2(r - l + 1));
	return max(mx[k][l], mx[k][r - (1 << k) + 1]);
}

int qry_mn(int l, int r){
	if(l > r) return (1 << 30);
	int k = floor(log2(r - l + 1));
	return min(mn[k][l], mn[k][r - (1 << k) + 1]);
}

void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	build(n);
	dp[n - 1] = 0;
	fill(dp, dp + n - 1, (1 << 30));
	for(int i = n - 2; i >= 0; i--){
		int gr = i, lo = i;
		{
			int l = i + 1, r = n - 1;
			while(l != r){
				int m = (l + r + 1) / 2;
				if(qry_mn(i, m) >= A[i]){ // && qry_mx(i, m) <= A[m]
					l = m;
				}else{
					r = m - 1;
				}
			}
			gr = l;
		}
		{
			int l = i + 1, r = n - 1;
			while(l != r){
				int m = (l + r + 1) / 2;
				if(qry_mx(i, m) <= A[i]){ // && qry_mn(i, m) >= A[m]
					l = m;
				}else{
					r = m - 1;
				}
			}
			lo = l;
		}
		{
			int l = i + 1, r = gr;
			while(l != r){
				int m = (l + r + 1) / 2;
				if(qry_mx(m, gr) >= qry_mx(i, gr)){
					l = m;
				}else{
					r = m - 1;
				}
			}
			gr = l;
		}
		{
			int l = i + 1, r = lo;
			while(l != r){
				int m = (l + r + 1) / 2;
				if(qry_mn(m, lo) <= qry_mn(i, lo)){
					l = m;
				}else{
					r = m - 1;
				}
			}
			lo = l;
		}
		dp[i] = min(dp[gr] + 1, dp[lo] + 1);
	}
	cout << dp[0] << endl;
}
 
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}