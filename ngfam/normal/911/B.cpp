#include <bits/stdc++.h>

using namespace std;

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	int n, a, b;

	cin >> n >> a >> b;

	int ans = 0;

	for(int i = 1; i < n; ++i){
		if(a < i) break;
		if(b < n - i) continue;

		ans = max(ans, min(a / i, b / (n - i)));
	}

	cout << ans;

	return 0;
}