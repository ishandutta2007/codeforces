#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    srand(time(0));
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        int res = 0;
        for (int it = 0; it < 9; it++) {
            vector<int> a;
            vector<int> b;
            for (int i = 1; i <= n; i++) {
                int id = (i >> it) & 1;
                if (id == 0) a.push_back(i);
                else b.push_back(i);
            }
            if (a.empty() || b.empty()) break;
            cout << a.size() << ' ' << b.size() << ' ';
            for (int u : a) cout << u << ' ';
            for (int u : b) cout << u << ' ';
            cout << endl;
            int foo;
            cin >> foo;
            res = max(res, foo);
        }
        cout << -1 << ' ' << res << endl;
    }
    return 0;
}