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

ll gcd(ll a, ll b) {
    while (a) {
        b %= a;
        swap(a, b);
    }
    return b;
}

int solve() {
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    vector<int> odd, even;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 2 == 1) {
            odd.push_back(x);
        } else {
            even.push_back(x);
        }
    }
    vector<int> arr = even;
    for (int i : odd) {
        arr.push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (gcd(arr[i], 2 * arr[j]) != 1) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
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