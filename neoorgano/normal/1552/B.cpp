#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
array<int, 5> arr[MAXN];

int get(int u, int v) {
    int cnt = 0;
    for (int i = 0; i < 5; ++i) {
        cnt += (arr[u][i] < arr[v][i]);
    }
    if (cnt >= 3) {
        return u;
    }
    return v;
}

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 5; ++j) {
                cin >> arr[i][j];
            }
        }
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cur = get(cur, i);
        }
        for (int i = 0; i < n; ++i) {
            if (get(cur, i) != cur) {
                cur = -2;
                break;
            }
        }
        cout << cur + 1 << "\n";
    }
    return 0;
}