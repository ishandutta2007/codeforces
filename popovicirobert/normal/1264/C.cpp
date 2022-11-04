#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int


#if 1
const int MOD = (int) 998244353;

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


const int MAXN = (int) 2e5;

int p[MAXN + 1];

struct Node {
    int invprd, sum;
    Node() : invprd(1), sum(0) { }
    Node(int _invprd, int _sum) : invprd(_invprd), sum(_sum) { }
};

Node aint[4 * MAXN + 1];

inline Node combine(Node a, Node b) {
    Node ans;
    ans.sum = (b.sum + 1LL * a.sum * b.invprd) % MOD;
    ans.invprd = (1LL * a.invprd * b.invprd) % MOD;
    return ans;
}

void build(int nod, int left, int right) {
    if(left == right) {
        int cur = inv(p[left]);
        aint[nod] = Node(cur, cur);
    }
    else {
        int mid = (left + right) / 2;

        build(2 * nod, left, mid);
        build(2 * nod + 1, mid + 1, right);

        aint[nod] = combine(aint[2 * nod], aint[2 * nod + 1]);
    }
}

Node query(int nod, int left, int right, int l, int r) {
    if(l <= left && right <= r) {
        return aint[nod];
    }
    else {
        int mid = (left + right) / 2;
        Node a, b;

        if(l <= mid) a = query(2 * nod, left, mid, l, r) ;
        if(mid < r) b = query(2 * nod + 1, mid + 1, right, l, r);

        return combine(a, b);
    }
}

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n, q;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;

    for(i = 1; i <= n; i++) {
        cin >> p[i];
        p[i] = (1LL * p[i] * inv(100)) % MOD;
    }

    build(1, 1, n);

    set <int> check;
    check.insert(1);
    check.insert(n + 1);

    int ans = query(1, 1, n, 1, n).sum;

    while(q--) {
        int pos;
        cin >> pos;

        if(check.find(pos) != check.end()) {
            auto it = check.find(pos);
            auto l = prev(it);
            auto r = next(it);

            Node a = query(1, 1, n, *l, pos - 1), b = query(1, 1, n, pos, *r - 1);
            Node cur = query(1, 1, n, *l, *r - 1);

            sub(ans, a.sum);
            sub(ans, b.sum);
            add(ans, cur.sum);

            check.erase(pos);
        }
        else {
            check.insert(pos);
            auto it = check.find(pos);
            auto l = prev(it);
            auto r = next(it);

            Node a = query(1, 1, n, *l, pos - 1), b = query(1, 1, n, pos, *r - 1);
            Node cur = query(1, 1, n, *l, *r - 1);

            add(ans, a.sum);
            add(ans, b.sum);
            sub(ans, cur.sum);
        }

        cout << ans << "\n";
    }

    return 0;
}