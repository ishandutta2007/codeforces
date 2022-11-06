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
        int ll = 2147483647, rr = 0;
        int minc = 0, maxc = 0;
        int samec = 0;
        bool same = false;
        while(n--) {
            int l, r, c; cin >> l >> r >> c;

            bool isl = l < ll;
            bool isr = r > rr;
        
            if(isl) {
                ll = l;
                minc = c;
                same = false;
            }
            if(isr) {
                rr = r;
                maxc = c;
                same = false;
            }

            if(l == ll && r == rr && (same ? samec : minc + maxc) > c) {
                same = true;
                samec = c;
                minc = min(minc, c);
                maxc = min(maxc, c);
            }
            if(l == ll) {
                minc = min(minc, c);
                if(same && samec > minc+maxc)
                    same = false;
            }
            if(r == rr) {
                maxc = min(maxc, c);
                if(same && samec > minc+maxc)
                    same = false;
            }
            cout << (same ? samec : minc + maxc) << endl;
        }
    }
}