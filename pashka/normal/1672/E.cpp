#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int ask(int w) {
    if (w < 1) return 0;
    cout << "? " << w << endl;
    int x;
    cin >> x;
    return x;
}


int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int l = n + n - 2;
    int r = n * 2001;
    while (r > l + 1) {
        int m = (l + r) / 2;
        int h = ask(m);
        if (h == 1) {
            r = m;
        } else {
            l = m;
        }
    }
    int res = r;
    for (int t = 2; t <= n; t++) {
        int w = (r - 1) / t;
        int h = ask(w);
        if (h > 0)
            res = min(res, w * h);
    }
    cout << "! " << res << endl;

    return 0;
}