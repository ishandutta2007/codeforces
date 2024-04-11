#include <bits/stdc++.h>
using namespace std;

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        set<int> st;
        for (int m = 0; m < (1 << n); ++m) {
            int s = 0;
            for (int i = 0; i < n; ++i) {
                if (m & (1 << i)) {
                    s += a[i];
                }
            }
            st.insert(s);
        }
        if (st.size() == (1 << n)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}