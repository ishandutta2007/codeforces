#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    long long n; cin >> n;
    vector<int> ans(2*n+1);

    for (int i = 1; i <= n; i++) {
        int j = 2*i;

        if (i % 2) {
            ans[i] = j;
            ans[i+n] = j-1;
        } else {
            ans[i+n] = j;
            ans[i] = j-1;
        }
    }

    set<int> sum;
    for (int i = 1; i <= 2*n; i++) {
        ans.push_back(ans[i]);
    }

    vector<int> pre(ans.size());
    for (int i = 1; i < pre.size(); i++) {
        pre[i] = pre[i-1] + ans[i];
    }

    for (int i = 2*n+1; i <= 4*n; i++) {
        sum.insert(pre[i] - pre[i-n]);
    }

    if (sum.size() > 2) {
        cout << "NO";
        return 0;
    }
    if (sum.size() == 1) {
        cout << "YES\n";
        for (int i = 1; i <= 2*n; i++) {
            cout << ans[i] << ' ';
        }
        return 0;
    }

    vector<int> k(sum.begin(), sum.end());
    if (abs(k[0] - k[1]) > 1) {
        cout << "NO";
        return 0;
    } else {
        cout << "YES\n";
        for (int i = 1; i <= 2*n; i++) {
            cout << ans[i] << ' ';
        }
        return 0;
    }

    return 0;
}