#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll n, m, a, b;
	cin >> n >> m >> a >> b;
	
	if (n % m == 0) {cout << 0; return 0;}
	
	ll x = n/m * m;
	ll y = (n/m + 1)*m;
	
	cout << min((y-n)*a, (n-x)*b);
	
	return 0;
}