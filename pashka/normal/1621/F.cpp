#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

struct test {
    void solve() {
        int n;
        long a, b, c;
        cin >> n >> a >> b >> c;
        string s;
        cin >> s;
        long aa = 0;
        long bb = 0;
        vector<int> q;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0' && s[i + 1] == '0') aa++;
            if (s[i] == '1' && s[i + 1] == '1') bb++;
        }
        int cc = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0' && (i == 0 || s[i - 1] == '1')) {
                cc++;
                int j = i;
                while (j < n && s[j] == '0') j++;
                if (i > 0 && j < n) {
                    q.push_back(j - i);
                }
            }
        }
        sort(q.begin(), q.end());

        if (bb > aa) {
            long res = aa * a + (aa + 1) * b;
            if (b - c > 0) {
                long x = min(bb + (int)q.size(), aa + cc + 1);
                res += (b - c) * (x - aa - 1);
            }
            cout << res << "\n";
        } else {
            long res = a * min(bb + 1, aa) + bb * b;
            if (b - c > 0) {
                long bbb = bb;
                long x = 0;
                for (int t : q) {
                    if (bbb >= t - 1) {
                        bbb -= t - 1;
                        x++;
                    }
                }
                res += (b - c) * x;
            }
            cout << res << "\n";
        }
        }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        test t;
        t.solve();
    }

    return 0;
}