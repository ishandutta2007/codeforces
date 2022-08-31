#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int N = 1e5 + 5;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    map<int, int> mp;

    for (int i = 0, b, d; i < n; i++) {
        cin >> b >> d;
        mp[b]++;
        mp[d]--;
    }

    int mx = 0, year = 1, cur = 0;
    for (auto& [x, c] : mp) {
        cur += c;
        if (cur > mx) {
            mx = cur;
            year = x;
        }
    }

    cout << year << ' ' << mx << '\n';
    return 0;
}