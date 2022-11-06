#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vint;
typedef pair<int, int> pint;
const double PI = 3.14159265358979323846;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
// cout << fixed << setprecision(20);

int n, l, r;

signed main() {
    cin >> n >> l >> r;
    cout << (n - l + (1 << l) - 1) << " " << (1 << r) - 1 + (n - r) * (1 << r - 1) << endl;
}