//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int N = 5e6 + 5;
const int M = 22;

int a[N];
int cnt[N];
int used[N];
int t;

void add(int mask) {
    if (cnt[mask] > 1 || used[mask] == t) {
        return;
    }
    cnt[mask]++;
    used[mask] = t;
    for (int i = 0; i < M; i++) {
        if (mask & (1 << i)) {
            add(mask ^ (1 << i));
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        int mask = 0;
        t = i;
        for (int j = M - 1; j >= 0; j--) {
            if ((a[i] >> j) & 1) {
                continue;
            }
            if (cnt[mask | (1 << j)] > 1) {
                mask |= 1 << j;
            }
        }
        if (i + 2 < n) {
            ans = max(ans, a[i] | mask);
        }
        add(a[i]);
    }
    cout << ans;
    return 0;
}