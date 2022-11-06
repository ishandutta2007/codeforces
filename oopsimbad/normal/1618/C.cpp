#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define f first
#define s second
#define mp make_pair
#define pb push_back

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int asdf; cin >> asdf;
    while(asdf--) {
        int n; cin >> n;
        vector<ll> v(n);
        F0R(i, n) cin >> v[i];
        ll gcd1 = v[0], gcd2 = v[1];
        F0R(i, n)
            if(i % 2) gcd2 = __gcd(gcd2, v[i]);
            else gcd1 = __gcd(gcd1, v[i]);
        bool ok1 = true, ok2 = true;
        F0R(i, n)
            if(i % 2) ok1 &= (v[i] % gcd1) != 0;
            else ok2 &= (v[i] % gcd2) != 0;
        if(ok1) cout << gcd1 << '\n';
        else if(ok2) cout << gcd2 << '\n';
        else cout << "0\n";
    }
	return 0;
}