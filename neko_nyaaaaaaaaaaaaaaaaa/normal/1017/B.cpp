#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	string a, b;
	cin >> a >> b;
	
	ll zo = 0, zz = 0, oo = 0, oz = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == '1' && b[i] == '1') oo++;
		if (a[i] == '0' && b[i] == '1') zo++;
		if (a[i] == '1' && b[i] == '0') oz++;
		if (a[i] == '0' && b[i] == '0') zz++;
	}
	
	ll ans = oo*zz;
	ans += zo*oz;
	ans += zz*oz;
	
	cout << ans;
	
	return 0;
}