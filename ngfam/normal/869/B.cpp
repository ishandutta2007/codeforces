#include <bits/stdc++.h>

using namespace std;

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	long long a, b;
	cin >> a >> b;

	if(b - a > 10) cout << 0;
	else{
		long long ans = 1;
		for(long long x = a + 1; x <= b; ++x){
			ans *= x % 10;
		}
		cout << ans % 10;
	}

	return 0;
}