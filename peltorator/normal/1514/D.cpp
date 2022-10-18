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

int solve() {
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    int q;
    cin >> q;
    vector<int> a(n);
    vector<vector<int>> inds(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        inds[a[i]].push_back(i);
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        int len = r - l;
        int major = -1, major_amount = 0;
        for (int j = 0; j < 50; j++) {
            int pos = rnd() % len + l;
            int val = a[pos];
            int cnt = lower_bound(inds[val].begin(), inds[val].end(), r) - lower_bound(inds[val].begin(), inds[val].end(), l);
            if (cnt > (len + 1) / 2) {
                major = val;
                major_amount = cnt;
                break;
            }
        }
        int ans = 1;
        if (major != -1) {
            ans = max(1, major_amount * 2 - len);
        }
        cout << ans << '\n';
    }
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
        cout << '\n';
        #ifdef ONPC
            cout << "\n__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}