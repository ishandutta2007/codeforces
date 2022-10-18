#ifdef ONPC
    #define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
#define char unsigned char
 
using namespace std;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
 
typedef long long ll;
typedef long double ld;
 
const int N = 412345;
 
ll tree[N];
 
int solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &i : a) {
        cin >> i;
    }
    n--;
    for (int i = 0; i < n; i++) {
        tree[n + i] = a[i + 1] - a[i];
    }
    for (int i = n - 1; i > 0; i--) {
        tree[i] = gcd(tree[i * 2], tree[i * 2 + 1]);
    }
    int ans = 0;
    auto get_gcd = [&] (int l, int r) -> ll {
        l += n;
        r += n;
        ll res = 0;
        while (l < r) {
            if (l & 1) {
                res = gcd(res, tree[l]);
                l++;
            }
            if (r & 1) {
                r--;
                res = gcd(res, tree[r]);
            }
            l /= 2;
            r /= 2;
        }
        return res;
    };
    for (int l = 0, r = 0; l < n; l++) {
        while (get_gcd(l, r) != 1 && r < n) {
            r++;
        }
        if (get_gcd(l, r) == 1) {
            r--;
        }
        ans = max(ans, r - l);
    }
    cout << ans + 1 << '\n';
    return 0;
}
 
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1e9;
    cin >> TET;
    for (int i = 1; i <= TET; i++) {
        if (solve()) {
            break;
        }
        #ifdef ONPC
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}