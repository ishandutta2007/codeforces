#include <bits/stdc++.h>
using namespace std;

main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool f = true;
        for (int i = 0; i < n; ++i) {
            if (s[i] != s[0]) {
                f = false;
            }
        }
        if (f) {
            cout << (n + 2) / 3 << '\n';
            continue;
        }
        int cnt = 0;
        while (s[0] == s.back()) {
            cnt++;
            s.pop_back();
        }
        string t;
        while (cnt--) {
            t.push_back(s[0]);
        }
        s = t + s;
        s.push_back(s[0]);
        char ch = s[0];
        cnt = 0;
        int ans = 0;
        for (int i = 0; i <= n; ++i) {
            if (s[i] == ch) {
                cnt++;
            } else {
                /// cout << "cnt: " << cnt << endl;
                ans += cnt / 3;
                cnt = 1;
                ch = s[i];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}