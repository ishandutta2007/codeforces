#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());

    vector<int> d(n + 1, INT_MAX); // d[i] = min    i
    d[0] = 0;
    vector<int> p(n + 1);

    for (int i = 0; i < n; i++) {
        if (d[i] == INT_MAX) continue;
        for (int j = 3; j <= 5; j++) {
            if (i + j > n) break;
            int dd = d[i] + a[i + j - 1].first - a[i].first;
            if (dd < d[i + j]) {
                d[i + j] = dd;
                p[i + j] = i;
            }
        }
    }
    int x = n;
    int k = 0;
    vector<int> res(n);
    while (x > 0) {
        int y = p[x];
        k++;
        for (int i = y; i < x; i++) {
            res[a[i].second] = k;
        }
        x = y;
    }
    cout << d[n] << " " << k << "\n";
    for (int i = 0; i < n; i++) cout << res[i] << " ";
    cout << "\n";

    return 0;
}