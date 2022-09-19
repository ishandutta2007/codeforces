#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

vector<int> p;
vector<int> sv;
vector<int> se;
vector<vector<long>> d;
int get(int x) {
    if (p[x] != x) p[x] = get(p[x]);
    return p[x];
}

const long MOD = 998244353;

void join(int x, int y) {
    if (sv[x] > sv[y]) swap(x, y);
    vector<long> dd(sv[x] + sv[y] + 1);
    for (int i = 1; i <= sv[x]; i++) {
        for (int j = 1; j <= sv[y]; j++) {
            dd[i + j] += d[x][i] * d[y][j];
            dd[i + j] %= MOD;
        }
    }
    for (int i = 1; i <= sv[x] + sv[y]; i++) {
        d[y][i] = dd[i];
    }
    p[x] = y;
    sv[y] += sv[x];
    se[y] += se[x] + 1;
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int, int>> e(n * (n - 1) / 2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            x--;
            if (j > i) {
                e[x] = {i, j};
            }
        }
    }
    p.resize(n);
    sv.resize(n);
    se.resize(n);
    for (int i = 0; i < n; i++) {
        p[i] = i;
        sv[i] = 1;
    }
    d.assign(n, vector<long>(n));
    for (int i = 0; i < n; i++) {
        d[i][1] = 1;
    }
    for (auto p : e) {
        int x = p.first;
        int y = p.second;
        int xx = get(x);
        int yy = get(y);
        if (xx == yy) {
            se[xx]++;
        } else {
            join(xx, yy);
        }
        xx = get(xx);
        int nn = sv[xx];
        int mm = se[xx];
        if (mm == (nn * (nn - 1)) / 2) {
            d[xx][1]++;
            d[xx][1] %= MOD;
        }
    }
    int x = get(0);
    for (int i = 1; i <= n; i++) {
        cout << d[x][i] << "\n";
    }

    return 0;
}