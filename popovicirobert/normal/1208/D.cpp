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

const ll INF = 1e18;
const int MAXN = (int) 2e5;

struct Node {
    ll mn, lazy;
    int pos;
}aint[4 * MAXN + 1];

ll arr[MAXN + 1];

inline void refresh(int nod) {
    if(aint[2 * nod].mn + aint[2 * nod].lazy < aint[2 * nod + 1].mn + aint[2 * nod + 1].lazy) {
        aint[nod].mn = aint[2 * nod].mn + aint[2 * nod].lazy;
        aint[nod].pos = aint[2 * nod].pos;
    }
    else {
        aint[nod].mn = aint[2 * nod + 1].mn + aint[2 * nod + 1].lazy;
        aint[nod].pos = aint[2 * nod + 1].pos;
    }
}

inline void push(int nod) {
    aint[2 * nod].lazy += aint[nod].lazy;
    aint[2 * nod + 1].lazy += aint[nod].lazy;
    aint[nod].lazy = 0;
}

void build(int nod, int left, int right) {
    if(left == right) {
        aint[nod] = {arr[left], 0, left};
    }
    else {
        int mid = (left + right) / 2;
        build(2 * nod, left, mid);
        build(2 * nod + 1, mid + 1, right);
        refresh(nod);
    }
}

void update(int nod, int left, int right, int l, int r, ll val) {
    if(l <= left && right <= r) {
        aint[nod].lazy += val;
        return ;
    }
    push(nod);
    int mid = (left + right) / 2;
    if(l <= mid) update(2 * nod, left, mid, l, r, val);
    if(mid < r) update(2 * nod + 1, mid + 1, right, l, r, val);
    refresh(nod);
}

pair <ll, int> get(int nod, int left, int right) {
    if(left == right) {
        return {aint[nod].mn, left};
    }
    push(nod);
    int mid = (left + right) / 2;
    pair <ll, int> ans;
    if(aint[2 * nod].lazy + aint[2 * nod].mn < aint[2 * nod + 1].lazy + aint[2 * nod + 1].mn) {
        ans = get(2 * nod, left, mid);
    }
    else ans = get(2 * nod + 1, mid + 1, right);
    refresh(nod);
    return ans;
}

int main() {
#if 0
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    build(1, 1, n);

    vector <int> sol(n + 1);
    for(i = 1; i <= n; i++) {
        int p = get(1, 1, n).second;
        update(1, 1, n, p, n, -i);
        update(1, 1, n, p, p, INF);
        sol[p] = i;
    }

    for(i = 1; i <= n; i++) {
        cout << sol[i] << " ";
    }

    return 0;
}