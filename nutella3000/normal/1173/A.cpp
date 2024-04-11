#include<bits/stdc++.h>

using namespace std;
#define int long long
const int max_n = 104;


signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    // online submission
#endif
    int a, b, c;
    cin >> a >> b >> c;
    int d = a - b;
    if (abs(d) <= c && c > 0) cout << "?";
    else if (d == 0) cout << 0;
    else if (d < 0) cout << "-";
    else cout << "+";
}