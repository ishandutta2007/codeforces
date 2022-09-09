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

ll x, y, m;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> x >> y >> m;

    if (max(x, y) >= m) {
        cout << 0 << endl;
        return 0;
    }

    if (max(x, y) <= 0) {
        cout << -1 << endl;
        return 0;
    }

    if (x > y) {
        swap(x, y);
    }

    ll ans = 0;

    if (x < 0) {
        ans += (-x) / y;
        x += ans * y;
    }

    while (max(x, y) < m) {
        if (x < y) {
            x += y;
        } else {
            y += x;
        }
        ++ans;
    }

    cout << ans << endl;

    return 0;
}