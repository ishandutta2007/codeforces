#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> f;
    vector<int> l;
    int g = 0;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        int ff = 0;
        int ll = 0;
        int px;
        bool ok = false;
        for (int j = 0; j < k; j++) {
            int x; cin >> x;
            if (j == 0) ff = x;
            if (j == k - 1) ll = x;
            if (j > 0 && x > px) {
                ok = true;
            }
            px = x;
        }
        if (ok) {
            g++;
        } else {
            f.push_back(ff);
            l.push_back(ll);
        }
    }
    sort(f.begin(), f.end());
    sort(l.begin(), l.end());
    long res = (long)g * n + (long)(n - g) * g;
    for (int ll : l) {
        int x = lower_bound(f.begin(), f.end(), ll + 1) - f.begin();
        res += f.size() - x;
    }
    cout << res << "\n";

    return 0;
}