#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while (t--) {
        int x, y; cin >> x >> y;
        if (x >= 4) {
            cout << "YES\n";
            continue;
        }
        queue<int> q;
        map<int, int> mp;
        bool can = false;
        q.push(x);
        while (!q.empty()) {
            int f = q.front(); q.pop();
            if (f == y) {
                can = true;
                break;
            }
            if (f % 2 == 0 && mp[(3 * f) / 2] == 0) {
                q.push((3 * f) / 2);
                mp[(3 * f) / 2] = 1;
            }
            if (f > 1 && mp[f - 1] == 0) {
                q.push(f - 1);
                mp[f - 1] = 0;
            }
        }
        if (can) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

}