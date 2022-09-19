#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

vector<int> d;
vector<int> dl;
int k;

void update(int x, int y) {
//    cout << "up " << x << " " << d[x] << " " << y << "\n";
    for (int i = 0; i < k; i++) {
        int xx = x ^ (1 << i);
        int dd = __builtin_popcount(xx ^ y);
        if (d[xx] > dd) {
            d[xx] = dd;
            dl[xx] = dl[x];
            update(xx, y);
        }
    }
}

int read() {
    string s;
    cin >> s;
    int x = 0;
    int i = 0;
    for (char c : s) {
        x += (c - '0') << i;
        i++;
    }
    return x;
}

int apply(int x, vector<int> p) {
    int k = p.size();
    int y = 0;
    for (int i = 0; i < k; i++) {
        y += ((x >> i) & 1) << p[i];
    }
    return y;
}

string bin(int x) {
    string s(k, '0');
    for (int i = 0; i < k; i++) {
        if (x & (1 << i)) {
            s[i] = '1';
        }
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m >> k;
    d.assign(1 << k, k + 1);
    dl.resize(1 << k);
    int st = read();
    int fn = read();
    vector<vector<int>> p(n + 1, vector<int>(k));
    for (int i = 0; i < k; i++) p[0][i] = i;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        p[i + 1] = p[i];
        swap(p[i + 1][x], p[i + 1][y]);
    }
//    vector<vector<int>> rp(n + 1, vector<int>(k));
//    for (int i = 0; i <= n; i++) {
//        for (int j = 0; j < k; j++) {
//            rp[i][p[i][j]] = j;
//        }
////        for (int x : rp[i]) cout << x << " ";
////        cout << "\n";
//    }
    int res = k + 1;
    int resl = 0, resr = 0;
    for (int i = 0; i + m <= n; i++) {
        int xx = apply(st, p[i]);
        d[xx] = 0;
        dl[xx] = i;
        update(xx, xx);
//        cout << "! " << bin(xx) << "\n";
        int yy = apply(fn, p[i + m]);
//        cout << "? " << bin(yy) << "\n";
        if (d[yy] < res) {
            res = d[yy];
            resl = dl[yy];
            resr = i + m;
        }
    }
//    cout << k - res << "\n";
    cout << k - res << " " << resl + 1 << " " << resr << "\n";

    return 0;
}