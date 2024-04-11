#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 2e4;
int arr[MAXN];

main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = n; i > 2; --i) {
        ans += i * (i - 1);
    }
    cout << ans;
    return 0;
}