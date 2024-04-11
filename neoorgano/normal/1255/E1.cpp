#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 1e5;
int arr[MAXN];

main() {
    int n;
    cin >> n;
    vector<int> ind;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (arr[i]) {
            ind.push_back(i);
        }
    }
    int x = ind.size();
    if (x < 2) {
        cout << -1;
        return 0;
    }
    int p = -1;
    int res = 1e18;
    for (int i = 2; i <= x; ++i) {
        if (x % i == 0) {
            p = i;
            int ans = 0;
            for (int i = 0; i < x / p; ++i) {
                vector<int> now;
                for (int j = i * p; j < i * p + p; ++j) {
                    now.push_back(ind[j]);
                }
                sort(now.begin(), now.end());
                int k = now[p / 2];
                for (int j = 0; j < p; ++j) {
                    ans += abs(now[j] - k);
                }
            }
            res = min(ans, res);
        }
    }
    cout << res;
    return 0;
}