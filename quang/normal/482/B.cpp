#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 100010;

int n, m;
int l[N], r[N];
long long q[N];
long long a[N];
long long tree[N * 4];

void Update(int node, int l, int r, int x, int y, int q) {
    if(y < l || x > r) return;
    if(x <= l && r <= y) {
        tree[node] |= q;
        return;
    }
    int m = (l + r) >> 1;
    Update(node * 2, l, m, x, y, q);
    Update(node * 2 + 1, m + 1, r, x, y, q);
}

long long Get(int node, int l, int r, int id) {
    if( id < l || id > r) return 0;
    if(l == r) return tree[node];
    int m = (l + r) >> 1;
    long long p1 = Get(node * 2, l, m, id);
    long long p2 = Get(node * 2 + 1, m + 1, r, id);
    return (p1 | p2 | tree[node]);
}

void Make(int node, int l ,int r) {
    if(l == r) {
        tree[node] = a[l];
        return;
    }
    int m =  (l + r) >> 1;
    Make(node * 2, l, m);
    Make(node * 2 + 1, m + 1, r);
    tree[node] = tree[node * 2] & tree[node * 2 + 1];
}

long long Getval(int node, int l, int r, int x, int y) {
    if(y < l || r < x) return ((1ll << 32) - 1);
    if(x <= l && r <= y) return tree[node];
    int m  = (l + r) >> 1;
    long long p1 = Getval(node * 2, l, m, x, y);
    long long p2 = Getval(node * 2 + 1, m + 1, r, x, y);
    return p1 & p2;
}

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        cin >> l[i] >> r[i] >> q[i];
        Update(1, 1, n, l[i], r[i], q[i]);
    }
    for(int i = 1; i <= n; i++)
        a[i] = Get(1, 1, n ,i);
    memset(tree, 0, sizeof(tree));
    Make(1, 1, n);
    for(int i = 1; i <= m; i++) {
        long long x = Getval(1, 1, n, l[i], r[i]);
        if(x != q[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}