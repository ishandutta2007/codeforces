#include <cstdio>
#include <iostream>

using namespace std;

int n, num, g;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    cin >> n;

    cin >> g;
    int m = g;
    for (int i = 1; i < n; ++i) {
        cin >> num;
        m = max(m, num);
        g = gcd(g, num);
    }
    //cout << m << " " << g << endl;
    if ((m / g - n) % 2 == 0) {
        cout << "Bob";
    } else {
        cout << "Alice";
    }

    return 0;
}