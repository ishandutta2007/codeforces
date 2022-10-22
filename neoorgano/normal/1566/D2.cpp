#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400;
int res[MAXN][MAXN];

int n, m;

bool cmp(int i, int j) {
    int x1 = i / m, y1 = i % m;
    int x2 = j / m, y2 = j % m;
    if (x1 == x2) {
        return y1 > y2;
    }
    return x1 < x2;
}

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        cin >> n >> m;
        vector<int> arr(n * m);
        vector<int> gr;
        for (int i = 0; i < n * m; ++i) {
            cin >> arr[i];
            gr.push_back(arr[i]);
        }
        sort(gr.begin(), gr.end());
        int k = unique(gr.begin(), gr.end()) - gr.begin();
        map<int, int> mp;
        for (int i = 0; i < k; ++i) {
            mp[gr[i]] = i;
        }
        for (int i = 0; i < n * m; ++i) {
            arr[i] = mp[arr[i]];
        }
        vector<int> cnt(k);
        vector<vector<int>> in(k, vector<int>(0));
        for (int i = 0; i < n * m; ++i) {
            cnt[arr[i]]++;
            in[arr[i]].push_back(i);
        }
        vector<int> start(k, 0);
        for (int i = 1; i < k; ++i) {
            start[i] = start[i - 1] + cnt[i - 1];
        }
        for (int i = 0; i < k; ++i) {
            vector<int> pos;
            for (int j = start[i]; j < start[i] + cnt[i]; ++j) {
                pos.push_back(j);
            }
            sort(pos.begin(), pos.end(), cmp);
            for (int j = 0; j < cnt[i]; ++j) {
                res[pos[j] / m][pos[j] % m] = in[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < j; ++k) {
                    if (res[i][k] < res[i][j]) ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}