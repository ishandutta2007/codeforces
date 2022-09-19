#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

void compress(vector<int> &x) {
    vector<int> xx = x;
    sort(xx.begin(), xx.end());
    for (int i = 0; i < x.size(); i++) {
        x[i] = lower_bound(xx.begin(), xx.end(), x[i]) - xx.begin();
    }
}

vector<int> vals;
vector<int> sums;

int size;

void add(int i, int x, int n, int L, int R) {
    if (R == L + 1) {
        vals[n] += x;
        sums[n] = (vals[n] > 0);
        return;
    }
    int M = (L + R) >> 1;
    if (i < M) {
        add(i, x, 2 * n + 1, L, M);
    } else {
        add(i, x, 2 * n + 2, M, R);
    }
    sums[n] = sums[2 * n + 1] + sums[2 * n + 2];
}

int sum(int l, int r, int n, int L, int R) {
    if (l >= R || L >= r) return 0;
    if (L >= l && R <= r) {
        return sums[n];
    }
    int M = (L + R) >> 1;
    return sum(l, r, 2 * n + 1, L, M) + sum(l, r, 2 * n + 2, M, R);
}

void init(int n) {
    size = 1;
    while (size < n) size *= 2;
    sums.assign(2 * size, 0);
    vals.assign(2 * size, 0);
}


void add(int i, int x) {
    add(i, x, 0, 0, size);
}

int sum(int l, int r) {
    return sum(l, r, 0, 0, size);
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    init(n);
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    compress(x);
    compress(y);
//    for (int i = 0; i < n; i++) {
//        cout << x[i] << " " << y[i] << "\n";
//    }

    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = {y[i], x[i]};
    }
    for (int i = 0; i < n; i++) {
        add(p[i].second, 1);
    }
    sort(p.begin(), p.end());
    long res = 0;
    for (int i = 0; i < n; i++) {
        long q = sum(0, n);
        res += q * (q + 1) / 2;
        add(p[i].second, -1);
        vector<int> c;
        c.push_back(-1);
        c.push_back(p[i].second);
        while (i < n - 1 && p[i + 1].first == p[i].first) {
            i++;
            add(p[i].second, -1);
            c.push_back(p[i].second);
        }
        c.push_back(n);
        for (int j = 0; j < c.size() - 1; j++) {
            q = sum(c[j] + 1, c[j + 1]);
            res -= q * (q + 1) / 2;
        }
//        cout << res << "\n";
    }
    cout << res;

    return 0;
}