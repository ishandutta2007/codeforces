/** neko_nyaa's very long and elaborated template **/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> ans(1000007, 0);

ll prod(ll n) {
	ll a = 1;
	while (n) {
		if (n % 10) {
			a *= n % 10;
		} 
		n /= 10;
		if (n == 0 && a > 9) {n = a; a = 1;} 
	}
	return a;
}

int main() {
	ios::sync_with_stdio(0);
	for (ll i = 0; i < 10; i++) {
		ans[i] = i;
	}
	for (ll i = 10; i < ans.size(); i++) {
		ll tmp = prod(i);
		ans[i] = ans[tmp];
	}
	vector<vector<ll>> que(1000007, vector<ll>(10, 0));
	for (ll i = 1; i < 1000007; i++) {
		for (ll j = 1; j < 10; j++) {
			que[i][j] = que[i-1][j];
			if (ans[i] == j) {que[i][j]++;}
		}
	}
	int q;
	cin >> q;
	while (q--) {
		ll l, r, k;
		cin >> l >> r >> k;
		cout << que[r][k] - que[l-1][k] << "\n";
	}
	
	return 0;
}