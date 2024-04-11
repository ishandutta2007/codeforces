#include <bits/stdc++.h>
#define int long long
using namespace std;

int A[200001];
void solve(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> A[i]; A[n] = 0;
	int ans = 0; int r = max(0LL, k - n) * n; k = min(k, n); 
	int s = 0; for(int i = 0; i < k; i++) s += A[i];
	for(int i = 0; i <= n - k; i++){
		ans = max(ans, s);
		s += A[i + k] - A[i];
	}
	cout << r + ans + k * (k - 1) / 2 << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}