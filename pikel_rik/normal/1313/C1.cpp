#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 3e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    vector<int> ansv;

    for (int i = 0; i < n; i++) {
        vector<int> tempv(n);
        tempv[i] = a[i];
        int cur = a[i];

        for (int j = i - 1; j >= 0; j--) {
            cur= min(a[j], cur);
            tempv[j] = cur;
        }

        cur = a[i];
        for (int j = i + 1; j < n; j++) {
            cur= min(a[j], cur);
            tempv[j] = cur;
        }
        ll temp = accumulate(tempv.begin(), tempv.end(), 0ll);
        if (temp > ans) {
            ans = temp;
            ansv = tempv;
        }
    }

    for (int i : ansv) cout << i << ' '; cout << '\n';
    return 0;
}