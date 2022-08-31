#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int sum(ll x) {
    int ans = 0;
    while (x) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll n; int s;
        cin >> n >> s;

        ll pow = 10, temp = n;
        while (sum(n) > s) {
            if (n % pow) {
                n += pow - n % pow;
            }
            pow *= 10;
        }

        cout << n - temp << '\n';
    }
    return 0;
}