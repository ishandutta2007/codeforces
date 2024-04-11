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
        ll mat[2*n][2*n];
        ll sum = 0;
        F0R(i, 2*n)
            F0R(j, 2*n) {
                cin >> mat[i][j];
                if(i >= n && j >= n)
                    sum += mat[i][j];
            }
        cout << min(
            min(min(mat[n][0], mat[n-1][2*n-1]),
            min(mat[0][n], mat[2*n-1][n-1])),
            min(min(mat[2*n-1][0], mat[0][2*n-1]),
            min(mat[n-1][n], mat[n][n-1]))) + sum << endl;
    }
}