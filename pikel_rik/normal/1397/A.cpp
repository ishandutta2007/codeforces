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

        vector<int> cnt(26);

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (char ch : s)
                cnt[ch - 'a']++;
        }

        bool ok = true;
        for (int i = 0; i < 26; i++) {
            ok &= cnt[i] % n == 0;
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}