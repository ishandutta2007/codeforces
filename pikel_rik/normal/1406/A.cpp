#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> cnt(101);
        for (int i = 0; i < n; i++) {
            cnt[a[i]]++;
        }

        int mex1 = 0, mex2 = 0;
        for (int i = 0; i <= 100; i++) {
            if (!cnt[i])
                break;
            mex1 = i + 1;
            cnt[i]--;
        }

        for (int i = 0; i <= 100; i++) {
            if (!cnt[i])
                break;
            mex2 = i + 1;
        }

        cout << mex1 + mex2 << '\n';
    }
    return 0;
}