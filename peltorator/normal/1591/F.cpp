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

const ll MOD = 998244353;

int solve() {
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    vector<ll> a(n);
    for (ll &val : a) {
        cin >> val;
    }
    vector<ll> dp(n, 0);
    vector<ll> prefdp(n + 1, 0);
    prefdp[0] = 1;
    vector<int> st;
    ll curans = 0;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.back()] >= a[i]) {
            int pos = st.back();
            st.pop_back();
            int l = -1;
            if (!st.empty()) {
                l = st.back();
            }
            curans = ((curans - (prefdp[pos] - (l >= 0 ? prefdp[l] : 0LL)) * a[pos]) % MOD + MOD) % MOD;
        }
        int l = -1;
        if (!st.empty()) {
            l = st.back();
        }
        curans = ((curans + (prefdp[i] - (l >= 0 ? prefdp[l] : 0LL)) * a[i]) % MOD + MOD) % MOD;
        dp[i] = (MOD - curans) % MOD;
        st.push_back(i);
        prefdp[i + 1] = (prefdp[i] + dp[i]) % MOD;
    }
    ll ans = dp.back();
    if (n % 2 == 1) {
        ans = (MOD - ans) % MOD;
    }
    ans %= MOD;
    ans += MOD;
    ans %= MOD;
    cout << ans << '\n';
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
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