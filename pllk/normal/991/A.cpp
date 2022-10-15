#include <iostream>

using namespace std;

int a, b, c, n;

int main() {
    cin >> a >> b >> c >> n;
    a -= c;
    b -= c;
    if (a >= 0 && b >= 0 && a+b+c < n) {
        cout << n-(a+b+c) << "\n";
    } else {
        cout << "-1\n";
    }
}