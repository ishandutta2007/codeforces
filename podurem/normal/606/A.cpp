#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, x, y, z;
    cin >> a >> b >> c;
    cin >> x >> y >> z;
    int dick = max(0, a - x) / 2 + max(0, b - y) / 2 + max(0, c - z) / 2;
    int cock = max(0, x - a) + max(0, y - b) + max(0, z - c);
    if (cock <= dick) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}