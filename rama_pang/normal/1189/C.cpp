#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<pair<int, int>>> s(n, vector<pair<int, int>>(20));
    for (int i = 0; i < n; i++) {
        s[i][0].first = a[i];
        s[i][0].second = 0;
    }

    for (int j = 1; j < 20; j++) {
        for (int i = 0; i < n; i++) {
            if (i + (1 << j) - 1 < n) {
                s[i][j].first = s[i][j - 1].first + s[i + (1 << (j - 1))][j - 1].first;
                s[i][j].second = s[i][j - 1].second + s[i + (1 << (j - 1))][j - 1].second;
                if (s[i][j].first >= 10) {
                    s[i][j].first -= 10;
                    s[i][j].second++;
                }
            }
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int d = log2(r - l + 1);
        cout << s[l][d].second << "\n";
    }

    return 0;
}