#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll n;
	cin >> n; 
	if (n == 1) {cout << 1; return 0;}
	vector<pair<ll, ll>> a(n);
	for (ll i = 0; i < n; i++) {
	      cin >> a[i].first >> a[i].second;
	}
	ll dist = a[0].first;
	ll ans = 2;
	for (ll i = 1; i < n-1; i++) {
	      if (a[i].first - a[i].second > dist) {
	            dist = a[i].first;
	            ans++;
	      } else if (a[i].first + a[i].second < a[i+1].first) {
	            dist = a[i].first + a[i].second;
	            ans++;
	      } else {dist = a[i].first;}
	}
	cout << ans;
	
	return 0;
}