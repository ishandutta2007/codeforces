#include <bits/stdc++.h>
#define err(...) //fprintf(stderr, __VA_ARGS__), fflush(stderr)
typedef long long ll;
 
using namespace std;

#define TASK ""

int solve();
int main() {
    #ifndef PoDuReM 
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (TASK == "input") {
            freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
        } else if (TASK != "") {
            freopen(TASK".in", "r", stdin); freopen(TASK".out", "w", stdout);
        }
    #endif
    return solve();
}

const int dd = (int)1e5 + 7;

void uin(int &a, int b) {
    if (a > b) {
        a = b;
    }
}

int solve() {
    int n, s, m, k;
    cin >> n >> m >> s >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    vector<pair<int, int>> F(m);
    for (auto &i : F) {
        cin >> i.first >> i.second;
        --i.first, --i.second;
    }
    vector<pair<int, int>> G;
    vector<int> rem(m, 0);
    for (int i = 0; i < m; ++i) {
        bool ok = true;
        for (int j = 0; j < m; ++j) if (i != j && !rem[j]) {
            if (F[i].first >= F[j].first && F[i].second <= F[j].second) {
                ok = false;
                break;
            }
        }
        if (ok) {
            G.push_back(F[i]);
        } else {
            rem[i] = 1;
        }
    }
    m = (int)G.size();
    sort(G.begin(), G.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });
    int l = 0, r = (int)1e9 + 7;
    while (r - l > 1) {
        int mid = (l + r) / 2;

        vector<int> nA(n), p(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            nA[i] = (A[i] <= mid);
            p[i + 1] = p[i] + nA[i];
        }

        auto getP = [&](int l, int r) {
            return p[r] - p[l];
        };
        vector<vector<int>> dp(m + 1, vector<int>(k + 1, (int)1e9)), maxP(m + 1, vector<int>(k + 1, (int)1e9));
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = 0;
            maxP[i][0] = 0;
        }
        for (int i = 1; i <= m; ++i) {
            int cnt = getP(G[i - 1].first, G[i - 1].second + 1);
            int j = -1;
            for (int o = 0; o < i - 1; ++o) {
                if (G[o].second < G[i - 1].first) {
                    j = o;
                } else {
                    break;
                }
            }
            int j2 = -1;
            for (int o = 0; o < i - 1; ++o) {
                if (G[o].second >= G[i - 1].first && (j2 == -1 || G[o].first < G[j2].first)) {
                    j2 = o;
                }
            }
            err("j = %d  j2 = %d\n", j, j2);
            for (int j = 1; j <= min(cnt, k); ++j) {
                dp[i][j] = 1;
            }
            int cnt2 = 0;
            if (j2 != -1) {
                cnt2 = getP(G[j2].second + 1, G[i - 1].second + 1);
                err("cnt2 = %d\n", cnt2);
            }
            for (int l = 1; l <= k; ++l) {
                if (j != -1) {
                    uin(dp[i][l], maxP[j + 1][max(0, l - cnt)] + 1);
                }
                if (j2 != -1) {
                    uin(dp[i][l], maxP[j2 + 1][max(0, l - cnt2)] + 1);
                }
                maxP[i][l] = min(maxP[i - 1][l], dp[i][l]);
            }
        }
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= k; ++j) {
                err("dp[%d][%d] = %d\n", i, j, dp[i][j]);
                err("maxP[%d][%d] = %d\n", i, j, maxP[i][j]);
            }
        }
        (maxP[m][k] <= s ? r : l) = mid;
    }
    cout << (r == (int)1e9 + 7 ? -1 : r) << "\n";
    return 0;
}