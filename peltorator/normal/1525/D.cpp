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

const int N = 5123;
const int INF = 1e9 + 7;

int dp[N][N];

int solve() {
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    vector<int> a(n);
    for (int &i : a) {
        cin >> i;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = INF;
        }
    }
    for (int j = 0; j < N; j++) {
        dp[0][j] = 0;
    }
    for (int i = 0; i < n; i++) {
        int curans = INF;
        for (int j = 0; j < n; j++) {
            if (a[i]) {
                if (!a[j]) {
                    curans = min(curans, dp[i][j] + abs(i - j));
                }
                dp[i + 1][j + 1] = curans;
            } else {
                dp[i + 1][j] = dp[i][j];
            }
        }
        if (!a[i]) {
            dp[i + 1][n] = dp[i][n];
        }
    }
    cout << dp[n][n] << '\n';
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