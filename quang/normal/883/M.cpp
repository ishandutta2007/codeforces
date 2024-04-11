#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y, u, v;
    cin >> x >> y >> u >> v;
    int ans = abs(x - u) + abs(y - v);
    if (x == u) ans += 1;
    if (y == v) ans += 1;
    ans = (ans + 2) * 2;
    cout << ans << endl;
}