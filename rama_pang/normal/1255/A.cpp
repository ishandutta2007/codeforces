#include <bits/stdc++.h>
#define testcase int TESTCASE; cin >> TESTCASE; for (int TC = 1; TC <= TESTCASE; TC++)
#define db(x) cout << #x << " is " << x << "\n"
using namespace std;
using lint = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        lint a, b; cin >> a >> b;
        lint ans = 0;
        if (a == b) {
            cout << 0 << "\n";
            continue;
        }
        if (abs(a - b) >= 10) {
            ans += (abs(a - b) / 10);
            if (a >= b) {
                a -= ans * 10;
            } else {
                a += ans * 10;
            }
            ans *= 2;
        }
        
        queue<pair<lint, lint>> q;
        q.emplace(a, 0ll);
        map<lint, int> vis;
        
        while (!q.empty()) {
            lint f = q.front().first, w = q.front().second;
            q.pop();
            if (vis[f]) continue;
            if (abs(f - b) > 1000) continue;
            vis[f] = 1;
            if (f < 0) continue;
            if (f == b) {
                ans += w;
                break;
            }
            q.emplace(f + 5, w + 1);
            q.emplace(f + 2, w + 1);
            q.emplace(f + 1, w + 1);
            q.emplace(f - 5, w + 1);
            q.emplace(f - 2, w + 1);
            q.emplace(f - 1, w + 1);   
        }

        cout << ans << "\n";
    }

}