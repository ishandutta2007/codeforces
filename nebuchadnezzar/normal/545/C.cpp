#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;
typedef long long ll;
typedef double dbl;
typedef pair <int, int> pii;
const int MAXN = 1e5 + 5;

int n;
vector <pii > inp;
int d[2][MAXN];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, h;
        cin >> x >> h;
        inp.puba(mapa(x, h));
    }

    d[0][0] = 1;
    d[1][0] = 1;
    for (int i = 1; i < n; ++i) {
        if (inp[i - 1].ff + inp[i - 1].ss < inp[i].ff) {
            d[1][i] = d[1][i - 1] + 1;
        } else {
            //cerr << "@" << endl;
            d[1][i] = d[0][i - 1] + 1;
        }
        if (inp[i].ff - inp[i].ss > inp[i - 1].ff + inp[i - 1].ss) {            
            d[0][i] = d[1][i - 1] + 1;
        } else if (inp[i].ff - inp[i].ss > inp[i - 1].ff) {
            d[0][i] = d[0][i - 1] + 1;
        } else if (inp[i].ff > inp[i - 1].ff + inp[i - 1].ss) {
            d[0][i] = d[1][i - 1];
        } else {
            d[0][i] = d[0][i - 1];
        }
        //cerr << d[0][i] << " " << d[1][i] << endl;
    }

    cout << d[1][n - 1] << endl;

    return 0;
}