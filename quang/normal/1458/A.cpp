#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, m;
long long a[N], b[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    long long g = 0;
    for (int i = 2; i <= n; i++) {
        g = __gcd(g, abs(a[1] - a[i]));
    }
    for (int i = 1; i <= m; i++) {
        cout << __gcd(g, a[1] + b[i]) << ' ';
    }
    cout << '\n';
    return 0;
}