#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	vector<ll> a(14);
	for (int i = 0; i < 14; i++) {
		cin>> a[i];
	}
	
	ll ans = 0;
	for (int i = 0; i < 14; i++) {
		if (a[i] == 0) continue;
		
		vector<ll> tmp = a;
		ll move = a[i]/14;
		ll leftover = a[i] % 14;
		tmp[i] = 0;
		
		for (int j = 0; j < 14; j++) {
			tmp[j] += move;
		}
		
		for (int j = (i+1)%14; leftover--; j = (j + 1)%14) {
			tmp[j]++;
		}
		
		ll s = 0;
		for (int j = 0; j < 14; j++) {
			if (tmp[j] % 2 == 0) {s += tmp[j];}
		}
		
		ans = max(ans, s);
	}
	cout << ans;
	
	return 0;
}