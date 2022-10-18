#ifdef ONPC
    #define _GLIBCXX_DEBUG
    #define deb(a) cerr << "@@@@@@@ " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <iostream>
#include <algorithm>
#include <cmath>
#include <random>
#define char unsigned char

using namespace std;
mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

int solve() {
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    vector<ll> a(n);
    vector<ll> b(n);
    for (ll &i : a) {
        cin >> i;
    }
    for (ll &i : b) {
        cin >> i;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i] * b[i];
    }
    ll defans = ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= i + 2 && j < n; j++) {
            ll curans = defans;
            int I = i;
            int J = j;
            while (true) {
                if (i < 0 || j >= n) {
                    break;
                }
                curans -= a[i] * b[i];
                curans -= a[j] * b[j];
                curans += a[i] * b[j];
                curans += a[j] * b[i];
                i--;
                j++;
                ans = max(ans, curans);
            }
            i = I;
            j = J;
        }
    }
    cout << ans << '\n';
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    //cin >> TET;
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