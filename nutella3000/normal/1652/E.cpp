#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define mp make_pair
#define siz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define pb emplace_back
#define pii pair<int, int>
#define chmax(a, b) a = max(a, b)

const int N = 1e5 + 3, mod = 998244353, inf = 1e9 + 7;
const int K = 300, M = (N+2)*(K+2);

int cnt[2*M];

void run() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; ++i)
        cin >> c[i];

    int res = 0;

    for (int b = -K; b <= K; ++b) {
        int nr = 0;
        for (int i = 0; i < n; ++i) {
            ++cnt[c[i] - i*b + M];
            int t = cnt[c[i] - i*b + M];
            if (t > nr) nr = t;
        }
        for (int i = 0; i < n; ++i)
            --cnt[c[i] - i*b + M];

        chmax(res, nr);
    }

    for (int m = 0; m < n; ++m) {
        int nr = 0;
        for (int i = max(0ll, m - N/K - 5); i < min(n, m + N/K + 5); ++i) {
            // c[m] = a + ib
            if (i == m || (c[i] - c[m]) % (i-m) != 0) continue;

            int pb = (c[i] - c[m]) / (i - m);
            ++cnt[pb + M];

            int t = cnt[pb + M];
            chmax(nr, t);
        }
        for (int i = max(0ll, m - N/K - 5); i < min(n, m + N/K + 5); ++i) {
            // c[m] = a + ib
            if (i == m || (c[i] - c[m]) % (i-m) != 0) continue;

            int pb = (c[i] - c[m]) / (i - m);
            --cnt[pb + M];
        }

        chmax(res, nr+1);
    }

    cout << n-res << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}