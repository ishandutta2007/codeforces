#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll __int128

mt19937 rnd(51);

const int INF = 1e9, N = 5e5 + 10;
int a[3][N], now = 0, par[3 * N];
int pos[3 * N];
array<int, 7> t[4 * N];
int bal = 0;

int find_set(int a) {
    if (a == par[a]) return a;
    else return par[a] = find_set(par[a]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return;
    par[b] = a;
}

array<int, 7> merge(array<int, 7> a, array<int, 7> b) {
    if (a[6] == -1) return b;
    if (b[6] == -1) return a;
    for (int i = 0; i < 6; i++) {
        if (a[i] != -1) par[a[i]] = a[i];
        if (b[i] != -1) par[b[i]] = b[i];
    }
    array<int, 7> c;
    c[6] = a[6] + b[6];
    bal++;
    for (int j = 0; j < 3; j++) {
        if (a[j + 3] != -1) {
            if (pos[a[j + 3]] != bal) {
                pos[a[j + 3]] = bal;
                c[6]--;
            }
        }
        c[j] = a[j];
    }
    bal++;
    for (int j = 3; j < 6; j++) {
        if (b[j - 3] != -1) {
            if (pos[b[j - 3]] != bal) {
                pos[b[j - 3]] = bal;
                c[6]--;
            }
        }
        c[j] = b[j];
    }
    for (int j = 0; j < 3; j++) {
        if (a[j + 3] != -1 && b[j] != -1) {
            union_set(a[j + 3], b[j]);
        }
    }
    bal++;
    for (int j = 0; j < 6; j++) {
        if (j < 3) {
            if (b[j] != -1 && pos[find_set(b[j])] != bal) {
                pos[find_set(b[j])] = bal;
                c[6]++;
            }
        } else {
            if (a[j] != -1 && pos[find_set(a[j])] != bal) {
                pos[find_set(a[j])] = bal;
                c[6]++;
            }
        }
    }
    for (int i = 0; i < 6; i++) {
        if (c[i] != -1) c[i] = find_set(c[i]);
    }
    return c;
}

void build(int v, int l, int r) {
    if (l == r) {
        for (int i = 0; i < 3; i++) {
            if (i == 0 || a[i - 1][l] != a[i][l]) {
                now++;
            }
            if (a[i][l] == 0) {
                t[v][i] = t[v][i + 3] = now;
            } else {
                t[v][i] = t[v][i + 3] = -1;
            }
        }
        if (min({a[0][l], a[1][l], a[2][l]}) == 0) {
            if (a[0][l] == 0 && a[1][l] == 1 && a[2][l] == 0) {
                t[v][6] = 2;
            } else {
                t[v][6] = 1;
            }
        } else {
            t[v][6] = 0;
        }
        return;
    }
    int m = (l + r) / 2;
    build(2 * v, l, m), build(2 * v + 1, m + 1, r);
    t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

array<int, 7> get(int v, int tl, int tr, int l, int r) {
    if (l > r) return {0, 0, 0, 0, 0, 0, -1};
    if (tl == l && tr == r) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return merge(get(2 * v, tl, tm, l, min(r, tm)), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
            a[i][j] ^= 1;
        }
    }
    build(1, 0, n - 1);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << get(1, 0, n - 1, l, r)[6] << '\n';
    }
    return 0;
}