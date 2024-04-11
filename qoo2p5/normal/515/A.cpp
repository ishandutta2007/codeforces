#include <bits/stdc++.h>

using namespace std;

int a, b, s;

int mod(int x, int y) {
    int result = x % y;
    if (result < 0) {
        result += y;
    }

    return result;
}

int main() {
    cin >> a >> b >> s;

    if(mod(s, 2) != mod(a + b, 2) || s < abs(a) + abs(b)) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }

    return 0;
}