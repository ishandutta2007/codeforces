#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 5000 + 5;

int p[N], mn[N], mx[N];

bool f(int n, int d) {
    return d >= mn[n] and d <= mx[n];
}

void construct(int idx, int par, int n, int d) {
    p[idx] = par;
    if (n == 1)
        return;

    if (f(n - 1, d - n + 1)) {
        construct(idx + 1, idx, n - 1, d - n + 1);
        return;
    }

    int target = d - n + 1;
    for (int i = 1; i < n; i++) {
        if (f(n - i - 1, target - mn[i])) {
            construct(idx + 1, idx, i, mn[i]);
            construct(idx + i + 1, idx, n - i - 1, target - mn[i]);
            return;
        }
        if (f(n - i - 1, target - mx[i])) {
            construct(idx + 1, idx, i, mx[i]);
            construct(idx + i + 1, idx, n - i - 1, target - mx[i]);
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    mn[1] = 0;
    for (int i = 2; i < N; i++) {
        mn[i] = mn[i - 1] + floor(log2(i));
        mx[i] = (i * i - i) / 2;
    }

    int t;
    cin >> t;

    while (t--) {
        int n, d;
        cin >> n >> d;
        if (!f(n, d)) {
            cout << "NO\n";
            continue;
        }

        construct(1, 0, n, d);
        cout << "YES\n";

        for (int i = 2; i <= n; i++)
            cout << p[i] << " \n"[i == n];
    }
    return 0;
}