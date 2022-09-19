#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L
#define PI 3.141592653589793238462643383279502884L

#define long long long int

using std::vector;
using std::map;
using std::string;
using std::pair;
using std::cin;
using std::cout;
using std::cerr;

// @author: pashka

vector<int> min;
vector<int> max;

void set(int i, int x, int n, int l, int r) {
    if (r == l + 1) {
        min[n] = max[n] = x;
        return;
    }
    int m = (l + r) / 2;
    if (i < m) {
        set(i, x, 2 * n + 1, l, m);
    } else {
        set(i, x, 2 * n + 2, m, r);
    }
    max[n] = std::max(max[n * 2 + 1], max[n * 2 + 2]);
    min[n] = std::min(min[n * 2 + 1], min[n * 2 + 2]);
}

int find1(int x, int n, int l, int r) {
    if (max[n] < x) return -1;
    if (r == l + 1) {
        return l;
    }
    int m = (l + r) / 2;
    int res = find1(x, n * 2 + 1, l, m);
    if (res == -1) {
        res = find1(x, n * 2 + 2, m, r);
    }
    return res;
}

int find2(int x, int n, int l, int r) {
    if (min[n] > x) return -1;
    if (r == l + 1) {
        return l;
    }
    int m = (l + r) / 2;
    int res = find2(x, n * 2 + 1, l, m);
    if (res == -1) {
        res = find2(x, n * 2 + 2, m, r);
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;
    n += 2;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    int l = -1;
    int r = 1000000000;
    vector<int> to(n);
    while (r > l + 1) {
        int m = (l + r) / 2;
        min.assign(n * 4, MAX_INT);
        max.assign(n * 4, MIN_INT);
//        cout << m << "\n";
        for (int i = n - 1; i >= 0; i--) {
            int c1 = find1(x[i] + m + 1, 0, 0, n);
            int c2 = find2(x[i] - m - 1, 0, 0, n);
            if (c1 == -1) c1 = n;
            if (c2 == -1) c2 = n;
            int c = std::min(c1, c2);
            to[i] = c - 1;
            set(i, x[i], 0, 0, n);
        }
//        for (int i = 0; i < n; i++) {
//            cout << to[i] << " ";
//        }
//        cout << "\n";
        int c = 0;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (i > c) ok = false;
            c = std::max(c, to[i]);
        }
        if (ok) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << r << "\n";

    return 0;
}