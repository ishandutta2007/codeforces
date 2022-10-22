#include <bits/stdc++.h>
using namespace std;

int main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n, k;
        cin >> n >> k;
        vector<string> arr(n), ans(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            for (int j = 0; j < n; ++j) {
                ans[i].push_back('1');
            }
        }
        vector<int> minx(2 * n - 1, 0);
        for (int i = n; i < 2 * n - 1; ++i) {
            minx[i] = i - n + 1;
        }
        vector<int> cur;
        cur.push_back(0);
        bool can = true;
        for (int i = 0; i < 2 * n - 2 * k + 1; ++i) {
            for (int t : cur) {
                /// cout << t << " ";
                bool f = false;
                for (int i = minx[n - 1 + t]; i < n && i - t < n; ++i) {
                    if (arr[i][i - t] == '1') {
                        ans[i][i - t] = '0';
                        if (t - 1 + n - 1 >= 0) {
                            minx[t - 1 + n - 1] = max(minx[t - 1 + n - 1], i);
                        }
                        if (t + 1 + n - 1 < 2 * n - 1) {
                            minx[t + 1 + n - 1] = max(minx[t + 1 + n - 1], i + 1);
                        }
                        f = true;
                        break;
                    }
                }
                if (!f) {
                    can = false;
                    break;
                }
            }
            /// cout << endl;
            if (!can) break;
            vector<int> ncur;
            if (i >= n - k) {
                for (int i = 0; i < (int)cur.size() - 1; ++i) {
                    ncur.push_back(cur[i] + 1);
                }
            } else {
                ncur.push_back(cur[0] - 1);
                for (int i = 0; i < (int)cur.size(); ++i) {
                    ncur.push_back(cur[i] + 1);
                }
            }
            cur = ncur;
        }
        if (can) {
            cout << "YES" << endl;
            for (auto elem : ans) {
                cout << elem << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
/**
1
4 3
1110
0101
1010
0111
*/