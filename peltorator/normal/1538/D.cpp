#ifdef ONPC
    #define _GLIBCXX_DEBUG
    #define deb(a) cerr << "@@@@@@@ " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>
#define char unsigned char

using namespace std;
mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

int getPrimes(int a) {
    int ans = 0;
    for (int i = 2; i * i <= a; i++) {
        while (a % i == 0) {
            a /= i;
            ans++;
        }
    }
    if (a > 1) {
        ans++;
    }
    return ans;
}

int solve() {
    ll a, b, k;
    cin >> a >> b >> k;
    if (k == 1) {
        if (a == b) {
            cout << "NO\n";
        } else if (a % b == 0 || b % a == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return 0;
    }
    if (k > getPrimes(a) + getPrimes(b)) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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