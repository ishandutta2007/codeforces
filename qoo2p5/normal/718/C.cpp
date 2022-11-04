#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-9;
const int MOD = 1e9 + 7;

const int N = 1e5 + 123;

ll mod(ll x) {
    return (x >= MOD ? x - MOD : x);
}

struct Matrix {
    int n, m;
    ll a[2][2];
    
    Matrix() {}
    
    Matrix(int n, int m) : n(n), m(m) {}
    
    ll* operator[](const int i) {
        return a[i];
    }
};

void mul(Matrix &a, Matrix &b, Matrix &c) {
    c.n = a.n;
    c.m = b.m;
    for (int i = 0; i < c.n; i++) {
        for (int j = 0; j < c.m; j++) {
            c[i][j] = 0;
            for (int k = 0; k < a.m; k++) {
                c[i][j] = mod(c[i][j] + (a[i][k] * 1LL * b[k][j]) % MOD);
            }
        }
    }
}

void accum(Matrix &a, Matrix &b, Matrix &c) {
    c.n = a.n;
    c.m = a.m;
    for (int i = 0; i < c.n; i++) {
        for (int j = 0; j < c.m; j++) {
            c[i][j] = mod(a[i][j] + b[i][j]);
        }
    }
}

void copy(Matrix &a, Matrix &b) {
    b.n = a.n;
    b.m = a.m;
    for (int i = 0; i < a.n; i++) {
        for (int j = 0; j < a.m; j++) {
            b[i][j] = a[i][j];
        }
    }
}

void self_mul(Matrix &a, Matrix &b) {
    Matrix tmp;
    mul(a, b, tmp);
    copy(tmp, a);
}

Matrix mem[N];
int ptr = 0;

Matrix& alloc(int n, int m) {
    mem[ptr].n = n;
    mem[ptr].m = m;
    return mem[ptr++];
}

Matrix& power(Matrix &a, ll p) {
    if (p == 1) {
        return a;
    }
    
    Matrix& res = alloc(a.n, a.m);
    
    if (p & 1) {
        Matrix &tmp = power(a, p - 1);
        mul(a, tmp, res);
        return res;
    }
    
    Matrix& tmp = power(a, p / 2);
    mul(tmp, tmp, res);
    return res;
}

Matrix cur_go;

void calc_go(ll x) {
    ptr = 0;
    Matrix& go = alloc(2, 2);

    go[0][0] = 0;
    go[0][1] = 1;
    go[1][0] = 1;
    go[1][1] = 1;
    cur_go.n = 2;
    cur_go.m = 2;
    Matrix &tmp = power(go, x);
    copy(tmp, cur_go);
}

int n, m;
int a[N];

Matrix sum[4 * N];
Matrix tree[4 * N];
bool flag[4 * N];
Matrix p[4 * N];

void recalc(int i, int tl, int tr) {
    if (tl != tr - 1) {
        sum[i][0][0] = mod(tree[2 * i + 1][0][0] + tree[2 * i + 2][0][0]);
        sum[i][0][1] = mod(tree[2 * i + 1][0][1] + tree[2 * i + 2][0][1]);
    }
    
    if (flag[i]) {
        mul(sum[i], p[i], tree[i]);
    } else {
        copy(sum[i], tree[i]);
    }
}

void build(int i, int tl, int tr) {
    sum[i] = Matrix(1, 2);
    
    if (tl == tr - 1) {
        sum[i][0][0] = 0;
        sum[i][0][1] = 1;
        if (a[tl] - 1 >= 1) {
            calc_go(a[tl] - 1);
            self_mul(sum[i], cur_go);
        }
        recalc(i, tl, tr);
        return;
    }
    
    int tm = (tl + tr) / 2;
    build(2 * i + 1, tl, tm);
    build(2 * i + 2, tm, tr);
    recalc(i, tl, tr);
}

void upd(int i, int tl, int tr, int l, int r) {    
    if (tl >= tr || tl >= r || tr <= l) {
        return;
    }
    
    if (l <= tl && tr <= r) {
        if (flag[i]) {
            self_mul(p[i], cur_go);
        } else {
            flag[i] = true;
            copy(cur_go, p[i]);
        }
        recalc(i, tl, tr);
        return;
    }
    
    int tm = (tl + tr) / 2;
    upd(2 * i + 1, tl, tm, l, r);
    upd(2 * i + 2, tm, tr, l, r);
    recalc(i, tl, tr);
}

Matrix& get(int i, int tl, int tr, int l, int r) {
    Matrix& res = alloc(1, 2);
    
    if (tl >= tr || tl >= r || tr <= l) {
        res[0][0] = 0;
        res[0][1] = 0;
        return res;
    }
    
    if (l <= tl && tr <= r) {
        return tree[i];
    }
    
    int tm = (tl + tr) / 2;
    Matrix& L = get(2 * i + 1, tl, tm, l, r);
    Matrix& R = get(2 * i + 2, tm, tr, l, r);
    accum(L, R, res);
    if (flag[i]) {
        self_mul(res, p[i]);
    }
    return res;
}

int run() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    build(0, 0, n);
    
    for (int i = 0; i < m; i++) {
        int tp, l, r, x;
        
        cin >> tp >> l >> r;
        if (tp == 1) {
            cin >> x;
        }
        
        l--; r--;
        
        if (tp == 1) {
            calc_go(x);
            upd(0, 0, n, l, r + 1);
        } else {
            ptr = 0;
            cout << get(0, 0, n, l, r + 1)[0][1] << "\n";
        }
    }
    
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return run();
}