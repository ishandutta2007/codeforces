#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	int a, b, c = 0; cin >> a >> b;

	int ans = 0;

	while(a > 0){
		++ans;
		--a;
		++c;
		if(c >= b){
			++a;
			c -= b;
		}			
	}	

	cout << ans;
}