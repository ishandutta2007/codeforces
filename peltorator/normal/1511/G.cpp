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

const int N = 212345;

int cnt[N];

int prefsums[N];

int getsum(int l, int r) {
    if (l > r) {
        return 0;
    }
    return prefsums[r] - prefsums[l];
}

const int X = 20;

int dp[X][N];

int findans(int l, int r, int x) {
    int ans = dp[x][l];
    int mid = r - (r - l) % (1 << (x + 1));
    ans -= dp[x][mid];
    int sep = mid + (1 << x);
    if (sep < r) {
        ans += getsum(sep, r);
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
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        c--;
        cnt[c]++;
    }
    for (int i = 1; i < N; i++) {
        prefsums[i] = prefsums[i - 1] + cnt[i - 1];
    }
    for (int x = 0; x < 20; x++) {
        for (int pos = m - 1; pos >= 0; pos--) {
            int mid = pos + (1 << x);
            int nextpos = pos + (1 << (x + 1));
            dp[x][pos] = getsum(mid, min(nextpos, m));
            if (nextpos < m) {
                dp[x][pos] += dp[x][nextpos];
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        bool have_1_bit = false;
        for (int x = 0; x < 20; x++) {
            if (findans(l, r, x) % 2 == 1) {
                have_1_bit = true;
                break;
            }
        }
        cout << (have_1_bit ? "A" : "B");
    }
    cout << '\n';
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