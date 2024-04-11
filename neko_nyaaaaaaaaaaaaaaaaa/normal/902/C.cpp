#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	
	ll h;
	ll sum = 0;
	cin >> h;
	vector<ll> a(h+1);
	ll ans;
	bool ambi = 0;
	cin >> a[0];
	sum = a[0];
	for (ll i = 1; i <= h; i++) {
		cin >> a[i];
		if (a[i] > 1 && a[i-1] > 1) {ambi = 1; ans = sum;}
		sum += a[i];
	}
	
	if (!ambi) {cout << "perfect"; return 0;}
	cout << "ambiguous\n";
	
	vector<ll> anss(sum);
	vector<ll> tmp = a;
	ll cur = 0;
	ll j = 0;
	for (ll i = 0; i < sum; i++) {
		if (a[j] == 0) {
			cur = i;
			j++;
		}
		anss[i] = cur;
		a[j]--;
	}
	for (ll i = 0; i < sum; i++) {
		cout << anss[i] << " ";
	}
	cout << endl;
	anss[ans]--;
	for (ll i = 0; i < sum; i++) {
		cout << anss[i] << " ";
	}
	
	
	return 0;
}