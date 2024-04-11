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
        int r, c; cin >> r >> c;
        char mat[r][r];
        F0R(i, r)
            F0R(j, r) mat[i][j] = '.';
        if(c * 2 - 1 <= r) {
            for(int i = 0; i < 2*c; i += 2)
                mat[i][i] = 'R';

            F0R(i, r) {
                F0R(j, r) cout << mat[i][j];
                 cout << endl;
            }
        }
        else cout << -1 << endl;
    }
}