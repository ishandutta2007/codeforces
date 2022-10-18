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

bool cmp(const vector<ll>& a, const vector<ll>& b) {
    return sz(a) > sz(b);
}

int solve() {
    int n;
    cin >> n;
    vector<vector<ll>> st(n);
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        ll s;
        cin >> s;
        st[x[i] - 1].push_back(s);
    }
    sort(st.begin(), st.end(), cmp);
    vector<ll> sum(n);
    for (int i = 0; i < n; i++) {
        for (ll j : st[i]) {
            sum[i] += j;
        }
    }
    for (int i = 0; i < n; i++) {
        sort(st[i].begin(), st[i].end());
        int a = sz(st[i]);
        vector<ll> newst(a + 1);
        for (int j = 0; j < a; j++) {
            newst[j + 1] = newst[j] + st[i][j];
        }
        st[i] = newst;
    }
    for (int k = 1; k <= n; k++) {
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int a = sz(st[i]) - 1;
            if (a < k) {
                break;
            }
            ans += sum[i] - st[i][a % k];
        }
        cout << ans << ' ';
    }
    cout << '\n';
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