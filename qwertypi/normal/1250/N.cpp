#include <bits/stdc++.h>
#define MAXN 1000001
using namespace std;
 
int A[MAXN];
int mn[MAXN], mx[MAXN];
struct BIT{
	int bit[MAXN] = {0}; // 1 base
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
	
	int qry_pos(int v){
		int res = 0, idx = 0;
		for(int i = __lg(MAXN); i >= 0; i--){
			if(idx + (1 << i) < MAXN && res + bit[idx + (1 << i)] < v){
				res += bit[idx + (1 << i)];
				idx += (1 << i);
			}
		}
		return idx + 1;
	}
} bit;
 
int dp[1000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, x;
	cin >> n >> x;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	mn[n] = (1 << 30);
	for(int i = n - 1; i >= 0; i--){
		mn[i] = min(mn[i + 1], A[i]);
	}
	for(int i = n - 1; i >= 0; i--){
		int val = bit.qry(A[i] - 1);
		mx[i] = (val ? bit.qry_pos(val) : 0);
		bit.upd(A[i], 1);
	}
	
	for(int i = 0; i < n; i++){
		if(A[i] == 1 || mx[i] == 0) continue;
		dp[A[i] + 1] = x + 1;
		dp[mn[i + 1] + 1] = max(dp[mn[i + 1] + 1], A[i]);
		dp[0] = max(dp[0], mx[i]);
	}
	
	for(int i = 0; i < x; i++){
		dp[i + 1] = max(i + 1, dp[i + 1]); 
		dp[i + 1] = max(dp[i], dp[i + 1]);
	}
	
	long long ans = 0;
	for(int i = 1; i <= x; i++){
		ans += max(0, x - dp[i] + 1);
	}
	cout << ans << endl;
}