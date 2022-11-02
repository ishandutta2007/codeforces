#include <bits/stdc++.h>
#define int long long
using namespace std;

int diff[500001], prec[500002];

int32_t main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	for(int i = 0; i <= 500000; i++){
		int l = max(c, b + i), r = min(d, c + i);
		diff[i] = max(0LL, r - l + 1);
	}
	for(int i = 0; i <= 500000; i++){
		prec[i + 1] = prec[i] + diff[i];
	}
	int ans = 0;
	for(int i = a; i <= b; i++){
		ans += prec[i];
	}
	cout << ans << endl;
}