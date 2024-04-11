#include<bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const int INF = 1e9;

struct Fenwick {
    vector<int> t;
    Fenwick(int n) {
        t.resize(n);
    }
    void inc(int i, int d) {
        for (; i < t.size(); i = (i | (i + 1))) {
            t[i] += d;
        }
    }
    int get(int r) {
        int ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ans += t[r];
        }
        return ans;
    }
    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

signed main() {
#ifdef LOCAL
   // freopen("input.txt", "r", stdin);
#endif // LCOAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> p(n), pos(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        pos[p[i]] = i;
    }
    k++;
    vector<vector<int>> dp(k + 1, vector<int>(1 << k, INF));
    dp[0][0] = 0;
    Fenwick t(n);
    for (int i = 0; i < n; i++) {
        vector<vector<int>> dpp(k + 1, vector<int>(1 << k, INF));
        t.inc(pos[i], 1);
        for (int j = 0; j <= k; j++) {
            int mn = i - j;
            if (mn >= 0) {
                t.inc(pos[mn], -1);
            }
            for (int mask = 0; mask < (1 << k); mask++) {
                if (dp[j][mask] == INF) continue;
                vector<int> ind;
                for (int f = 0; f < k; f++) {
                    if (mask & (1 << f)) {
                        assert(mn + f < n);
                        ind.pb(mn + f);
                    }
                }
                for (int f = 0; f < k && mn + f < n; f++) {
                    if (!(mask & (1 << f))) {
                        int val = mn + f;
                        int add = t.get(pos[val], n - 1);
                        for (auto a : ind) {
                            add += pos[a] > pos[val];
                        }
                        int new_mask = mask | (1 << f), new_j = j + 1;
                        while (new_mask & 1) {
                            new_mask /= 2;
                            new_j--;
                        }
                        if (new_j < 0 || new_j > k) continue;
                        dpp[new_j][new_mask] = min(dpp[new_j][new_mask], dp[j][mask] + add);
                    }
                }
            }
        }
        for (int j = 0; j <= k; j++) {
            int mn = i - j;
            if (mn >= 0) {
                t.inc(pos[mn], 1);
            }
        }
        swap(dp, dpp);
    }
    cout << dp[0][0] << endl;
    return 0;
}