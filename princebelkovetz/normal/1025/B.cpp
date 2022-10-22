#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <cassert>
#include <bitset>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    int n; cin >> n;
    int ans = 0, X = 0, Y = 0;
    for (int i = 0, x, y; i < n; ++i) {
        cin >> x >> y;
        ans = gcd(ans, x * y);
        X = x, Y = y;
    }
    for (int i = 2; i * i <= X; ++i) {
        if (X % i) continue;
        if (ans % i == 0) {
            cout << i << '\n';
            return 0;
        }
        if (ans % (X / i) == 0) {
            cout << (X / i) << '\n';
            return 0;
        }
    }
    if (ans % X == 0) {
        cout << X << '\n';
        return 0;
    }
    for (int i = 2; i * i <= Y; ++i) {
        if (Y % i) continue;
        if (ans % i == 0) {
            cout << i << '\n';
            return 0;
        }
        if (ans % (Y/ i) == 0) {
            cout << (Y / i) << '\n';
            return 0;
        }
    }
    if (ans % Y == 0) {
        cout << Y << '\n';
        return 0;
    }
    
    cout << -1 << '\n';

    return 0;
}