#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
#define all(_v) _v.begin(), _v.end()
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const ll inf = 1e17 + 7;
const int max_n = (1 << 17);

struct node {
    int sum, mark, delta, l, r;

    node() {}
    node(int sum, int mark, int delta, int l, int r) : sum(sum), mark(mark), delta(delta), l(l), r(r) {}
};

int n;
node s[2 * max_n];

void build() {
    for(int i = 2 * max_n - 1;i >= 1;i--) {
        if (i >= max_n) {
            int num = 0;
            if (i - max_n < n) num = i - max_n + 1;
            s[i] = {0, num, 0, i - max_n, i - max_n};
        }else {
            s[i] = {0, 0, 0, s[i * 2].l, s[i * 2 + 1].r};
        }
    }
}

int get(int v, int l, int r) {
    if (s[v].l > r || s[v].r < l) return 0;
    if (s[v].l >= l && s[v].r <= r) return s[v].sum;
    return get(v * 2, l, r) + get(v * 2 + 1, l, r) + s[v].delta * (min(r, s[v].r) - max(l, s[v].l) + 1);
}

void Clear(int v, int x) {
    if (s[v].mark > 0) {
        s[v].delta += abs(s[v].mark - x);
        s[v].sum += abs(s[v].mark - x) * (s[v].r - s[v].l + 1);
    }else {
        Clear(v * 2, x);
        Clear(v * 2 + 1, x);
        s[v].sum = s[v * 2].sum + s[v * 2 + 1].sum + s[v].delta * (s[v].r - s[v].l + 1);
    }
    s[v].mark = 0;
}

void upd(int v, int l, int r, int x) {
    if (s[v].l > r || s[v].r < l) return;
    if (s[v].l >= l && s[v].r <= r) Clear(v, x), s[v].mark = x;
    else {
        if (s[v].mark > 0) s[v * 2].mark = s[v * 2 + 1].mark = s[v].mark, s[v].mark = 0;
        upd(v * 2, l, r, x);
        upd(v * 2 + 1, l, r, x);
        s[v].sum = s[v * 2].sum + s[v * 2 + 1].sum + s[v].delta * (s[v].r - s[v].l + 1);
    }
}
 
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int m;
    cin >> n >> m;
    build();
    for(int i = 0;i < m;i++) {
        int t, l, r, x;
        cin >> t >> l >> r;
        l--; r--;
        if (t == 1) {
            cin >> x;
            upd(1, l, r, x);
        }else {
            cout << get(1, l, r) << endl;
        }
    }
}