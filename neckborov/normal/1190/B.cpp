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
    int n;
    cin >> n;
    ll kek = 0;
    vector<int> a(n);
    for (int& i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    int pairs = 0;
    for (int i = 0; i < n; i++) {
        kek += a[i] - i;
        if (a[i] < i) {
            cout << "cslnb";
            return 0;
        }
        if (i > 1 && a[i] == a[i - 1] && a[i] == a[i - 2] + 1) {
            cout << "cslnb";
            return 0;
        }
        if (i && a[i] == a[i - 1]) {
            pairs++;
        }
    }
    if (pairs > 1 || kek % 2 == 0) {
        cout << "cslnb";
    } else {
        cout << "sjfnb";
    }
    return 0;
}