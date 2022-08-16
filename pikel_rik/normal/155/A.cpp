#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    cin >> n;

    cin >> a;
    int min = a, max = a, c = 0;
    for (int i = 1; i < n; i++) {
        cin >> a;
        if (a > max) {
            max = a;
            c += 1;
        }
        else if (a < min) {
            min = a;
            c += 1;
        }
    }

    cout << c;
    return 0;
}