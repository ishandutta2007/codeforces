#include <iostream>

using namespace std;

int ext_euclid(int a, int b, int &x, int &y) {
    if (a % b == 0) {
        x = 0, y = 1;
        return b;
    }

    int nx, ny;
    int g = ext_euclid(b, a % b, nx, ny);

    x = ny;
    y = nx - x * (a / b);

    return g;
}
int main() {

    int n;
    cin >> n;

    int st = n;

    int p1 = -1, p2 = -1;
    for (int i = 2; i*i <= n; ++i) {
        if (n % i == 0) {
            (p1 == -1 ? p1 : p2) = i;
            while (n % i == 0)
                n /= i;
        }
    }

    if (n > 1) (p1 == -1 ? p1 : p2) = n;

    if (p2 == -1) {
        cout << "NO" << endl;
        return 0;
    }

    int a, b;
    int g = ext_euclid(p1, p2, a, b);
    a = -a, b = -b;

    cout << "YES" << endl << 2 << endl;

    if (a < 0) {
        a += st / p1;
    } else {
        b += st / p2;
    }

    cout << a << " " << (st / p1) << endl;
    cout << b << " " << (st / p2) << endl;

    return 0;
}