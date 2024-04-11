#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 5000 + 5;

int n, a[N];

int recurse(int l, int r, int h) {
    int mn = *min_element(a + l, a + r + 1);
    int cost = mn - h;

    int last = l - 1;
    for (int i = l; i <= r; i++) {
        if (a[i] == mn) {
            if (last != i - 1)
                cost += recurse(last + 1, i - 1, mn);
            last = i;
        }
    }

    if (last != r)
        cost += recurse(last + 1, r, mn);
    return min(cost, r - l + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << recurse(0, n - 1, 0) << "\n";
    return 0;
}