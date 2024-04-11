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
        string s; cin >> s;
        cout << s[0];
        bool found = false;
        while(n-- > 3) {
            string t; cin >> t;
            if(t[0] != s[1]) {
                cout << s[1];
                found = true;
            }
            cout << t[0];
            s = t;
        }
        cout << s[1];
        if(!found) cout << 'a';
        cout << '\n';
    }

	return 0;
}