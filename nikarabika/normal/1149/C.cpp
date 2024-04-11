#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef long double LD;

#define L first
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define R second
#define smin(x, y) (x) = min((x), (y))
#define PB push_back
#define MP make_pair
#define all(x) (x).begin(),(x).end()

const int maxn = 200 * 1000 + 100;
int laz[maxn << 2];
int n, q;
string s;

struct node {
    int ans;
    int minus;
    int plus;
    int left;
    int right;
} seg[maxn << 2];

void add(int val, int st, int en, int l, int r, int id);

node merge(node le, node ri) {
    node res;
    res.ans = max({le.ans, ri.ans, le.left + ri.plus, le.plus + ri.right});
    res.plus = max(le.plus, ri.plus);
    res.minus = max(le.minus, ri.minus);
    res.left = max({le.left, ri.left, le.plus + ri.minus});
    res.right = max({le.right, ri.right, le.minus + ri.plus});
    return res;
}

void push(int l, int r, int id) {
    if (!laz[id]) return;
    int mid = (l + r) >> 1;
    add(laz[id], l, mid, l, mid, id << 1 | 0);
    add(laz[id], mid, r, mid, r, id << 1 | 1);
    laz[id] = 0;
}

void add(int val, int st, int en, int l = 0, int r = n, int id = 1) {
    if (st >= r or en <= l)
        return;
    if (st <= l and r <= en) {
        laz[id] += val;
        seg[id].plus += val;
        seg[id].minus -= 2 * val;
        seg[id].left -= val;
        seg[id].right -= val;
        return;
    }
    push(l, r, id);
    int mid = (l + r) >> 1;
    add(val, st, en, l, mid, id << 1 | 0);
    add(val, st, en, mid, r, id << 1 | 1);
    seg[id] = merge(seg[id << 1 | 0], seg[id << 1 | 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    n = 2 * n - 1;
    cin >> s;
    s = '0' + s;
    for (int i = 0; i < sz(s); i++)
        if (s[i] == '(')
            add(+1, i, n);
        else if (s[i] == ')')
            add(-1, i, n);
    cout << seg[1].ans << '\n';
    while (q--) {
        int fi, se;
        cin >> fi >> se;
        if (fi > se) swap(fi, se);
        if (s[fi] != s[se]) {
            if (s[fi] == '(')
                add(-2, fi, se);
            else
                add(+2, fi, se);
            swap(s[fi], s[se]);
        }
        cout << seg[1].ans << '\n';
    }
    return 0;
}