#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <cassert>
#include <bitset>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 998244353, p = 239, N = 4e5 + 5;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);

    int n, q; cin >> n >> q;

    int eq = 0, neq = 0;

    multiset <vector <int>> heap1, heap2;
    map <pair <int, int>, int> getE;
    while (q --> 0) {
        char t, c; cin >> t;
        if (t == '+') {
            int u, v; cin >> u >> v >> c;
            getE[{u, v}] = c;
            if (v < u) swap(v, u);
            if (heap1.find({ u, v }) != heap1.end())
                neq++;
            if (heap2.find({ u, v, c }) != heap2.end())
                eq++;
            heap1.insert({ u, v });
            heap2.insert({ u, v, c });
        }
        else if (t == '-') {
            int u, v; cin >> u >> v;
            c = getE[{u, v}];
            if (v < u) swap(v, u);
            heap1.erase(heap1.find({ u, v }));
            heap2.erase(heap2.find({ u, v, c }));
            if (heap1.find({ u, v }) != heap1.end())
                neq--;
            if (heap2.find({ u, v, c }) != heap2.end())
                eq--;
        }
        else {
            int k; cin >> k;
            cout << (k & 1 and neq or k & 1 ^ 1 and eq ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}