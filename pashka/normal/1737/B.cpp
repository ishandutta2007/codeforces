#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

struct test {

    long calc(long x) {
        long y = sqrt(x);
        while (y * y < x) y++;
        while (y * y >= x) y--;
        long res = (y - 1) * 3 + 1;
        if (y * (y + 1) < x) res++;
        if (y * (y + 2) < x) res++;
//        cout << y << " " << x << " " << res << "\n";
        return res;
    }

    void solve() {
        long l, r;
        cin >> l >> r;
        cout << calc(r + 1) - calc(l) << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        test().solve();
    }

    return 0;
}