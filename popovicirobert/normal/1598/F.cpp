#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define Test(x) cout << "Case #" << x << ": ";
 
using namespace std;

constexpr int MAXN = 20;

int dp[1 << MAXN][2];


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    vector<int> mn(n, 1e9), bal(n);
    vector<unordered_map<int, int>> first(n), last(n);
    vector<vector<int>> freq(n);

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        unordered_map<int, int> tot_freq;
        int balance = 0;
        for (auto itr : str) {
            if (itr == '(') {
                balance++;
            } else {
                balance--;
            }

            mn[i] = min(mn[i], balance);
            tot_freq[balance]++;

            if (first[i].count(balance) == 0) {
                first[i][balance] = (int)freq[i].size();
            }

            last[i][balance] = (int)freq[i].size();
            freq[i].push_back(tot_freq[balance]);
        }

        bal[i] = balance;
    }

    for (int mask = 1; mask < (1 << n); mask++) {
        constexpr int INF = 1e9;
        dp[mask][0] = -INF;

        int balance = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                balance += bal[i];
            }
        }
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                balance -= bal[i];

                dp[mask][1] = max(dp[mask][1], dp[mask ^ (1 << i)][1]);

                if (balance >= 0) {
                    int a = (balance + mn[i] < 0);
                    int curr = 0;

                    if (mn[i] >= -balance) {
                        auto itr = last[i].find(-balance);
                        if (itr != last[i].end()) {
                            curr = freq[i][itr->second];
                        }
                    } else {
                        auto itr = first[i].find(-balance - 1);
                        assert(itr != first[i].end());

                        if (itr->second > 0) {
                            curr = freq[i][itr->second - 1];
                        }
                    }

                    dp[mask][a] = max(dp[mask][a], dp[mask ^ (1 << i)][0] + curr);
                }

                balance += bal[i];
            }
        }
    }

    cout << max(dp[(1 << n) - 1][0], dp[(1 << n) - 1][1]);
    
    return 0;
}