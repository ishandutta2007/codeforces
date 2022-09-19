#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int, int>> s(n);
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i].first;
        s[i].second = i + 1;
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    sort(t.begin(), t.end());
    vector<pair<int, int>> d;
    vector<vector<int>> res;
    for (int i = 0; i < n; i++) {
        int x = t[i] - s[i].first;
//        cout << i << " " << x << "\n";
        if (x > 0) {
            d.push_back({x, i});
        } else {
            x = -x;
            while (x > 0) {
                if (d.size() == 0) {
                    cout << "NO";
                    return 0;
                }
                int y = min(d.back().first, x);
                if (y > 0) {
                    res.push_back({d.back().second, i, y});
                }
                d.back().first -= y;
                x -= y;
                if (d.back().first == 0) {
                    d.pop_back();
                }
            }
        }
    }
    if (d.size() > 0) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    cout << res.size() << "\n";
    for (auto p : res) {
        cout << s[p[0]].second << " " << s[p[1]].second << " " << p[2] << "\n";
    }

    return 0;
}