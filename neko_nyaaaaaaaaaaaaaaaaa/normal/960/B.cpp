#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll n, k1, k2;
	cin >> n >> k1 >> k2;
	vector<ll> a(n), b(n);
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	ll k = k1+k2;
	
	priority_queue<ll> q;
	for (int i = 0; i < n; i++) {
		q.push(abs(a[i] - b[i]));
	}
	while (q.size() && k > 0 && q.top() > 0) {
		ll tmp = q.top();
		tmp--;
		q.pop();
		q.push(tmp);
		k--;
	}
	
	if (k == 0) {
		ll ans = 0;
		while (q.size()) {
			ans += q.top()*q.top();
			q.pop();
		}
		cout << ans;
	} else {
		if (k % 2) {cout << 1;}
		else {cout << 0;}
	}
	
	return 0;
}