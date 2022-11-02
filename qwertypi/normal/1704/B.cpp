#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[200001];
void solve(){
	int n, x;
	cin >> n >> x;
	for(int i = 0; i < n; i++) cin >> a[i];
	int cur_l = (1LL << 60), cur_r = -(1LL << 60);
	int ans = 0;
	for(int i = 0; i < n; i++){
		cur_l = min(cur_l, a[i]);
		cur_r = max(cur_r, a[i]);
		if(cur_r - cur_l > x * 2){
			ans++;
			cur_l = a[i];
			cur_r = a[i];
		}
	}
	cout << ans << '\n';
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}