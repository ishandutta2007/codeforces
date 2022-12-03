//#pragma GCC optimize("O3")
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
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    int d;
    cin >> d;
    cout << max(0, d - a[1] + a[0]) + max(0, d - a[2] + a[1]);
    return 0;
}