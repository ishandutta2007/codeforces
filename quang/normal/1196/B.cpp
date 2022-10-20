#include <bits/stdc++.h>

using namespace std;

const int N = 100010;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int cur = 0;
        vector<int> res;
        for (int i = 1; i < k; i++) {
            long long tot = 0;
            while (cur < n) {
                tot += a[cur];
                cur++;
                if (tot % 2) break;
            }
            res.push_back(cur);
        }
        long long foo = 0;
        for (int i = cur; i < n; i++) {
            foo += a[i];
        }
        if (foo % 2 == 0) {
            cout << "NO\n";
            continue;
        }
        res.push_back(n);
        cout << "YES\n";
        for (int u : res) cout << u << ' ';
            cout << '\n';
    }
    return 0;
}