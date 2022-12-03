#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int prev = 0;
    int f = 1;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (f && a < prev) {
            cout << "NO";
            return 0;
        }
        if (!f && a > prev) {
            cout << "NO";
            return 0;
        }
        if (a == n) {
            f = 0;
        }
        prev = a;
    }
    cout << "YES";
    return 0;
}