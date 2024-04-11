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
    int asdf; cin >> asdf;
    while(asdf--) {
        int n; cin >> n;
        vector<int> v(n);
        vector<bool> b(n);
        F0R(i, n) cin >> v[i];

        bool ok = true;
        FORd(a, 1, n+1) {
            bool found = false;
            F0R(i, n) {
                if(b[i]) continue;
                int x = v[i];
                while(x != 0) {
                    if(x == a) found = true;
                    x >>= 1;
                }
                if(found) {
                    b[i] = true;
                    break;
                }
            }

            ok &= found;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}