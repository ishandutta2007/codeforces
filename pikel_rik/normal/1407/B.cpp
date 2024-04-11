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
        sort(a.rbegin(), a.rend());

        int cur = a[0];
        for (int i = 1; i < n; i++) {
            int mx = i;
            for (int j = i + 1; j < n; j++) {
                if (__gcd(cur, a[j]) > __gcd(cur, a[mx])) {
                    mx = j;
                }
            }
            cur = __gcd(cur, a[mx]);
            swap(a[i], a[mx]);
        }

        for (int i : a) cout << i << ' ';
        cout << '\n';
    }
    return 0;
}