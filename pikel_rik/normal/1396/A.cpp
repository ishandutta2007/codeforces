#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n;
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    if (n == 1) {
        cout << "1 1\n" << -a[0] << "\n";
        cout << "1 1\n" << 0 << "\n";
        cout << "1 1\n" << 0 << "\n";
        return 0;
    }

    cout << "1 " << n << "\n";
    for (int i = 0; i < n; i++) {
        int m = n - 1 - (a[i] % (n - 1) + n - 1) % (n - 1);
        cout << m * (ll)n << " ";
        a[i] += m * (ll)n;
    }
    cout << '\n';

    cout << "1 " << n - 1 << "\n";
    for (int i = 0; i < n - 1; i++) {
        cout << -a[i] << " ";
        a[i] = 0;
    }
    cout << '\n';

    cout << "2 " << n << "\n";
    for (int i = 1; i < n; i++) {
        cout << -a[i] << " ";
        a[i] = 0;
    }
    return 0;
}