#include <bits/stdc++.h>

using namespace std;

const int N = 100010;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x, y, z, t1, t2, t3;
    cin >> x >> y >> z >> t1 >> t2 >> t3;
    int stairs = abs(x - y) * t1;
    int ele = abs(x - z) * t2 + abs(x - y) * t2 + t3 * 3;
    if (ele <= stairs) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}