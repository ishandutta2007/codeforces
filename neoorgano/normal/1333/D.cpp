#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e3;
int arr[MAXN];

main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') {
            arr[i] = 1;
        }
    }
    vector<int> cur;
    vector<vector<int>> ans;
    for (int i = 1; i < n; ++i) {
        if (arr[i] && !arr[i - 1]) {
            cur.push_back(i);
        }
    }
    while (!cur.empty()) {
        ans.push_back(cur);
        vector<int> cur1;
        for (auto i : cur) {
            arr[i] = 0;
            arr[i - 1] = 1;
            if (i >= 2 && arr[i - 2] == 0) {
                cur1.push_back(i - 1);
            }
            if (arr[i + 1]) {
                cur1.push_back(i + 1);
            }
        }
        cur = cur1;
    }
    int cnt = 0;
    for (int i = 0; i < (int)ans.size(); ++i) {
        cnt += ans[i].size();
    }
    if (cnt < k) {
        cout << -1;
        return 0;
    }
    if ((int)ans.size() > k) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < (int)ans.size(); ++i) {
        if (cnt - (int)ans[i].size() >= k - 1) {
            cout << ans[i].size() << " ";
            for (auto j : ans[i]) {
                cout << j << " ";
            }
            cout << '\n';
            k--;
        } else {
            cout << cnt - k + 1 << " ";
            for (int j = 0; j < cnt - k + 1; ++j) {
                cout << ans[i][j] << " ";
            }
            cout << '\n';
            for (int j = cnt - k + 1; j < (int)ans[i].size(); ++j) {
                cout << 1 << " " << ans[i][j];
                cout << '\n';
                k--;
            }
            k--;
        }
        cnt -= ans[i].size();
    }
    return 0;
}