#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
void sub(){
	int p, a, b, c;
	cin >> p >> a >> b >> c;
	int ans = 1LL << 62;
	ans = min(ans, (p + a - 1) / a * a);
	ans = min(ans, (p + b - 1) / b * b);
	ans = min(ans, (p + c - 1) / c * c);
	cout << ans - p << endl;
}
 
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}