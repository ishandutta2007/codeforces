#include <bits/stdc++.h>
#define int long long
using namespace std;
using lint = long long;
// #define TESTCASE
int solve();
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #ifdef TESTCASE
    int t; 
    cin >> t;
    while (t--) {
        solve();
    }
    #else
    solve();
    #endif
}

int solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    int mnx = a[0].first, mny = a[0].second;
    for (int i = 0; i < n; i++) {
        mnx = min(mnx, a[i].first);
        mny = min(mny, a[i].second);
    }
    for (int i = 0; i < n; i++) {
        a[i].first -= mnx;
        a[i].second -= mny;
    }

    if (n == 2) {
        cout << 1 << "\n";
        cout << 1 << "\n";
        return 0;
    }
    
    vector<int> ans1, ans2;
    while (ans1.size() == 0) {
        for (int i = 0; i < n; i++) {
            if ((a[i].first + a[i].second) % 2 == 0) {
                ans1.emplace_back(i);
            } else {
                ans2.emplace_back(i);
            }
        }

        if (ans1.size() == 0 || ans2.size() == 0) {
            ans1.clear();
            ans2.clear();
        } else {
            break;
        }

        if ((a[0].first + a[0].second) % 2 == 1) {
            for (int i = 0; i < n; i++) {
                a[i].first++;
            }
        }
        for (int i = 0; i < n; i++) {
            tie(a[i].first, a[i].second) = pair<int, int>{(a[i].first + a[i].second) / 2, (a[i].first - a[i].second) / 2};
        }
        mnx = a[0].first, mny = a[0].second;
        for (int i = 0; i < n; i++) {
            mnx = min(mnx, a[i].first);
            mny = min(mny, a[i].second);
        }
        for (int i = 0; i < n; i++) {
            a[i].first -= mnx;
            a[i].second -= mny;
        }
    }


    cout << ans1.size() << "\n";
    for (auto i : ans1) {
        cout << i + 1 << " ";
    }
    cout << "\n";

}