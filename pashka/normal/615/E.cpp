#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

// @author: pashka

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    long long n;
    cin >> n;
    if (n == 0) {
        cout << "0 0" << endl;
        return 0;
    }


    long long l = 0;
    long long r = (long long int) 1e9;
    while (r > l + 1) {
        long long m = (r + l) >> 1;
        if (m * (m + 1) >= (n + 2) / 3) {
            r = m;
        } else {
            l = m;
        }
    }

    n -= 3 * l * (l + 1);

    long long x, y;

    if (n <= r) {
        x = 2 * r - n;
        y = 2 * n;
    } else {
        n -= r;
        if (n <= r) {
            x = r - 2 * n;
            y = 2 * r;
        } else {
            n -= r;
            if (n <= r) {
                x = -r - n;
                y = 2 * r - 2 * n;
            } else {
                n -= r;
                if (n <= r) {
                    x = -2 * r + n;
                    y = -2 * n;
                } else {
                    n -= r;
                    if (n <= r) {
                        x = -r + 2 * n;
                        y = -2 * r;
                    } else {
                        n -= r;
                        x = r + n;
                        y = -2 * r + 2 * n;
                    }
                }
            }
        }
    }
    cout << x << " " << y << endl;


    return 0;
}