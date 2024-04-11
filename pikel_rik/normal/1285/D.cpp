#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, a[N];

int recurse(int l, int r, int bit, int cur) {
    if (bit < 0)
        return 0;
    if (!((a[l] ^ a[r]) & (1 << bit))) {
        if (a[l] & (1 << bit))
            cur |= (1 << bit);
        return recurse(l, r, bit - 1, cur);
    }
    int mid = lower_bound(a + l, a + r + 1, cur | (1 << bit)) - a;
    return (1 << bit) + min(recurse(l, mid - 1, bit - 1, cur), recurse(mid, r, bit - 1, cur | (1 << bit)));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    cout << recurse(0, n - 1, 29, 0) << '\n';
    return 0;
}