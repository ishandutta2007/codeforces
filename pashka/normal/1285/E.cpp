#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    int n;
    cin >> n;
    vector<pair<int, int>> e;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        e.push_back({2 * l, i});
        e.push_back({2 * r + 1, i});
    }
    sort(e.begin(), e.end());

    vector<bool> z(n);
    int cnt = 0;
    int xr = 0;

    vector<pair<int, int>> a;

    a.push_back({0, 0});

    for (int i = 0; i < 2 * n; i++) {
        int x = e[i].first;
        int k = e[i].second;
        if (z[k]) {
            z[k] = false;
            cnt--;
        } else {
            z[k] = true;
            cnt++;
        }
        xr ^= k;
        if (i == 2 * n - 1 || e[i + 1].first != e[i].first) {
            a.push_back({cnt, xr});
//            cout << cnt << ":" << xr << " ";
        }
    }
    cout << "\n";

    int ss = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i].first > 0) {
            if (i == 0 || a[i - 1].first == 0) {
                ss++;
            }
        }
    }

    int m = a.size();
    vector<int> res(n);
    for (int i = 1; i < a.size() - 1; i++) {
        if (a[i].first == 1) {
            if (a[i - 1].first > 1 && a[i + 1].first > 1) {
                res[a[i].second]++;
            }
            if (a[i - 1].first == 0 && a[i + 1].first == 0) {
                res[a[i].second]--;
            }
        }
    }

    int mx = INT_MIN;
    for (int i = 0; i < n; i++) {
//        cout << res[i] << " ";
        mx = max(mx, res[i]);
    }
//    cout << "\n";
    cout << ss + mx << "\n";

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