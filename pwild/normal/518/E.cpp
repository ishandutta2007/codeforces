#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

const ll oo = 0x3f3f3f3f3f3f3f3f;

#define sz(c) ll((c).size())
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define pb push_back

ll a[100010];

int main() {
	ios_base::sync_with_stdio(false);

	ll n, k; cin >> n >> k;
	FOR(i,0,n) {
		string s; cin >> s;
		if (s[0] == '?') {
			a[i] = oo;
		} else {
			stringstream ss(s);
			ss >> a[i];
		}
	}
	
	FOR(i,0,k) {
		vi b;
		b.pb(-1e10);
		for (ll j = i; j < n; j += k) {
			b.pb(a[j]);
		}
		b.pb(1e10);
		ll l = 0;
		while (l < sz(b)-1) {
			ll r = l+1;
			while (b[r] == oo) r++;
			if (r-l > b[r]-b[l]) {
				cout << "Incorrect sequence" << endl;
				return 0;
			}
			if (r-l >= 2) {
				ll mid = (l+r)/2;
				ll minv = b[l] + (r-l)/2, maxv = b[r] - (r-l+1)/2;
				if (minv > 0) b[mid] = minv;
				else if (maxv < 0) b[mid] = maxv;
				else b[mid] = 0;
				FOR(i,l+1,r) {
					b[i] = b[mid] + i - mid;
				}
			}
			l = r;
		}
		FOR(j,0,sz(b)-2) {
			a[i+k*j] = b[j+1];
		}
	}
	FOR(i,0,n) {
		if (i) cout << " ";
		cout << a[i];
	}
	cout << endl;


	
}