#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Counter {
    vector<int> cnt;
    vector<int> a;
    ll curans;
    int l, r; // current segment is [l, r)

    Counter(const vector<int>& arr) {
        a = arr;
        cnt.assign(a.size() + 1, 0);
        curans = 0;
        l = 0;
        r = 0;
    }

    ll ask(int ql, int qr) { // [ql, qr)
        while (l > ql) {
            l--;
            curans += cnt[a[l]];
            cnt[a[l]]++;
        }
        while (r < qr) {
            curans += cnt[a[r]];
            cnt[a[r]]++;
            r++;
        }
        while (l < ql) {
            cnt[a[l]]--;
            curans -= cnt[a[l]];
            l++;
        }
        while (r > qr) {
            r--;
            cnt[a[r]]--;
            curans -= cnt[a[r]];
        }
        return curans;
    }
};

const int N = 100001;
const int K = 21;
const ll INF = 1e18;

ll dp[K][N];

void divide(int ki, int L, int R, int cl, int cr, Counter& counter) { // find dp[ki][ni] for all ni: l <= ni < r if cl <= opt[ki][ni] < cr
    if (L >= R) { // empty segment
        return;
    }
    int M = (L + R) / 2;
    int opt; // optimal partition point for dp[ki][M]
    for (int i = cl; i < min(M, cr); i++) {
        if (dp[ki][M] > dp[ki - 1][i] + counter.ask(i, M)) {
            dp[ki][M] = dp[ki - 1][i] + counter.ask(i, M);
            opt = i;
        }
    }
    divide(ki, L, M, cl, opt + 1, counter);
    divide(ki, M + 1, R, opt, cr, counter);
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int &val : arr) {
        cin >> val;
    }
    for (int ki = 0; ki <= k; ki++) {
        fill(dp[ki], dp[ki] + N, INF);
    }
    dp[0][0] = 0;
    for (int ki = 1; ki <= k; ki++) {
        Counter counter(arr);
        divide(ki, ki, n + 1, 0, n + 1, counter);
    }
    cout << dp[k][n] << endl;
}