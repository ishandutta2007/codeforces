#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>
#include<bitset>
#include<unordered_map>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int N = 2e5 + 10;

struct node{
    int ans, val_l, val_r, col_l, col_r, len;
};

node t[4 * N];
int a[N];

node func(node a, node b){
    if (a.len == 0) return b;
    if (b.len == 0) return a;
    node c;
    c.ans = a.ans + b.ans + (a.val_r <= b.val_l ? a.col_r * b.col_l : 0);
    c.len = a.len + b.len;
    c.val_l = a.val_l;
    c.val_r = b.val_r;
    c.col_l = a.col_l;
    c.col_r = b.col_r;
    if (a.col_l == a.len && a.val_r <= b.val_l) c.col_l += b.col_l;
    if (b.col_r == b.len && a.val_r <= b.val_l) c.col_r += a.col_r;
    return c;
}

void update(int v, int l, int r, int pos, int val){
    if (l == r){
        t[v] = {1, val, val, 1, 1, 1};
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m){
        update(2 * v, l, m, pos, val);
    }
    else{
        update(2 * v + 1, m + 1, r, pos, val);
    }
    t[v] = func(t[v * 2], t[v * 2 + 1]);
}

node get(int v, int tl, int tr, int l, int r){
    if (l > r) {
        return node{0, 0, 0, 0, 0, 0};
    }
    if (tl == l && tr == r){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return func(get(2 * v, tl, tm, l, min(r, tm)), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        update(1, 0, n - 1, i, a[i]);
    }
    while(q--){
        int t;
        cin >> t;
        if (t == 1){
            int x, y;
            cin >> x >> y;
            update(1, 0, n - 1, x - 1, y);
        }
        else{
            int l, r;
            cin >> l >> r;
            cout << get(1, 0, n - 1, l - 1, r - 1).ans << endl;
        }
    }
    return 0;
}