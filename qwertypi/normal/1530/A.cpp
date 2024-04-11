#include <bits/stdc++.h>

using namespace std;

void sub(){
	int n;
	cin >> n;
	int ans = 0;
	while(n){
		ans = max(ans, n % 10);
		n /= 10;
	}
	cout << ans << endl;
}
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
	return 0;
}