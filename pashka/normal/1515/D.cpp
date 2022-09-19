#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> ll(n);
    vector<int> rr(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        if (i < l) ll[x]++; else rr[x]++;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        int x = min(ll[i], rr[i]);
        ll[i] -= x;
        rr[i] -= x;
        l -= x;
        r -= x;
        while (l > r && ll[i] >= 2) {
            res++;
            ll[i] -= 2;
            l -= 2;
        }
        while (r > l && rr[i] >= 2) {
            res++;
            rr[i] -= 2;
            r -= 2;
        }
    }
    res += abs(l - r) / 2;
    res += (r + l) / 2;
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve_test();
    }

    return 0;
}