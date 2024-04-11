#include <bits/stdc++.h>
using namespace std;

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n, k;
        cin >> n >> k;
        vector<int> used(2 * n, 0);
        vector<array<int, 2>> h;
        for (int i = 0; i < k; ++i) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            if (x > y) {
                swap(x, y);
            }
            h.push_back({x, y});
            used[x] = used[y] = 1;
        }
        vector<int> rem;
        for (int i = 0; i < 2 * n; ++i) {
            if (!used[i]) {
                rem.push_back(i);
            }
        }
        for (int i = 0; i < n - k; ++i) {
            h.push_back({rem[i], rem[n - k + i]});
        }
        sort(h.begin(), h.end());
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            /// cout << h[i][0] << " " << h[i][1] << endl;
            for (int j = i + 1; j < n; ++j) {
                if (h[i][1] < h[j][1] && h[i][1] > h[j][0]) {
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}