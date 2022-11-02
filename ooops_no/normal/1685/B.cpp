#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld double
#define ll long long

mt19937 rnd(51);

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        string s;
        cin >> s;
        int cnt = 0, n = s.size(), res = 0;
        for (auto to : s) {
            cnt += (to == 'A');
        }
        if (cnt != a + c + d) {
            cout << "NO\n";
            continue;
        }
        vector<int> arr, arr2;
        for (int i = 0; i < n;) {
            int j = i;
            while (j + 1 < n && s[j] != s[j + 1]) {
                j++;
            }
            int len = (j - i + 1);
            if (len % 2 == 1) {
                res += len / 2;
            } else if (s[i] == 'A') {
                arr.pb(len / 2);
            } else {
                arr2.pb(len / 2);
            }
            i = j + 1;
        }
        sort(arr.begin(), arr.end());
        for (auto to : arr) {
            if (to <= c) {
                c -= to;
            } else {
                int need = c;
                c -= need;
                to -= need;
                d -= to - 1;
            }
        }
        sort(arr2.rbegin(), arr2.rend());
        int mn = min(res, c);
        c -= mn;
        res -= mn;
        for (auto to : arr2) {
            if (c > 0) {
                if (to - 1 <= c) {
                    c -= to - 1;
                } else {
                    d -= (to - c - 1);
                    c = 0;
                }
            } else {
                d = max(0, d - to);
            }
        }
        if (c + d <= res) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}