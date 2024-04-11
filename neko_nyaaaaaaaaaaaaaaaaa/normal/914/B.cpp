#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll n, x;
	cin >> n;
	vector<ll> a(100001, 0);
	for (ll i = 0; i < n; i++) {
	      cin >> x;
	      a[x]++;
	}
	for (ll i = 100000; i >= 0; i--) {
	      if (a[i] % 2) {cout << "Conan"; return 0;}
	}
	cout << "Agasa";
	
	return 0;
}