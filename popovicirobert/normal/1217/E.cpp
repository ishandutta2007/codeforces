#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long



#if 0
const int MOD = ;

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
}
#endif

#if 0
int fact[], invfact[];

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
}
#endif

using namespace std;

#define mn1 first
#define mn2 second

const int INF = 1e9 + 5;

struct SegTree {
    vector < pair <int, int> > aint;
    int n;

    inline void init(int _n) {
        n = _n;
        aint.resize(4 * n + 1, {INF, INF});
    }

    inline pair <int, int> combine(pair <int, int> a, pair <int, int> b) {
        pair <int, int> ans;
        ans.mn1 = min(a.mn1, b.mn1);
        if(ans.mn1 == a.mn1) {
            ans.mn2 = min(a.mn2, b.mn1);
        }
        else {
            ans.mn2 = min(b.mn2, a.mn1);
        }
        return ans;
    }

    void update(int nod, int left, int right, int pos, int val) {
        if(left == right) {
            aint[nod] = {val, INF};
        }
        else {
            int mid = (left + right) / 2;
            if(pos <= mid) update(2 * nod, left, mid, pos, val);
            else update(2 * nod + 1, mid + 1, right, pos, val);
            aint[nod] = combine(aint[2 * nod], aint[2 * nod + 1]);
        }
    }

    pair <int, int> query(int nod, int left, int right, int l, int r) {
        if(l <= left && right <= r) {
            return aint[nod];
        }
        else {
            int mid = (left + right) / 2;
            pair <int, int> ans = {INF, INF};
            if(l <= mid) ans = combine(ans, query(2 * nod, left, mid, l, r));
            if(mid < r) ans = combine(ans, query(2 * nod + 1, mid + 1, right, l, r));
            return ans;
        }
    }
}st[10];

int main() {
#if 0
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
    int i, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(i = 0; i < 10; i++) {
        st[i].init(n);
    }

    vector <int> x(n + 1);
    for(i = 1; i <= n; i++) {
        int aux;
        cin >> x[i];
        aux = x[i];
        for(int j = 0; j < 10; j++) {
            if(aux % 10) {
                st[j].update(1, 1, n, i, x[i]);
            }
            aux /= 10;
        }
    }

    while(m--) {
        int type;
        cin >> type;

        if(type == 1) {
            int pos, aux, cur;
            cin >> pos >> cur;
            aux = cur;
            for(i = 0; i < 10; i++) {
                if(x[pos] % 10) {
                    st[i].update(1, 1, n, pos, INF);
                }
                x[pos] /= 10;

                if(aux % 10) {
                    st[i].update(1, 1, n, pos, cur);
                }
                aux /= 10;
            }
            x[pos] = cur;
        }
        else {
            int l, r;
            cin >> l >> r;
            int ans = 2 * INF;
            for(i = 0; i < 10; i++) {
                auto cur = st[i].query(1, 1, n, l, r);
                if(cur.mn2 != INF) {
                    ans = min(ans, cur.mn1 + cur.mn2);
                }
            }
            if(ans == 2 * INF) {
                cout << -1 << "\n";
            }
            else {
                cout << ans << "\n";
            }
        }
    }

    return 0;
}