#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

void solve() {
    int x, y;
    cin >> x >> y;
    int a, b;
    cin >> a >> b;
    if (x > y) swap(x, y);
    if (2 * a > b) {
        cout << 1LL * a * (y - x) + 1LL * b * x << "\n";
    } else cout << 1LL * a * (x + y) << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) solve();
    return 0;
}