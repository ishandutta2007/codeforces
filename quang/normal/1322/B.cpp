#include <bits/stdc++.h>

using namespace std;

const int N = 400010;
const int LOG = 26;

int n;
int a[N];
int b[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int res = 0;
    for (int l = 0; l < LOG; l++) {
        int mask = (1 << l + 1) - 1;
        for (int i = 1; i <= n; i++) {
            b[i] = a[i] & mask;
        }
        sort(b + 1, b + n + 1);
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            int lower = lower_bound(b + 1, b + i, (1 << l)- b[i]) - b;
            int middle = lower_bound(b + 1, b + i, (1 << l + 1) - b[i]) - b;
            int upper = lower_bound(b + 1, b + i, (1 << l + 1) + (1 << l) - b[i]) - b;
            cur ^= (middle - lower) % 2;
            cur ^= (i - upper) % 2;
        }
        res |= (cur << l);
    }
    cout << res << endl;
    return 0;
}