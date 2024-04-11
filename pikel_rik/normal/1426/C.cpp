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

        int cur = ceil(sqrt(n)), sum = cur;
        int moves = cur - 1;

        while (sum < n) {
            sum += cur;
            moves++;
        }

        cout << moves << '\n';
    }
    return 0;
}