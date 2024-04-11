#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;




 
 
int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n, q;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
 
	
    cin >> n;
    vector<ll> a(n + 1);
    for(i = 1; i <= n; i++) {
    	cin >> a[i];
    }

    vector<ll> diff(n);
    ll suma = 0, sumb = 0;
    for(i = 1; i < n; i++) {
    	diff[i] = a[i + 1] - a[i];
    	suma += max(diff[i], 0LL);
    	sumb += max(-diff[i], 0LL);
    }

    auto upd = [&](int pos, int sign) {
    	suma += sign * max(diff[pos], 0LL);
    	sumb += sign * max(-diff[pos], 0LL);
    };

    auto get = [&](ll suma, ll sumb) -> ll {
    	// x
    	// a[1] - x

    	ll x = (a[1] - suma) / 2;
    	return max(x + suma, a[1] - x);

    	// max(x + suma, a[1] - x)
    	// x + suma == a[1] - x
    	// 2 * x == a[1] - suma
    };

    cout << get(suma, sumb) << '\n';

    cin >> q;
    while(q--) {
    	int l, r, x;
    	cin >> l >> r >> x;

    	if(l == 1) {
    		a[1] += x;
    	}

    	if(l > 1) {
    		upd(l - 1, -1);
    		diff[l - 1] += x;
    		upd(l - 1, 1);
    	}
    	if(r < n) {
    		upd(r, -1);
    		diff[r] -= x;
    		upd(r, 1);
    	}

    	cout << get(suma, sumb) << "\n";
    }

 
    return 0;
}