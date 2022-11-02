#include <bits/stdc++.h>
#define pb push_back
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
signed main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % k) {
        cout << "No" << endl;
        return 0;
    }

    vector<int> ans(1, 1);
    int cur = a[0];
    for (int i = 1; i < n; ++i) {
        // cout << ans.back() << " " << cur << endl;
        if (cur < sum / k) {
            cur += a[i];
            ans.back()++;
        }
        else if (cur == sum / k) {
            ans.pb(1);
            cur = a[i];
        }
        else {
            cout << "No" << endl;
            return 0;
        }
    }
    if (cur != sum / k) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    for (auto &i : ans) {
        cout << i << " ";
    }

    return 0;
}