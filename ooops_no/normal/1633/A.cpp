#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<pair<string, int>> good;
    for (int i = 0; i <= 999; i += 7) {
        string s = to_string(i);
        while (s.size() < 3) s = '0' + s;
        good.pb({s, to_string(i).size()});
    }
    int t;
    cin >> t;
    while (t--) {
        int n, bst = 3;
        cin >> n;
        string s = to_string(n), ans = "";
        while (s.size() < 3) s = '0' + s;
        for (auto to : good) {
            if (to.second < to_string(n).size()) continue;
            int cnt = 0;
            for (int j = 0; j < 3; j++) {
                if (to.first[j] != s[j]) cnt++;
            }
            if (cnt < bst) {
                bst = cnt;
                ans = to.first;
            }
        }
        bool ok = 0;
        for (int j = 0; j < 3; j++) {
            if (ans[j] == '0') {
                if (ok) {
                    cout << 0;
                }
            } else {
                cout << ans[j];
                ok = 1;
            }
        }
        if (!ok) cout << 0 << endl;
        else cout << endl;
    }
    return 0;
}