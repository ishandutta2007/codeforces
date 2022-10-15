#include <bits/stdc++.h>
using namespace std;
 
 
typedef long long ll;
typedef long double ld;
 
const ll INF = 1e18;
 
struct Item {
 
	ll V;
	ll cost;
	long double cl;
 
};
 
int main() {
	ll n, L;
	cin >> n >> L;
	vector<Item> a;
	for(ll i = 1; i <= n; i++) {
		long double val;
		cin >> val;
		ll V = (1 << (i - 1));
		a.push_back({V, (ll)val, val / (long double)V});
	}
	sort(a.begin(), a.end(), [] (const Item &left, const Item &right) {
		if(left.cl != right.cl) {
			return left.cl < right.cl;
		} else {
			return left.V > right.V;
		}
	});
	ll ans = 0;

	ll realAns = INF;
	for(int i = 0; i < (int)a.size(); i++) {
		if(a[i].V <= L) {

			ll times = (L / a[i].V);
			ans += times * a[i].cost;
			L -= a[i].V * times;
			realAns = min(realAns, ans + a[i].cost);
		} else {
			realAns = min(realAns, ans + a[i].cost);
		}
		if(L <= 0) {
			realAns = min(realAns, ans);
			break;
		}
	}
	cout << realAns;
}