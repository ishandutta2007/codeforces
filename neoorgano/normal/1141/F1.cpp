#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 3e5;
int arr[MAXN], pref[MAXN];
int dp[MAXN];
int pred[MAXN];
int maxdp[MAXN];

main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        pref[i + 1] = pref[i] + arr[i];
    }
    vector<int> can;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            can.push_back(pref[j] - pref[i]);
        }
    }
    vector<pair<int, int>> ans;
    for (auto sum : can) {
        fill(dp, dp + n + 1, 0);
        fill(maxdp, maxdp + n + 1, 0);
        fill(pred, pred + n + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (pref[i] - pref[j] == sum) {
                    if (dp[maxdp[j]] + 1 > dp[i]) {
                        pred[i] = j;
                        dp[i] = dp[maxdp[j]] + 1;
                    }
                }
            }
            if (dp[i] > dp[maxdp[i - 1]]) {
                maxdp[i] = i;
            } else {
                maxdp[i] = maxdp[i - 1];
            }
        }
        /*if (sum == 5) {
            for (int i = 0; i <= n; ++i) {
                cout << dp[i] << " ";
            }
        }*/
        int maxi = 0;
        for (int i = 0; i <= n; ++i) {
            if (dp[i] > dp[maxi]) {
                maxi = i;
            }
        }
        if (dp[maxi] > ans.size()) {
            ans.clear();
            while (pred[maxi] != -1) {
                ans.push_back({pred[maxi] + 1, maxi});
                maxi = maxdp[pred[maxi]];
            }
        }
    }
    cout << ans.size() << endl;
    for (auto elem : ans) {
        cout << elem.first << " " << elem.second << endl;
    }
    return 0;
}