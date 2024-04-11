#include <bits/stdc++.h>
using namespace std;

main() {
    int t;
    cin >> t;
    while (t--) {
        int n, s, k;
        cin >> n >> s >> k;
        set<int> st;
        for (int i = 0; i < k; ++i) {
            int x;
            cin >> x;
            st.insert(x);
        }
        int res = 1e9;
        for (int i = max(1, s - k); i <= min(n, s + k); ++i) {
            if (!st.count(i)) {
                res = min(res, abs(s - i));
            }
        }
        cout << res << endl;
    }
    return 0;
}