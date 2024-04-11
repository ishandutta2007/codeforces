#include <bits/stdc++.h>
#define int long long
// !!!!!!!!!!!
// Last Div 2!
// Hope so.
// !!!!!!!!!!!
 
 
using namespace std;
 
void solve(){
	int n, B, x, y;
	cin >> n >> B >> x >> y;
	int ans = 0;
	int c = 0;
	for(int i = 1; i <= n; i++){
		if(c + x <= B) c += x;
		else c -= y;
		ans += c;
	}
	cout << ans << endl;
}
 
int32_t main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}