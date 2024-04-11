#include <bits/stdc++.h>
using namespace std;

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string t = s;
        sort(t.begin(), t.end());
        int ans = s.size();
        for (int i = 0; i < s.size(); ++i) {
            ans -= (s[i] == t[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}