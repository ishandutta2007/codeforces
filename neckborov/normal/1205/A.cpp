//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    vector<int> a(n * 2);
    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            a[i - 1] = i;
        } else {
            a[i - 1] = n * 2 - i + 2;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            a[n + i - 1] = i + 1;
        } else {
            a[n + i - 1] = n * 2 - i + 1;
        }
    }
    for (int i = 0; i < n * 2; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}