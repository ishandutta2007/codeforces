#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif
	
	int n, ans = 0, base = 1; 
	cin >> n;

	while(n > 0){
		int val = n % 10;
		if(val == 7) ans += base;
		n /= 10;
		base += base;
	  if(n > 0) ans += base;  	
	}

	cout << ans + 1;

	return 0;
}