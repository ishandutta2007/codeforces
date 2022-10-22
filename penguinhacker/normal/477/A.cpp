#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll a, b;
	cin >> a >> b;
	//for (int i=1; i<b; ++i) { // i = x mod b
		// x = i*j*b + i
	//	for (int j=1; j<=a; ++j)
	//}
	const int M=1e9+7;
	ll ans=b*(b-1)/2%M*a%M;
	ans=(ans+(b*(b-1)/2%M)*(a*(a+1)/2%M)%M*b)%M;
	cout << ans;
	return 0;
}