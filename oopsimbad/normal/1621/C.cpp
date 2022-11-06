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
        int nx[n];
        F0R(i, n) nx[i] = -1;
        F0R(i, n) {
            if(nx[i] != -1) continue;
            vector<int> v;

            cout << "? " << i+1 << endl;
            int a; cin >> a; v.pb(a);

            while(true) {
                cout << "? " << i+1 << endl;
                cin >> a; v.pb(a);
                if(a == v[0]) break;
            }

            F0R(j, v.size()-1)
                nx[v[j]-1] = v[j+1];
        }

        cout << "!";
        F0R(i, n) cout << " " << nx[i];
        cout << endl;
    }
}