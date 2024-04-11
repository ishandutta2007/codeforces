#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);

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

        vector<int> temp = a;
        int idx = find(temp.begin(), temp.end(), 1) - temp.begin();

        bool ans = false;
        {
            bool ok = true;
            for (int i = idx + 1; i < n; i++) {
                if (a[i] != 1 + a[i - 1]) {
                    ok = false;
                }
            }
            for (int i = 0; i < idx; i++) {
                if (a[i] != 1 + a[(i + n - 1) % n]) {
                    ok = false;
                }
            }
            ans |= ok;
        }

        {
            bool ok = true;
            for (int i = idx - 1; i >= 0; i--) {
                if (a[i] != 1 + a[i + 1]) {
                    ok = false;
                }
            }
            for (int i = n - 1; i > idx; i--) {
                if (a[i] != 1 + a[(i + 1) % n]) {
                    ok = false;
                }
            }
            ans |= ok;
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }
    return 0;
}