#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long



/*const int MOD = ;

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

inline void sub(int &x, int y) {
    x += MOD - y;
    mod(x);
}

inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}

inline int inv(int x) {
    return lgput(x, MOD - 2);
}*/

/*int fact[], invfact[];

inline void prec(int n) {
    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }
    invfact[n] = lgput(fact[n], MOD - 2);
    for(int i = n - 1; i >= 0; i--) {
        invfact[i] = (1LL * invfact[i + 1] * (i + 1)) % MOD;
    }
}

inline int comb(int n, int k) {
    if(n < k) return 0;
    return (1LL * fact[n] * (1LL * invfact[k] * invfact[n - k] % MOD)) % MOD;
}*/

using namespace std;

const int MAXN = (int) 3e5;
const int MAXVAL = 1e6;

struct Node {
    int sum, suff;
}aint[1 << 21];

inline void refresh(int nod) {
    aint[nod].sum = aint[2 * nod].sum + aint[2 * nod + 1].sum;
    aint[nod].suff = max(aint[2 * nod + 1].suff, aint[2 * nod].suff + aint[2 * nod + 1].sum);
}

void update(int nod, int left, int right, int pos, int val) {
    if(left == right) {
        aint[nod].sum += val;
        aint[nod].suff += val;
    }
    else {
        int mid = (left + right) / 2;
        if(pos <= mid) update(2 * nod, left, mid, pos, val);
        else update(2 * nod + 1, mid + 1, right, pos, val);
        refresh(nod);
    }
}

int query(int nod, int left, int right, int sum) {
    if(left == right) {
        return left;
    }
    else {
        int mid = (left + right) / 2;
        if(aint[2 * nod + 1].suff + sum > 0) {
            return query(2 * nod + 1, mid + 1, right, sum);
        }
        return query(2 * nod, left, mid, sum + aint[2 * nod + 1].sum);
    }
}

int main() {
#if 0
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n, m, q;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    vector <int> a(n + 1), b(m + 1);
    for(i = 1; i <= n; i++) {
        cin >> a[i];
        update(1, 1, MAXVAL, a[i], 1);
    }
    for(i = 1; i <= m; i++) {
        cin >> b[i];
        update(1, 1, MAXVAL, b[i], -1);
    }

    cin >> q;
    while(q--) {
        int t, p, x;
        cin >> t >> p >> x;
        if(t == 1) {
            update(1, 1, MAXVAL, a[p], -1);
            a[p] = x;
            update(1, 1, MAXVAL, a[p], 1);
        }
        else {
            update(1, 1, MAXVAL, b[p], 1);
            b[p] = x;
            update(1, 1, MAXVAL, b[p], -1);
        }
        if(aint[1].suff <= 0) {
            cout << -1 << "\n";
            continue;
        }
        cout << query(1, 1, MAXVAL, 0) << "\n";
    }

    return 0;
}