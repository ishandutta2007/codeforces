#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int mod = 998244353;
const int inf = 2e9 + 5;

int compare(const string &a, const string &b) {
    int ans = 0;
    for (int i = 0; i < a.length(); i++) {
        ans += (a[i] != b[i]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<string> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<set<char>> ch(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ch[j].insert(a[i][j]);
            }
        }

        int c = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                c = max(c, compare(a[i], a[j]));
            }
        }

        if (c > 2) {
            cout << "-1\n";
            continue;
        }

        string ans = a[0];
        bool flag = false;

        for (int i = 0; i < m; i++) {
            for (char x : ch[i]) {
                ans[i] = x;
                int ma = 0;
                for (int j = 1; j < n; j++) {
                    ma = max(ma, compare(ans, a[j]));
                }
                if (ma <= 1) {
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
            ans[i] = a[0][i];
        }

        if (flag) cout << ans << "\n";
        else cout << "-1\n";
    }
    return 0;
}