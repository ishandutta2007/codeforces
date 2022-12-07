#include <bits/stdc++.h>

using namespace std;

bool check(int u, int v){
	if(u <= 0 || u > v) return false;
	return true;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif
	
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;

	long long ans = 0;

	for(int i = 1; i <= n; ++i){
		int val2 = i + c - b;
		int val3 = val2 + d - a;
		int val4 = val3 + b - c;
		
		if(check(val2, n) && check(val3, n) && check(val4, n)){
		 	ans += n;
		 //	cout << i << " " << val2 << " " << val3 << " " << val4 << endl;
		}
	}

	cout << ans;
	return 0;
}