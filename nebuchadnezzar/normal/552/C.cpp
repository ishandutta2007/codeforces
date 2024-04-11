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

ll w, m;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> w >> m;
    
    ll tmp = m;
    for (int i = 0; i <= 101; ++i) {
        if (tmp % w != 0 && tmp % w != 1 && tmp % w != w - 1) {
            cout << "NO\n";
            return 0;
        }
        if (tmp % w == 1) {
            tmp -= 1;
        }
        if (tmp % w == w - 1) {
            tmp += 1;
        }
        tmp /= w;
    }

    if (!tmp) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}