#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int


using namespace std;

const int MOD = (int) 1e9 + 7;

inline void mod(int &x) {
    if(x >= MOD) x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    vector < vector <int> > pos(n + 1);
    vector <int> s(n + 1);
    for(i = 1; i <= n; i++) {
        cin >> s[i];
        pos[s[i]].push_back(i);
    }

    vector < vector <int> > cows(n + 1);
    for(i = 1; i <= m; i++) {
        int f, h;
        cin >> f >> h;
        if(h <= pos[f].size()) {
            cows[f].push_back(h);
        }
    }

    int ans_mx = 0, ans_cnt = 0;
    for(int p = 0; p <= n; p++) {
        int cur_mx = 0, cur_cnt = 1;

        vector <int> dp(4, 0), new_dp(4, 0);

        for(int col = 1; col <= n; col++) {
            int sz = pos[col].size();

            fill(dp.begin(), dp.end(), 0);
            dp[0] = 1;

            bool ok = (col != s[p]);

            for(auto it : cows[col]) {
                for(int conf = 0; conf < 4; conf++) {
                    new_dp[conf] = dp[conf];
                }

                if(pos[col][it - 1] <= p) {
                    if(col == s[p]) {
                        if(pos[col][it - 1] == p) {
                            ok = 1;
                            for(int conf = 0; conf < 4; conf++) {
                                if((conf & 2) == 0) {
                                    add(new_dp[conf | 2], dp[conf]);
                                }
                            }
                        }
                    }
                    else {
                        for(int conf = 0; conf < 4; conf++) {
                            if((conf & 2) == 0) {
                                add(new_dp[conf | 2], dp[conf]);
                            }
                        }
                    }
                }
                if(pos[col][sz - it] > p) {
                    for(int conf = 0; conf < 4; conf++) {
                        if(conf % 2 == 0) {
                            add(new_dp[conf | 1], dp[conf]);
                        }
                    }
                }
                swap(dp, new_dp);
            }

            int mx_bit = -1e9;
            for(int conf = 0; conf < 4; conf++) {
                if(dp[conf] > 0 && ok) { // ?
                    if(col != s[p]) {
                        mx_bit = max(mx_bit, __builtin_popcount(conf));
                    }
                    else if(conf & 2) {
                        mx_bit = max(mx_bit, __builtin_popcount(conf));
                    }
                }
            }
            cur_mx += mx_bit;

            int sum = 0;
            for(int conf = 0; conf < 4; conf++) {
                if(__builtin_popcount(conf) == mx_bit) {
                    if(col == s[p]) {
                        if(conf & 2)
                            add(sum, dp[conf]);
                    }
                    else {
                        add(sum, dp[conf]);
                    }
                }
            }

            sum *= ok;
            cur_cnt = (1LL * cur_cnt * sum) % MOD;
        }

        if(cur_mx > ans_mx) {
            ans_mx = cur_mx;
            ans_cnt = cur_cnt;
        }
        else if(cur_mx == ans_mx) {
            add(ans_cnt, cur_cnt);
        }
    }

    if(ans_mx == 0) {
        ans_cnt = 1;
    }

    cout << ans_mx << " " << ans_cnt;

    return 0;
}