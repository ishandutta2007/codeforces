#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

ll f(ll n) {
	if (n < 10) return n;
	ll ans = 1;
	while (n > 0) {
		ans *= max(n % 10, 1ll);
		n /= 10;
	}
	return ans;
}

ll g(ll n) {
	if (n < 10) return n;
	else return g(f(n));
}

vector<ll> count(10, 0);
vector<ll> d[2000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	d[0] = count;
	for(ll i = 1; i <= 2e6; ++i) {
		ll k = g(i);
		if (k < 10) ++count[k];
		d[i] = count;
	}
	for (ll i = 0; i < n; ++i) {
		ll l, r, k;
		cin >> l >> r >> k;
		cout << d[r][k] - d[l - 1][k] << '\n';
	}
	//system("pause");
    return 0;
}