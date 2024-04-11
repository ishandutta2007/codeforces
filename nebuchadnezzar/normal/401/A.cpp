#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int n, x, bal, num;

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        bal += num;
    }
    bal = abs(bal);
    cout << (bal + x - 1) / x;
    return 0;
}