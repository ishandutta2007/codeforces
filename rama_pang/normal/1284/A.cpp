#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    lint n, m;
    cin >> n >> m;
    vector<string> s(n), t(m);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> t[i];
    }
    int q;
    cin >> q;
    lint lcm = n * m / __gcd(n, m);
    while (q--) {
        lint year;
        cin >> year;
        year--;
        int pt1 = year, pt2 = year;
        pt1 %= n;
        pt2 %= m;
        cout << s[pt1] << t[pt2] << "\n";
    }


}