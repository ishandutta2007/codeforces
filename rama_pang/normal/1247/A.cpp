#include <bits/stdc++.h>
using namespace std;

int main() {
    int d1, d2;
    cin >> d1 >> d2;
    if (d1 == 9 && d2 == 1) {
        cout << "9 10\n";
    } else if (d2 - d1 != 1 && d2 - d1 != 0) {
        cout << -1 << "\n";
    } else if (d2 - d1 == 1) {
        cout << d1 << " " << d2 << "\n";
    } else {
        cout << d1 << "0 " << d2 << "1\n";
    }
}