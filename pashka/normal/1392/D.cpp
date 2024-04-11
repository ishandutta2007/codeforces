#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<string> g = {"RL", "RLL", "RRL", "RRLL"};
    int res = INT_MAX;
    for (int t = 0; t < 5; t++) {
        vector<int> d(n + 1, INT_MAX);
        d[0] = 0;
        for (int i = 0; i < n; i++) {
            if (d[i] == INT_MAX) continue;
            for (string p : g) {
                int j = i + p.size();
                if (j <= n) {
                    int c = 0;
                    for (int q = 0; q < p.size(); q++) {
                        if (s[i + q] != p[q]) c++;
                    }
                    d[j] = min(d[j], d[i] + c);
                }
            }
        }
//        cout << s << "\n";
//        for (int x : d) cout << x << " ";
//        cout << "\n";
        res = min(res, d[n]);
        s = s.substr(1, s.size() - 1) + s[0];
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve_test();
    }

    return 0;
}