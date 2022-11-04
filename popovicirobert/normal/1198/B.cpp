#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


/*const int MOD = (int) 1e9 + 7;

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

const int MAXN = (int) 2e5;

int aint[4 * MAXN + 1];

inline void push(int nod) {
    aint[2 * nod] = max(aint[2 * nod], aint[nod]);
    aint[2 * nod + 1] = max(aint[2 * nod + 1], aint[nod]);
    aint[nod] = 0;
}

void update(int nod, int left, int right, int pos, int val) {
    if(left == right) {
        aint[nod] = val;
        return ;
    }
    push(nod);

    int mid = (left + right) / 2;

    if(pos <= mid) update(2 * nod, left, mid, pos, val);
    else update(2 * nod + 1, mid + 1, right, pos, val);
}

void dfs(int nod, int left, int right) {
    if(left == right) {
        cout << aint[nod] << " ";
        return ;
    }
    push(nod);

    int mid = (left + right) / 2;

    dfs(2 * nod, left, mid);
    dfs(2 * nod + 1, mid + 1, right);
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, q;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector <int> arr(n + 1);
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
        update(1, 1, n, i, arr[i]);
    }

    cin >> q;

    while(q--) {
        int type, id, x;

        cin >> type;

        if(type == 1) {
            cin >> id >> x;
            update(1, 1, n, id, x);
        }
        else {
            cin >> x;
            aint[1] = max(aint[1], x);
        }
    }

    dfs(1, 1, n);

    return 0;
}