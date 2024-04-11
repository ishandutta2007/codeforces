#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int k[100], h[100];
bool sig[100];
int solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> k[i];
	}
	for(int i = 0; i < n; i++){
		cin >> h[i];
	}
	fill(sig, sig + n, true);
	for(int i = n - 1; i >= 0; i--){
		for(int j = i + 1; j < n; j++){
			if(h[j] - h[i] >= k[j] - k[i]) sig[i] = false;
			if(k[j] - k[i] < h[j]) h[j] = max(h[j], h[i] + k[j] - k[i]), sig[i] = false;
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(sig[i]){
			ans += h[i] * (h[i] + 1) / 2;
		}
	}
	cout << ans << endl;
	return 0; // function not return can cause error?????
}
 
int32_t main(){
	int t;
	cin >> t;
	while(t--) solve();
}