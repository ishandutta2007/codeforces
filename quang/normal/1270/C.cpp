#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        long long sum = 0;
        long long xorSum = 0;
        for (int i = 1; i <= n; i++) {
            int u; cin >> u;
            sum += u;
            xorSum ^= u;
        }
        if (sum == 0) {
            cout << 0 << "\n\n";
            continue;
        }
        vector<long long> res;
        int foo = log2(sum) + 2;
        long long now = (1ll << foo);
        if (sum & 1) now++;
        res.push_back(now);
        sum += now;
        xorSum ^= now;
        long long bar = (xorSum * 2 - sum) / 2;
        res.push_back(bar);
        res.push_back(bar);
        cout << res.size() << '\n';
        for (long long u : res) cout << u << ' ';
            cout << '\n';
    }   
    return 0;
}