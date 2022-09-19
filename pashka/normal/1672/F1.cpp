#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka
struct test {
    void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }
        vector<vector<int>> c(n);
        vector<pair<int, int>> b(n);
        for (int i = 0; i < n; i++) {
            b[i].second = i;
            b[a[i]].first++;
            c[a[i]].push_back(i);
        }
        sort(b.rbegin(), b.rend());
        vector<int> res(n);
        vector<int> d(n);
        for (int i = 0; i < n; i++) d[i] = b[i].first;
        int j = 1;
        for (int i = 0; i < n; i++) {
            for (int t = 0; t < b[i].first; t++) {
                while (j < n && d[j] == 0) j++;
                int x;
                if (j == n) {
                    x = 0;
                } else {
                    d[j]--;
                    x = j;
                }
                res[c[b[i].second].back()] = b[x].second;
                c[b[i].second].pop_back();
            }
        }
        for (int i = 0; i < n; i++) cout << res[i] + 1 << " ";
        cout << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        test().solve();
    }

    return 0;
}