#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

vector<string> l = {"x^y^z", "x^z^y", "(x^y)^z", "(x^z)^y", "y^x^z", "y^z^x", "(y^x)^z", "(y^z)^x", "z^x^y", "z^y^x", "(z^x)^y", "(z^y)^x"};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ld x, y, z;
    cin >> x >> y >> z;

    if (x < 1 and y < 1 and z < 1) {
        ld ans = pow(x, pow(y, z));
        int cur = 0;

        if (pow(x, pow(z, y)) > ans) {
            ans = pow(x, pow(z, y));
            cur = 1;
        }
        if (pow(x, y * z) > ans) {
            ans = pow(x, y * z);
            cur = 2;
        }
        if (pow(y, pow(x, z)) > ans) {
            ans = pow(y, pow(x, z));
            cur = 4;
        }
        if (pow(y, pow(z, x)) > ans) {
            ans = pow(y, pow(z, x));
            cur = 5;
        }
        if (pow(y, x * z) > ans) {
            ans = pow(y, x * z);
            cur = 6;
        }
        if (pow(z, pow(x, y)) > ans) {
            ans = pow(z, pow(x, y));
            cur = 8;
        }
        if (pow(z, pow(y, x)) > ans) {
            ans = pow(z, pow(y, x));
            cur = 9;
        }
        if (pow(z, x * y) > ans) {
            ans = pow(z, x * y);
            cur = 10;
        }
        cout << l[cur] << "\n";
        return 0;
    }

    ld ans = 0;
    int cur = 0;

    if (x < 1)
        ans = -1e18;
    else if (x == 1)
        ans = -1000;
    else ans = z * log(y) + log(log(x));

    if (x > 1 and y * log(z) + log(log(x)) > ans) {
        ans = y * log(z) + log(log(x));
        cur = 1;
    }

    if (x > 1 and log(y) + log(z) + log(log(x)) > ans) {
        ans = log(y) + log(z) + log(log(x));
        cur = 2;
    }

    if (y == 1 and ans < -1000) {
        ans = -1000;
        cur = 4;
    }
    if (y > 1 and z * log(x) + log(log(y)) > ans) {
        ans = z * log(x) + log(log(y));
        cur = 4;
    }

    if (y > 1 and x * log(z) + log(log(y)) > ans) {
        ans = x * log(z) + log(log(y));
        cur = 5;
    }

    if (y > 1 and log(x) + log(z) + log(log(y)) > ans) {
        ans = log(x) + log(z) + log(log(y));
        cur = 6;
    }

    if (z == 1 and ans < -1000) {
        ans = -1000;
        cur = 8;
    }

    if (z > 1 and y * log(x) + log(log(z)) > ans) {
        ans = y * log(x) + log(log(z));
        cur = 8;
    }

    if (z > 1 and x * log(y) + log(log(z)) > ans) {
        ans = x * log(y) + log(log(z));
        cur = 9;
    }

    if (z > 1 and log(x) + log(y) + log(log(z)) > ans) {
        ans = log(x) + log(y) + log(log(z));
        cur = 10;
    }

    cout << l[cur];
    return 0;
}