#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	int n; cin >> n;

	int ans = 0;

	for(int i = 1; i <= n + 1; ++i){
	 	if((i * (i + 1)) / 2 > n){
	 		ans = i - 1;
	 		break;
	 	} 
	}

	cout << ans << endl;
	for(int i = 1; i < ans; ++i){
		cout << i << " ";
	}
	cout << n - (ans * (ans - 1)) / 2;
}