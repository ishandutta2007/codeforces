#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e4;
int a[MAXN], cnt[MAXN];
array<int, 2> ans[MAXN];
int used[MAXN];

main() {
    int n, k;
    cin >> n >> k;
    int m = (n + k - 2) / (k - 1);
    for (int i = 0; i < n * k; ++i) {
        cin >> a[i];
        a[i]--;
    }
    fill(used, used + n * k, -1);
    int lst = -1;
    array<int, 2> z = {0, 0};
    for (int i = 0; i < n * k; ++i) {
        if (ans[a[i]] != z) continue;
        if (used[a[i]] > lst) {
            ans[a[i]] = {used[a[i]], i};
            for (int j = used[a[i]]; j <= i; ++j) {
                cnt[j]++;
                if (cnt[j] == m) {
                    lst = max(lst, j);
                }
            }
        } else {
            used[a[i]] = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        assert(ans[i] != z);
        cout << ans[i][0] + 1 << " " << ans[i][1] + 1 << "\n";
    }
    return 0;
}