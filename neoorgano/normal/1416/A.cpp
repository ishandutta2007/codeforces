#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e5;
int arr[MAXN], last[MAXN], len[MAXN];

bool cmp(int a, int b) {
    return len[a] < len[b];
}

main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        fill(last, last + n, -1);
        fill(len, len + n, -1);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            x--;
            len[x] = max(len[x], i - last[x]);
            last[x] = i;
        }
        vector<int> all;
        for (int i = 0; i < n; ++i) {
            if (len[i] != -1) {
                len[i] = max(len[i], n - last[i]);
                all.push_back(i);
            }
        }
        sort(all.begin(), all.end(), cmp);
        int cur = 1e9, f = 0;
        for (int k = 1; k <= n; ++k) {
            while (f < all.size() && len[all[f]] <= k) {
                cur = min(cur, all[f]);
                f++;
            }
            if (cur == 1e9) {
                cout << -1;
            } else {
                cout << cur + 1;
            }
            cout << " ";
        }
        cout << '\n';
    }

    return 0;
}