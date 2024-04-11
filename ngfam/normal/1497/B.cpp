#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int ntest; cin >> ntest;
    while(ntest--) {
        int n, m; cin >> n >> m;
        map<int, int> mp;
        for(int i = 0; i < n; ++i) {
            int x; cin >> x;
            mp[x % m] += 1;
        }

        int ans = 0;
        for(int i = 1; i + i < m; ++i) {
            int x = mp[i], y = mp[m - i];
            if (x < y) swap(x, y);
            if (x == 0) continue;
            if (abs(x-y) <= 1) ans += 1;
            else ans += x - y;
        }
        if (mp[0] > 0) ans += 1;

        if (m%2 == 0 && mp[m/2]>0) ans += 1;

        cout << ans << endl;
    }

    return 0;
}