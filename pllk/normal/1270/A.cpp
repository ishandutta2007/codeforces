#include <iostream>

using namespace std;

void lol() {
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    int v, x;
    for (int i = 1; i <= k1; i++) {cin >> x; if (x == n) v = 1;}
    for (int i = 1; i <= k2; i++) {cin >> x; if (x == n) v = 2;}
    if (v == 1) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) lol();
}