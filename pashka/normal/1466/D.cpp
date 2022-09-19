#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

struct test {

    void solve() {
        int n;
        cin >> n;
        vector<pair<long, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
        }
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            a[x].second++;
            a[y].second++;
        }
        sort(a.rbegin(), a.rend());
        long s = 0;
        for (int i = 0; i < n; i++) s += a[i].first;
        cout << s;
        for (int i = 0; i < n; i++) a[i].second--;
        int j = 0;
        for (int i = 0; i < n - 2; i++) {
            while (a[j].second == 0) j++;
            a[j].second--;
            s += a[j].first;
            cout << " " << s;
        }
        cout << "\n";
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