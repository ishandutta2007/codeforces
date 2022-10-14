#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int q;
    cin >> q;
    while (q--) {
        lint n;
        cin >> n;
        vector<lint> t;
        lint k = 1;
        t.emplace_back(1);
        while (t.back() <= n) {
            k = 3 * k + 1;
            t.emplace_back(t.back() * 3);
        }
        for (int i = (int)t.size() - 1; i >= 0; i--) {
            // cout << k << " ";
            if ((k - t[i]) >= n) {
                k -= t[i];
            }
        }
        cout << k << "\n";
    }
    return 0;
}