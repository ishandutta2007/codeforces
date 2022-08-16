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
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector<int> cnt0(k), cnt1(k);
        for (int i = 0; i < n; i++) {
            if (s[i] == '?')
                continue;
            if (s[i] == '0')
                cnt0[i % k]++;
            else cnt1[i % k]++;
        }

        int c0 = 0, c1 = 0;
        bool bad = false;

        for (int i = 0; i < k; i++) {
            if (cnt0[i] and cnt1[i])
                bad = true;
            else if (cnt0[i])
                c0++;
            else if (cnt1[i])
                c1++;
        }

        if (bad or c0 > k / 2 or c1 > k / 2)
            cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}