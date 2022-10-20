#include <bits/stdc++.h>

using namespace std;

const int LOG = 30;

int n;
int basis[LOG];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int cur = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        cur ^= u;
        auto add = [](int now, int &cnt) {
            for (int i = LOG - 1; i >= 0; i--) {
                if ((now >> i & 1) == 0) continue;
                if (!basis[i]) {
                    basis[i] = now;
                    cnt++;
                    return;
                }
                now ^= basis[i];
            }
        };
        add(cur, cnt);
    }   
    if (cur == 0) {
        cout << -1 << endl;
        return 0;
    } 
    cout << cnt << endl;
    return 0;
}