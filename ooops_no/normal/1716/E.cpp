#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

const int N = 2.7e5 + 10;

struct node {
    ll pref, suf, ans, sum;
    node(int a) {
        sum = a;
        pref = suf = ans = max(a, 0);
    }
};

node merge_node(node a, node b) {
    node c(0);
    c.sum = a.sum + b.sum;
    c.ans = max({a.ans, b.ans, a.suf + b.pref});
    c.pref = max({a.pref, a.sum + b.pref});
    c.suf = max({b.suf, b.sum + a.suf});
    return c;
}

int a[N], po[N];
vector<node> t[4 * N];

void build(int v, int l, int r) {
    t[v].resize(r - l + 1, 0);
    if (l == r) {
        t[v][0] = node(a[l]);
        return;
    }
    int m = (l + r) / 2;
    build(2 * v, l, m), build(2 * v + 1, m + 1, r);
    for (int i = 0; i <= m - l; i++) {
        t[v][i] = merge_node(t[v * 2][i], t[v * 2 + 1][i]);
    }
    for (int i = m - l + 1; i <= r - l; i++) {
        t[v][i] = merge_node(t[v * 2 + 1][i - (r - l + 1) / 2], t[v * 2][i - (r - l + 1) / 2]);
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    n = (1 << n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    int q, x = 0;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        x ^= (1 << k);
        cout << t[1][x].ans << endl;
    }
    return 0;
}