#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        if (a % b != 0)
            cout << b - a % b << "\n";
        else
            cout << "0" << "\n";
    }
    return 0;
}