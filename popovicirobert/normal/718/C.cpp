#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXN = (int) 1e5;

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

int arr[MAXN + 1];
int a[3][3], ans[3][3];

inline void multiply(int a[3][3], int b[3][3]) {
    int c[3][3];
    for(int i = 1; i <= 2; i++) {
        for(int j = 1; j <= 2; j++) {
            c[i][j] = 0;
            for(int k = 1; k <= 2; k++) {
                c[i][j] = (c[i][j] + 1LL * a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    memcpy(a, c, sizeof(c));
}

inline pair <int, int> lgput(pair <int, int> vals, ll step) {
    memset(a, 0, sizeof(a));
    memset(ans, 0, sizeof(ans));
    a[1][2] = a[2][1] = a[2][2] = 1;
    for(int i = 1; i <= 2; i++) {
        ans[i][i] = 1;
    }
    while(step > 0) {
        if(step & 1)
            multiply(ans, a);
        step >>= 1;
        multiply(a, a);
    }
    return {(1LL * vals.first * ans[1][1] + 1LL * vals.second * ans[2][1]) % MOD, (1LL * vals.first * ans[1][2] + 1LL * vals.second * ans[2][2]) % MOD};
}

struct Aint {
    pair <int, int> vals;
    int mat[3][3];
}aint[4 * MAXN + 1];

inline void refresh(int nod) {
    aint[nod].vals = {(aint[2 * nod].vals.first + aint[2 * nod + 1].vals.first) % MOD, (aint[2 * nod].vals.second + aint[2 * nod + 1].vals.second) % MOD};
}

inline void solve_lazy(int nod) {
    if(2 * nod + 1 <= 4 * MAXN) {
        multiply(aint[2 * nod].mat, aint[nod].mat);
        multiply(aint[2 * nod + 1].mat, aint[nod].mat);
    }
    pair <int, int> aux = aint[nod].vals;
    aint[nod].vals.first = (1LL * aux.first * aint[nod].mat[1][1] + 1LL * aux.second * aint[nod].mat[2][1]) % MOD;
    aint[nod].vals.second = (1LL * aux.first * aint[nod].mat[1][2] + 1LL * aux.second * aint[nod].mat[2][2]) % MOD;
    memset(aint[nod].mat, 0, sizeof(aint[nod].mat));
    for(int i = 1; i <= 2; i++) {
        aint[nod].mat[i][i] = 1;
    }
}

void build(int nod, int left, int right) {
    for(int i = 1; i <= 2; i++) {
        aint[nod].mat[i][i] = 1;
    }
    if(left == right) {
        aint[nod].vals = lgput({1, 1}, arr[left] - 1);
    }
    else {
        int mid = (left + right) / 2;
        build(2 * nod, left, mid);
        build(2 * nod + 1, mid + 1, right);
        refresh(nod);
    }
}

void update(int nod, int left, int right, int l, int r, int x) {
    solve_lazy(nod);
    if(l <= left && right <= r) {
        multiply(aint[nod].mat, ans);
        solve_lazy(nod);
    }
    else {
        int mid = (left + right) / 2;
        if(l <= mid)
            update(2 * nod, left, mid, l, r, x);
        else
            solve_lazy(2 * nod);
        if(mid < r)
            update(2 * nod + 1, mid + 1, right, l, r, x);
        else
            solve_lazy(2 * nod + 1);
        refresh(nod);
    }
}

int query(int nod, int left, int right, int l, int r) {
    solve_lazy(nod);
    if(l <= left && right <= r) {
        return aint[nod].vals.first;
    }
    else {
        int mid = (left + right) / 2;
        int ans = 0;
        if(l <= mid) {
            ans += query(2 * nod, left, mid, l, r);
            mod(ans);
        }
        else
            solve_lazy(2 * nod);
        if(mid < r) {
            ans += query(2 * nod + 1, mid + 1, right, l, r);
            mod(ans);
        }
        else
            solve_lazy(2 * nod + 1);
        refresh(nod);
        return ans;
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m;
    //ios::sync_with_stdio(false);
    //cin >> n >> m;
    scanf("%d%d" ,&n,&m);
    for(i = 1; i <= n; i++) {
        //cin >> arr[i];
        scanf("%d" ,&arr[i]);
    }
    build(1, 1, n);
    while(m > 0) {
        m--;
        int type, l, r, x;
        //cin >> type >> l >> r;
        scanf("%d%d%d" ,&type,&l,&r);
        if(type == 1) {
            //cin >> x;
            scanf("%d" ,&x);
            lgput({1, 1}, x);
            update(1, 1, n, l, r, x);
        }
        else {
            //cout << query(1, 1, n, l, r) << "\n";
            printf("%d\n" ,query(1, 1, n, l, r));
        }
    }
    //cin.close();
   // cout.close();
    return 0;
}