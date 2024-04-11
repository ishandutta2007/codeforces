#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &u : a) cin >> u;
        int res = 0;
        reverse(a.begin(), a.end());
        int last = 1e9;
        for (int u : a) {
            if (last > u + 1) {
                last = u + 1;
                res++;
            } else if (last == u + 1) {
                last = u;
                res++;
            }
        }
        cout << res << '\n';
    }
    return 0;
}