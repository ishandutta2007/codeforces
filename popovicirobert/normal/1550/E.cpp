#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define Test(x) cout << "Case #" << x << ": ";
 
using namespace std;



 
int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, k;
    string str;
    cin >> n >> k >> str;

    auto Check = [&](int len) {

        vector<int> freq(k);
        int cnt_q = 0;

        vector<vector<int>> pos(k, vector<int>(n, n));

        for (int i = 0; i < n; i++) {
            if (str[i] == '?') {
                cnt_q++;
            } else {
                freq[str[i] - 'a']++;
            }

            if (i >= len) {
                if (str[i - len] == '?') {
                    cnt_q--;
                } else {
                    freq[str[i - len] - 'a']--;
                }
            }

            for (int ch = 0; ch < k; ch++) {
                if (freq[ch] + cnt_q == len) {
                    pos[ch][i - len + 1] = i - len + 1;
                }
            }
        }

        for (int ch = 0; ch < k; ch++) {
            for (int i = n - 2; i >= 0; i--) {
                pos[ch][i] = min(pos[ch][i], pos[ch][i + 1]);
            }
        }

        vector<int> dp(1 << k, n);
        for (int ch = 0; ch < k; ch++) {
            dp[1 << ch] = pos[ch][0];
        }

        for (int conf = 0; conf < (1 << k); conf++) {
            for (int i = 0; i < k; i++) {
                if (conf & (1 << i)) {
                    if (dp[conf ^ (1 << i)] + len < n) {
                        dp[conf] = min(dp[conf], pos[i][dp[conf ^ (1 << i)] + len]);
                    }
                }
            }
        }

        return dp[(1 << k) - 1] < n;
    };

    int res = 0;
    for (int step = 1 << 17; step; step >>= 1) {
        if (Check(res + step)) {
            res += step;
        }
    }

    cout << res;

    return 0;
    
}