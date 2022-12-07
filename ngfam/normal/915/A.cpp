#include <bits/stdc++.h>

using namespace std;

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	int k, n, ans = 1e9;

	cin >> n >> k;
	while(n--){
		int x;
		cin >> x;

		if(k % x == 0) ans = min(ans, k / x);
	}

	cout << ans;

	return 0;
}