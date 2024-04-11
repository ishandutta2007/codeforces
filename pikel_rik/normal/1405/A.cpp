#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n);
        for (auto& i : p) cin >> i;

        reverse(p.begin(), p.end());
        for (int i : p) cout << i << ' '; cout << '\n';
    }
    return 0;
}