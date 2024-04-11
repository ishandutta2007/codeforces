#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld long double
#define ll __int128

mt19937 rnd(51);

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        bool r = 0, g = 0, b = 0, bad = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'r') r = 1;
            else if (s[i] == 'g') g = 1;
            else if (s[i] == 'b') b = 1;

            if (s[i] == 'R') {
                if (!r) {
                    bad = 1;
                }
            } else if (s[i] == 'G') {
                if (!g) {
                    bad = 1;
                }
            } else if (s[i] == 'B') {
                if (!b) {
                    bad = 1;
                }
            }
        }
        cout << (bad ? "NO" : "YES") << endl;
    }
    return 0;
}