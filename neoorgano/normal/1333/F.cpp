#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
int arr[MAXN];
int used[MAXN];

main() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int x = n; x > 1; --x) {
        for (int i = 2 * x; i <= n; i += x) {
            if (used[i]) {
                used[i] = 0;
                cnt--;
            }
        }
        used[x] = 1;
        cnt++;
        arr[x - 1] = cnt + x - 1;
    }
    int f = 1;
    for (int i = 2; i <= n; ++i) {
        while (arr[f] < i) {
            f++;
        }
        cout << f << " ";
    }
    return 0;
}