#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int



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

struct SegTree {
    struct Node {
        int val;
        int lazy;
        Node() {
            val = lazy = 0;
        }
    };

    vector <Node> aint;
    int n;

    inline void init(int _n) {
        n = _n;
        aint.resize(4 * n + 1);
    }

    inline void push(int nod) {
        aint[2 * nod].lazy += aint[nod].lazy;
        aint[2 * nod + 1].lazy += aint[nod].lazy;
        aint[nod].lazy = 0;
    }

    inline Node combine(Node a, Node b) {
        Node ans;
        ans.val = max(a.val + a.lazy, b.val + b.lazy);
        return ans;
    }

    void update(int nod, int left, int right, int l, int r, int val) {
        if(l <= left && right <= r) {
            aint[nod].lazy += val;
            return ;
        }
        push(nod);
        int mid = (left + right) / 2;

        if(l <= mid) update(2 * nod, left, mid, l, r, val);
        if(mid < r) update(2 * nod + 1, mid + 1, right, l, r, val);

        aint[nod] = combine(aint[2 * nod], aint[2 * nod + 1]);
    }

    Node query(int nod, int left, int right, int l, int r) {
        if(l <= left && right <= r) {
            return aint[nod];
        }
        push(nod);
        int mid = (left + right) / 2;
        Node ans;

        if(l <= mid) ans = combine(ans, query(2 * nod, left, mid, l, r));
        if(mid < r) ans = combine(ans, query(2 * nod + 1, mid + 1, right, l, r));

        return ans;
    }
};

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector <int> a(2 * n + 1);
    for(i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    vector <int> stk, l(2 * n + 1, 1), r(2 * n + 1, 2 * n);
    for(i = 1; i <= 2 * n; i++) {
        while(stk.size() && a[stk.back()] >= a[i]) {
            r[stk.back()] = i - 1;
            stk.pop_back();
        }
        stk.push_back(i);
    }
    stk.clear();
    for(i = 2 * n; i >= 1; i--) {
        while(stk.size() && a[stk.back()] >= a[i]) {
            l[stk.back()] = i + 1;
            stk.pop_back();
        }
        stk.push_back(i);
    }

    /*for(i = 1; i <= 2 * n; i++) {
        cerr << a[i] << " " << l[i] << " " << r[i] << "\n";
    }*/

    SegTree st; st.init(2 * n);
    for(i = 1; i <= n; i++) {
        st.update(1, 1, 2 * n, l[i], r[i], 1);
    }
    int ans = st.query(1, 1, 2 * n, 1, n).val, num = 0;
    for(i = 1; i < n; i++) {
        st.update(1, 1, 2 * n, l[i], r[i], -1);
        st.update(1, 1, 2 * n, l[i + n], r[i + n], 1);
        auto cur = st.query(1, 1, 2 * n, i + 1, i + n);
        if(ans > cur.val) {
            ans = cur.val;
            num = i;
        }
    }

    cout << ans << " " << num;

    return 0;
}