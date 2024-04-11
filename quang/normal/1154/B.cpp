#include <bits/stdc++.h>

using namespace std;

const int N = 100010;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &u : a) cin >> u;
    int res = 1000;
    for (int i = 1; i <= 100; i++) {
        int d = -1;
        int found = 0;
        for (int u : a) {
            if (u == i) continue;
            if (d == -1) d = abs(i - u);
            else {
                if (u + d == i) continue;
                if (u - d == i) continue;
                found = 1;
                break;
            }
        }
        if (d == -1) d = 0;
        if (!found) res = min(res, d);
    }
    if (res >= 1000) cout << -1 << endl;
    else cout << res << endl;
    return 0;
}