#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    vector<vector<int>> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int y;
            cin >> y;
            y--;
            a[y].push_back(i);
            b[i].push_back(y);
        }
    }
    for (int first = 0; first < n; first++) {
        for (int i = 0; i < n; i++) {
            if (a[i].size() == 1 && i != first) {
                vector<int> q = {i};
                vector<int> s(n);
                for (int i = 0; i < n; i++) {
                    s[i] = a[i].size();
                }
                s[first]++;
                vector<bool> z(n - 1);
                vector<bool> zz(n);
                for (int j = 0; j < q.size(); j++) {
                    zz[q[j]] = true;
                    for (int x : a[q[j]]) {
                        if (!z[x]) {
                            z[x] = true;
                            for (int k : b[x]) {
                                s[k]--;
                                if (s[k] == 1) {
                                    q.push_back(k);
                                }
                            }
                        }
                    }
                }
//                for (int j = 0; j < n; j++) {
//                    if (!zz[j]) q.push_back(j);
//                }
                reverse(q.begin(), q.end());
                if (q.size() != n) continue;
                vector<int> r(n);
                for (int j = 0; j < n; j++) {
                    r[q[j]] = j;
                }
                bool ok = true;
                for (auto e : b) {
                    int mn = INT_MAX;
                    int mx = INT_MIN;
                    for (int x : e) {
                        mn = min(mn, r[x]);
                        mx = max(mx, r[x]);
                    }
                    if (mx - mn + 1 != e.size()) ok = false;
                }
                if (ok) {
                    for (int x : q) {
                        cout << x + 1 << " ";
                    }
                    cout << "\n";
                    return;
                }
            }
        }
    }
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