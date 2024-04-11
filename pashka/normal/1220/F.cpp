#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

typedef long item;
item zeroAdd = 0;

item add(item a, item b) {
    return a + b;
}

item zeroSum = 0;

item sum(item a, item b) {
    return a > b ? a : b;
}

vector<item> sums;
vector<item> adds;

int size;

void propagate(int n) {
    adds[2 * n + 1] = add(adds[2 * n + 1], adds[n]);
    sums[2 * n + 1] = add(sums[2 * n + 1], adds[n]);
    adds[2 * n + 2] = add(adds[2 * n + 2], adds[n]);
    sums[2 * n + 2] = add(sums[2 * n + 2], adds[n]);
    adds[n] = zeroAdd;
}

void add(int l, int r, int x, int n, int L, int R) {
    if (l >= R || L >= r) return;
    if (L >= l && R <= r) {
        adds[n] = add(adds[n], x);
        sums[n] = add(sums[n], x);
        return;
    }
    int M = (L + R) >> 1;
    propagate(n);
    add(l, r, x, 2 * n + 1, L, M);
    add(l, r, x, 2 * n + 2, M, R);
    sums[n] = sum(sums[2 * n + 1], sums[2 * n + 2]);
}

item sum(int l, int r, int n, int L, int R) {
    if (l >= R || L >= r) return zeroSum;
    if (L >= l && R <= r) {
        return sums[n];
    }
    int M = (L + R) >> 1;
    propagate(n);
    return sum(sum(l, r, 2 * n + 1, L, M), sum(l, r, 2 * n + 2, M, R));
}

void init(int n) {
    size = 1;
    while (size < n) size *= 2;
    sums.assign(2 * size, zeroSum);
    adds.assign(2 * size, zeroAdd);
}

void init(vector<item> a) {
    int n = a.size();
    init(n);
    size = 1;
    while (size < n) size *= 2;
    sums.assign(2 * size, zeroSum);
    adds.assign(2 * size, zeroAdd);
    for (int i = 0; i < n; i++) {
        sums[size - 1 + i] = a[i];
    }
    for (int i = size - 2; i >= 0; i--) {
        sums[i] = sum(sums[2 * i + 1], sums[2 * i + 2]);
    }
}

void add(int l, int r, int x) {
//    cout << "add " << l << " " << r << " " << x << "\n";
    add(l, r, x, 0, 0, size);
}

item sum(int l, int r) {
    return sum(l, r, 0, 0, size);
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    vector<int> p(2 * n, -1);
    vector<int> r(2 * n, -1);
    init(2 * n);
    int res = MAX_INT;
    int pres = -1;
    for (int i = 0; i < 2 * n; i++) {
        int x = i - 1;
        int y = -1;
        while (x != -1 && a[i] < a[x]) {
            y = x;
            x = p[x];
        }
        if (y != -1) {
            p[y] = i;
        }
        p[i] = x;
        if (x >= -1) {
            r[x] = i;
        }
        add(x + 1, i, 1);
        int d = x == -1 ? 1 : sum(x, x + 1) + 1;
        add(i, i + 1, d);
        if (i >= n) {
            int x = r[i - n];
            if (x != -1) {
                p[x] = p[i - n];
            }
            if (p[i - n] == -1) {
                add(i - n, i + 1, -1);
            } else {
                add(i - n, p[i - n], -1);
            }
//            for (int j = i - n + 1; j <= i; j++) {
//                cout << p[j] << " ";
//            }
//            cout << "\n";
//            for (int j = i - n + 1; j <= i; j++) {
//                cout << sum(j, j + 1) << " ";
//            }
//            cout << "\n";
            int ss = sum(i - n + 1, i + 1);
            int pp = (i - n + 1) % n;
            if (ss < res) {
                res = ss;
                pres = pp;
            }
//            cout << pp << " " << ss << "\n";
        }
    }
    cout << res << " " << pres;

    return 0;
}