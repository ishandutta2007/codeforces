#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 1e9;
const int maxN = 400000 + 2000;
const int md = 998244353;
const int md2 = 1e9 + 7;

// double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

int mul(int a, int b) {
    return (1ll * a * b) % md;
}

int add(int a, int b) {
    if (a + b >= md) return a + b - md;
    return a + b;
}

int sub(int a, int b) {
    if (a - b < 0) return a - b + md;
    return a - b;
}

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int mid = binpow(a, b / 2);
    return mul(mid, mid);
}

int rev(int a) {
    return binpow(a, md - 2);
}

int fact[maxN];

void init() {
    fact[0] = 1;
    for(int i = 1; i <= 1e4; ++i) fact[i] = mul(fact[i-1], i);
}

int Cw(int n, int k) {
    return mul(fact[n], rev(fact[n - k]));
}

void solve() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> bancol(w, 0), banrow(h, 0);
    range(i, n) {
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;
        bancol[c2] = banrow[r1] = banrow[r2] = bancol[c1] = 1;
    }

    int k = max(h, w);
    vector<vector<int>> dp(k + 1, vector<int> (k + 1, 0));
    dp[0][0] = dp[1][0] = 1;
    for(int i = 2; i <= k; ++i) {
        dp[i][0] = 1;
        for(int c = 1; c <= k; ++c) {
            dp[i][c] = add(dp[i-1][c], dp[i-2][c-1]);
        }
    }

    vector<int> cnt(h + 1, 0);
    cnt[0] = 1;
    for(int i = 0, j = 0; i < w; i = j) {
        while(j < w && !bancol[j]) j++;
        if (i == j) {
            j++;
            continue;
        }
        vector<int> new_cnt(h + 1, 0);
        for(int d = 0; d <= (j - i); ++d) {
            for(int ds = d; ds <= h; ++ds) {
                new_cnt[ds] = add(new_cnt[ds], mul(cnt[ds-d], dp[j-i][d]));
            }
        }
        cnt = new_cnt;
    }

    vector<int> cnt2(w + 1, 0);
    cnt2[0] = 1;
    for(int i = 0, j = 0; i < h; i = j) {
        while(j < h && !banrow[j]) j++;
        if (i == j) {
            j++;
            continue;
        }
        vector<int> new_cnt(w + 1, 0);
        for(int d = 0; d <= (j - i); ++d) {
            for(int ds = d; ds <= w; ++ds) {
                new_cnt[ds] = add(new_cnt[ds], mul(cnt2[ds-d], dp[j-i][d]));
            }
        }
        cnt2 = new_cnt;
    }

    int banned_row = 0;
    range(i, h) banned_row += banrow[i];
    int banned_col = 0;
    range(i, w) banned_col += bancol[i];
    init();
    int ans = 0;
    for(int i = 0; i <= h - banned_row && i * 2 <= w - banned_col; ++i) {
        for(int j = 0; j * 2 + i <= h - banned_row && j + i * 2 <= w - banned_col; ++j) {
            int c = mul(cnt[i], cnt2[j]);
            c = mul(c, Cw(h - banned_row - j * 2, i));
            c = mul(c, Cw(w - banned_col - i * 2, j));
            ans = add(ans, c);
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
//    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}