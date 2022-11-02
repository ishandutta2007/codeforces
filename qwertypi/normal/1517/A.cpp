#include <bits/stdc++.h>

using namespace std;

void sub(){
	long long n;
	cin >> n;
	if(n % 2050 != 0) { cout << -1 << endl; return; }
	long long r = n / 2050;
	int ans = 0;
	while(r != 0){
		if(r % 10){
			ans += r % 10;
		}
		r /= 10;
	}
	cout << ans << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}