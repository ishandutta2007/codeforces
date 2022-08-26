#include <iostream>
#include <vector>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 200001 * 6;
ll md = 1000000007;

struct Node {
    ll upd = 0;
    ll val = 0;
    ll min = INF;
};

Node tree[maxN];
ll a[maxN];

void build(int v, int l, int r) {
    if (l + 1 == r) {
        tree[v] = {0, a[l], a[l]};
        return;
    }
    build(v * 2, l, (l + r) / 2);
    build(v * 2  + 1, (l + r) / 2, r);
    tree[v].val = min(tree[v * 2].val, tree[v * 2 + 1].val);
    tree[v].min = min(tree[v].min, tree[v].val);
}

void push(int v) {
    tree[v * 2].upd += tree[v].upd;
    tree[v * 2 + 1].upd += tree[v].upd;
    tree[v].val += tree[v].upd;
    tree[v].upd = 0;
    tree[v].min = min(tree[v].min, tree[v].val);
}

void upd(ll x, int lq, int rq, int v, int l, int r) {
    if (l >= rq || r <= lq) return;
    if (lq <= l && r <= rq) {
        tree[v].upd += x;
        push(v);
        return;
    }
    push(v);
    upd(x, lq, rq, v * 2, l, (l + r) / 2);
    upd(x, lq, rq, v * 2 + 1, (l + r) / 2, r);
    tree[v].val = min(tree[v * 2].val, tree[v * 2 + 1].val);
}

void print_tree(int v, int l, int r) {
    push(v);
    if (l + 1 == r) {
        cout << tree[v].val << ' ';
        return;
    }
    print_tree(v * 2, l, (l + r) / 2);
    print_tree(v * 2 + 1, (l + r) / 2, r);
}

void solve() {
    int n; cin >> n;
    vector<ll> b(n), c(n), d(n, 0);
    range(i, n) cin >> b[i];
    range(i, n) cin >> c[i];
    range(i, n) {
        d[b[i] - 1] = c[i];
    }
    a[0] = d[0];
    for(int i = 1; i < n; ++i) a[i] = a[i - 1] + d[i];
    range(i, b[0] - 1) a[i] += c[0];
    for(int i = b[0] - 1; i < n; ++i) a[i] -= c[0];
    build(1, 0, n);
    for (int i = 1; i < n - 1; ++i) {
        //print_tree(1, 0, n); cout << '\n';
        upd(-c[i], b[i] - 1, n, 1, 0, n);
        upd(c[i], 0, b[i] - 1, 1, 0, n);
    }
    //print_tree(1, 0, n);cout << '\n';
    cout << min(c[0], tree[1].min);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests; tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}