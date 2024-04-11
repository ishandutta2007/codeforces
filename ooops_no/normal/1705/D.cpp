#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        string s, t, ss = "", tt = "";
        cin >> s >> t;
        for (int i = 0; i + 1 < n; i++) {
            ss += ((s[i] - '0') ^ (s[i + 1] - '0')) + '0';
        }
        for (int i = 0; i + 1 < n; i++) {
            tt += ((t[i] - '0') ^ (t[i + 1] - '0')) + '0';
        }
        if (s[0] != t[0] || s.back() != t.back()) {
            cout << -1 << endl;
        } else {
            int cnts = 0, cntt = 0;
            ll ans = 0;
            for (int i = 0; i < n - 1; i++) {
                cnts += ss[i] == '1';
                cntt += tt[i] == '1';
                ans += abs(cnts - cntt);
            }
            if (cnts != cntt) {
                cout << -1 << endl;
            } else {
                cout << ans << endl;
            }
        }
    }
    return 0;
}