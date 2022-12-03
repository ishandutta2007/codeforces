//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll n, k;
        cin >> n >> k;
        if (k % 3) {
            if (n % 3) {
                cout << "Alice\n";
            } else {
                cout << "Bob\n";
            }
        } else {
            ll per = k + 1;
            if ((n % per) % 3 == 0 && n % per != k) {
                cout << "Bob\n";
            } else {
                cout << "Alice\n";
            }
        }
    }
    return 0;
}