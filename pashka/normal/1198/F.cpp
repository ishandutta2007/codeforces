#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

int a[100000];
int r[100000];
int n;

int gcd(int a, int b) {
    while (b > 0) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

bool bt(int i, int x, int y) {
    if (x == 1 && y == 1) {
        return true;
    }
    if (i == n) {
        return false;
    }
    int xx = gcd(x, a[i]);
    int yy = gcd(y, a[i]);
    if (xx == x && yy == y) {
        return bt(i + 1, x, y);
    } else {
        if (xx != x) {
            r[i] = 0;
            if (bt(i + 1, xx, y)) return true;
        }
        if (yy != y && i > 0) {
            r[i] = 1;
            if (bt(i + 1, x, yy)) return true;
        }
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    if (bt(0, 0, 0)) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            cout << r[i] + 1 << " ";
        }
    } else {
        cout << "NO\n   ";
    }

    return 0;
}