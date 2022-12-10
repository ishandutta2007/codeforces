#include <bits/stdc++.h>

using namespace std;

int f(int a, int b){
	if(b == 1)
		return a - 1;
	return a / b + f(b, a % b);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int ans = n;
	for(int i = 1; i <= n; i++){
		if(__gcd(n, i) != 1)
			continue;
		ans = min(ans, f(n, i));
	}
	cout << ans << endl;
	return 0;
}