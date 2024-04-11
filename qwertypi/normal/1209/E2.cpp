#pragma optimize("Ofast");
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first
#define se second

using namespace std;
 
typedef long long ll;
 
vpii sorted;
 
int cmp(pii A, pii B){
	return A.se > B.se;
}
 
int A[12][12];
int dp[13][4096];
int prec[12][4096];
int B[12][2000];
 
inline void Swap(int k, int n){
	int temp = A[0][k-1];
	for(int i=0;i<n-1;i++){
		A[i][k-1] = A[i+1][k-1];
	}
	A[n-1][k-1] = temp;
}
 
int getMax(int col, int mask, int n){
	int res = 0;
	for(int i=0;i<n;i++){
		int cnt = 0;
		int m = mask;
		for(int j=0;j<n;j++){
			if(m % 2)
				cnt += A[j][col];
			m /= 2;
		}
		res = max(res, cnt);
		Swap(col+1, n);
	}
	return res;
}
 
int f(int n){
	// O(n^3 2^n)
	for(int i = 0; i < n; i++){
		for(int j = 0; j < (1 << n); j++){
			prec[i][j] = getMax(i, j, n);
		}
	}
	fill(dp[0], dp[0]+(1 << n), 0);
	// O(n 3^n)
	for(int i=0;i<n;i++){
		for(int j=0;j<(1<<n);j++){
			dp[i+1][j] = dp[i][j];
		}
		for(int mask = 0; mask < (1 << n); mask++){
			for(int j = mask; j; j = (j - 1) & mask){
				dp[i+1][mask - j] = max(dp[i+1][mask - j], dp[i][mask] + prec[i][j]);
			}
		}
	}
	return dp[n][0];
}
 
void Solve(){
	sorted.clear();
	set<int> used;
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> B[i][j];
			sorted.emplace_back(pii{j, B[i][j]});
		}
	}
	sort(sorted.begin(), sorted.end(), cmp);
	for(auto i:sorted){
		if(used.size() >= n){
			break;
		}
		used.insert(i.fi);
	}
	vector<int> temp(used.begin(), used.end());
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			A[i][j] = temp.size() > j ? B[i][temp[j]] : 0;
		}
	}
	int ans = 0;
	cout << f(n) << endl;
}
 
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		Solve();
	}
	return 0;
}