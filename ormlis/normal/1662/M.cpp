//#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>
#include <queue>
#include <set>

using namespace std;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef long double ld;

const ll SZ = 3e5 + 1000;



signed main()
{
    fastInp;

    ll t;
    cin >> t;

    while (t--) {
        ll n, m;
        cin >> n >> m;

        ll r = 0, w = 0;
        for (int i = 0; i < m; i++) {
            ll rc, wc;
            cin >> rc >> wc;
            r = max(rc, r);
            w = max(wc, w);
        }

        if (r + w > n) {
            cout << "IMPOSSIBLE\n";
        } else {
            for (int i = 0; i < r; i++) {
                cout << "R";
            }
            for (int i = r; i < n; i++) {
                cout << "W";
            }
            cout << "\n";
        }
    }

    return 0;
}