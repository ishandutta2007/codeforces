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

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);

    int n; cin >> n;
    int X = 0, Y = (1 << 10) - 1;
    for (int i = 0; i < n; ++i) {
        char c; int x;
        cin >> c >> x;
        if (c == '|') X |= x, Y |= x;
        else if (c == '&') X &= x, Y &= x;
        else X ^= x, Y ^= x;
    }
    int Xor = 0, And = (1 << 10) - 1, Or = 0;
    for (int i = 0; i < 10; ++i) {
        bool x = (X >> i) & 1, y = (Y >> i) & 1;
        if (x and !y) Xor += (1 << i);
        if (x and y) Or += (1 << i);
        if (!x and !y) And -= (1 << i);
    }
    cout << "3\n";
    cout << "| " << Or << '\n';
    cout << "& " << And << '\n';
    cout << "^ " << Xor << '\n';
    return 0;
}