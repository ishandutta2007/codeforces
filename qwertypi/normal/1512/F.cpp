#include <bits/stdc++.h>
#define int long long
using namespace std;

int A[200001], B[200001];
int dp[200001][2];
void solve(){
	int n, c;
	cin >> n >> c;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 0; i < n - 1; i++){
		cin >> B[i];
	}
	int money = 0, d = 0;
	int ans = (1LL << 60);
	for(int i = 0; i < n; i++){
		ans = min(ans, d + max((c - money + A[i] - 1) / A[i], 0LL));
		// cout << ans << ' ' << money << ' ' << d << endl;
		if(i != n - 1){
			int dd = max((B[i] - money + A[i] - 1) / A[i], 0LL);
			d += dd + 1;
			money = money + dd * A[i] - B[i];
		}
	}
	cout << ans << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}