#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll n, c;
	cin >> n >> c;
	vector<ll> a(100001);
	vector<ll> pr(100001, 0);
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		pr[i] = pr[i-1] + a[i];
	}
 	if (c > n) {cout << pr[n]; return 0;}
 	
 	vector<ll> mini(100001);
 	multiset<ll> q;
 	for (ll i = 1; i <= c; i++) {
 		q.insert(a[i]);
 	}
 	auto it = q.begin();
 	mini[c] = *it;
 	for (ll i = c+1; i <= n; i++) {
 		q.insert(a[i]);
 		q.erase(q.find(a[i-c]));
 		it = q.begin();
 		mini[i] = *it;
 	}
 	
 	vector<ll> dp(n+1);
 	for (ll i = c; i <= n; i++) {
 		dp[i] = max(dp[i-1], dp[i-c] + mini[i]);
 	}
 	cout << pr[n] - dp[n];
 	
	return 0;
}