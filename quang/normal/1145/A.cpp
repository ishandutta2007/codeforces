#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int a[N];

int go(int l, int r) {
    if (l == r) return 1;
    int m = l + r >> 1;
    int res = max(go(l, m), go(m + 1, r));
    int found = 0;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] < a[i - 1]) {
            found = 1;
            break;
        }
    }
    if (!found) res = r - l + 1;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cout << go(1, n) << endl;
    return 0;
}