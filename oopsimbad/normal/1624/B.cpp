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
        int a, b, c; cin >> a >> b >> c;
        int d = b-(c-b);
        int e = (c-a)%2 == 0 ? a + (c-a) / 2 : -1;
        int f = b+(b-a);

        bool ok = false;
        if(d/a * a == d && d > 0) ok = true;
        if(e/b * b == e && e > 0) ok = true;
        if(f/c * c == f && f > 0) ok = true;

        cout << (ok ? "YES" : "NO") << endl;
    }
}