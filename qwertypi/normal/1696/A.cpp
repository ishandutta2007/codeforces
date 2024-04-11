#include <bits/stdc++.h>

using namespace std;

int A[2001];
void solve(){
	int n, z;
	cin >> n >> z;
	for(int i = 0; i < n; i++) cin >> A[i];
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans = max(ans, z | A[i]);
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