#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define Test(x) cout << "Case #" << x << ": ";

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
 

using namespace std;

short memo[52][1 << 10][52];


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        int n;
        cin >> n;

        for (int i = 0; i < 52; i++) {
            for (int mask = 0; mask < (1 << n); mask++) {
                fill(memo[i][mask], memo[i][mask] + 52, -1);
            }
        }

        auto Get = [&](char ch) {
            if (ch >= 'a' && ch <= 'z') {
                return ch - 'a';
            }
            return 26 + ch - 'A';
        };

        constexpr int SIGMA = 256;
        vector<vector<vector<int>>> pos(n, vector<vector<int>>(SIGMA + 1));
        vector<string> str(n);

        for (int i = 0; i < n; i++) {
            cin >> str[i];
            str[i] = " " + str[i];

            for (int j = 1; j < (int)str[i].size(); j++) {
                pos[i][str[i][j]].push_back(j);
            }
        }

        int len = (int)str[0].size() - 1;
        int answer = 0, best_i = 0, best_mask = 0;

        vector<vector<int>> dp(len + 1, vector<int>(1 << n, -1e9));
        vector<vector<pair<int, int>>> from(len + 1, vector<pair<int, int>>(1 << n));

        vector<vector<int>> max_mask(len + 1, vector<int>(1 << n));

        auto update = [&](int i, int maski, int j, int maskj) {
            if (dp[i][maski] < dp[j][maskj] + 1) {
                dp[i][maski] = dp[j][maskj] + 1;
                from[i][maski] = {j, maskj};
            }
        };

        for (int i = 1; i <= len; i++) {
            int bit0 = 0;
            if (pos[0][str[0][i]][0] != i) {
                bit0 = 1;
            }

            for (int mask = 0; mask < (1 << n); mask++) {
                if ((mask & 1) != bit0) continue;

                bool bad = false;
                for (int bit = 0; bit < n; bit++) {
                    if (pos[bit][str[0][i]].size() <= ((mask >> bit) & 1)) {
                        bad = true;
                        break;
                    }
                }

                if (bad) continue;

                dp[i][mask] = 1;

                for (int j = i - 1; j >= 1; j--) {
                    bad = false;

                    int sub_mask = 0;
                    short& ref = memo[Get(str[0][i])][mask][Get(str[0][j])];

                    if (ref == -1) {
                        for (int bit = 0; bit < n; bit++) {

                            int pi = ((mask >> bit) & 1), pj = 0;
                            while (pj < (int)pos[bit][str[0][j]].size() &&
                                   pos[bit][str[0][j]][pj] < pos[bit][str[0][i]][pi]) {
                                pj++;
                            }

                            pj--;
                            if (pj < 0) {
                                bad = true;
                                break;
                            }

                            sub_mask += pj * (1 << bit);
                        }
                        
                        if (bad == true) {
                            ref = -2;
                            continue;
                        }

                        ref = sub_mask;

                    } else if (ref == -2) {
                        continue;
                    } else {
                        sub_mask = ref;
                    }

                    update(i, mask, j, max_mask[j][sub_mask]);
                }

                if (answer < dp[i][mask]) {
                    answer = dp[i][mask];
                    best_i = i;
                    best_mask = mask;
                }
            }

            for (int mask = 0; mask < (1 << n); mask++) {
                max_mask[i][mask] = mask;
                for (int bit = 0; bit < n; bit++) {
                    if (mask & (1 << bit)) {
                        int msk = max_mask[i][mask ^ (1 << bit)];
                        if (dp[i][msk] > dp[i][max_mask[i][mask]]) {
                            max_mask[i][mask] = msk;
                        }
                    }
                }
            }
        }

        string res;
        while (best_i != 0) {
            auto curr = from[best_i][best_mask];
            res += str[0][best_i];
            best_i = curr.first;
            best_mask = curr.second;
        }

        reverse(res.begin(), res.end());
        cout << answer << "\n" << res << "\n";

    }

    return 0;
}