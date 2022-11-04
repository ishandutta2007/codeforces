#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-10
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

ll n;

bool is_prime(ll x) {
    for (ll i = 2; i * i <= n; i++) {
    	if (n % i == 0) {
    		return false;
    	}
    }

    return true;
}

bool not_divides(ll x, const vector<ll> &bad) {
	for (ll y : bad) {
		if (x % y == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
    ios::sync_with_stdio(false);

    vector<ll> dividers;
    vector<ll> bad;

    cin >> n;
    for (ll i = 1; i * i <= n; i++) {
    	if (i * i == n) {
    		dividers.pb(i);
    		bad.pb(i * i);
    	} else {
    		if (n % i == 0) {
    			ll a = i;
    			ll b = n / a;
				dividers.pb(a);
				if (a != 1) {
					bad.pb(a * a);
				}
				dividers.pb(b);
				if (b != 1) {
					bad.pb(b * b);
				}
    		}
    	}
    }

    ll ans = 1;
    for (ll x : dividers) {
    	if (not_divides(x, bad)) {
    		ans = max(ans, x);
    	}
    }

    cout << ans << endl;

    return 0;
}