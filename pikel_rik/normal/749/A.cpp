#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << n / 2 << "\n";
        for (int i = 0; i < n / 2; i++) {
            cout << "2 ";
        }
    }
    else {
        n -= 3;
        cout << 1 + n / 2 << "\n";
        cout << "3 ";
        for (int i = 0; i < n / 2; i++) {
            cout << "2 ";
        }
    }

    return 0;
}