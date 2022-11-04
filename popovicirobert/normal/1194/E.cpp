#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


/*const int MOD = 998244353;

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

int fact[MAXN + 1], invfact[MAXN + 1];

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

struct Fenwick {
    vector <int> aib;
    int n;
    inline void init(int _n) {
        n = _n;
        aib.resize(n + 1);
    }
    inline void update(int pos, int val) {
        for(int i = pos; i <= n; i += lsb(i)) {
            aib[i] += val;
        }
    }
    inline int query(int pos) {
        int ans = 0;
        for(int i = pos; i > 0; i -= lsb(i)) {
            ans += aib[i];
        }
        return ans;
    }
    inline int sum(int l, int r) {
        return max(0, query(r) - query(l - 1));
    }
};

const int MAXN = 5005;

struct O {
    int y;
    int x1, x2;
};

struct V {
    int x;
    int y1, y2;
};

struct Data {
    int y, type, x1, x2;

    bool operator <(const Data &other) const {
        if(y == other.y) return type < other.type;
        return y < other.y;
    }
};

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector <V> v;
    vector <O> o;

    for(i = 1; i <= n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += MAXN, y1 += MAXN, x2 += MAXN, y2 += MAXN;
        if(x1 == x2) {
            v.push_back({x1, min(y1, y2), max(y1, y2)});
        }
        else {
            o.push_back({y1, min(x1, x2), max(x1, x2)});
        }
    }

    Fenwick fen; fen.init(2 * MAXN);
    ll ans = 0;

    for(auto it : o) {
        vector <Data> cur;
        for(auto itr : v) {
            if(itr.y1 <= it.y && it.y <= itr.y2) {
                cur.push_back({itr.y1, 1, itr.x, 0});
                cur.push_back({itr.y2, 2, itr.x, 0});
            }
        }
        for(auto itr : o) {
            if(itr.y > it.y) {
                cur.push_back({itr.y, 0, itr.x1, itr.x2});
            }
        }

        sort(cur.begin(), cur.end());

        for(auto itr : cur) {
            if(itr.type == 0) {
                int sz = fen.sum(max(it.x1, itr.x1), min(itr.x2, it.x2));
                ans += 1LL * sz * (sz - 1) / 2;
            }
            else if(itr.type == 1) {
                fen.update(itr.x1, 1);
            }
            else {
                fen.update(itr.x1, -1);
            }
        }
    }

    cout << ans;

    return 0;
}