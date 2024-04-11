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

const int N = 312345;
const ll MOD = 998244353;

ll rev2pows[N];
ll dp[N];

ll solve_for_horizontal(vector<vector<int>> f, int n, int m) {
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int white_cells = 0;
        for (int j = 0; j < m; j++) {
            if (f[i][j] == 0) {
                white_cells++;
            } else {
                white_cells = 0;
            }
            if (white_cells >= 2) {
                ans = (ans + dp[white_cells - 2]) % MOD;
                if (white_cells % 2 == 0) {
                    ans = (ans + rev2pows[white_cells - 2]) % MOD;
                }
            }
        }
    }
    ans = (ans * rev2pows[2]) % MOD;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (f[i][j] == 0) {
                ans = ans * 2 % MOD;
            }
        }
    }
    return ans;
}

int solve() {
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    int m;
    cin >> m;
    vector<vector<int>> field(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            field[i][j] = (s[j] == '*');
        }
    }
    rev2pows[0] = 1;
    dp[0] = 0;
    ll rev2 = (MOD + 1) / 2;
    for (int i = 1; i < N; i++) {
        rev2pows[i] = rev2pows[i - 1] * rev2 % MOD;
        dp[i] = dp[i - 1];
        if (i % 2 == 1) {
            dp[i] += rev2pows[i];
        }
    }
    vector<vector<int>> transposedField(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            transposedField[i][j] = field[j][i];
        }
    }
    ll ans = solve_for_horizontal(field, n, m) + solve_for_horizontal(transposedField, m, n);
    ans %= MOD;
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
        cout << '\n';
        #ifdef ONPC
            cout << "\n__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}