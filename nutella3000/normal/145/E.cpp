#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
//#define int long long
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
#define all(_v) _v.begin(), _v.end()
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;

const int inf = 1e9;
const int max_n = (1 << 20);

struct node {
    int l, r, sw;
    vector<int> s, c;

    node() {
        s.resize(2);
        c.resize(2);
    }

    node(vector<int> s, vector<int> c, int l, int r, int sw) : s(s), c(c), l(l), r(r), sw(sw) {}
};  

int n;
node s[2 * max_n];


void pushup(int v) {
    int l = v * 2, r = v * 2 + 1;

    for(int i = 0;i < 2;i++) {
        s[v].s[i] = s[l].s[i] + s[r].s[i];
        s[v].c[i] = max(s[l].c[i] + s[r].s[1 - i], s[l].s[i] + s[r].c[i]);
    }
}

void update(int v) {
    swap(s[v].s[0], s[v].s[1]);
    swap(s[v].c[0], s[v].c[1]);
    s[v].sw ^= 1;
}

void pushdown(int v) {
    if (!s[v].sw) return;
    s[v].sw = 0;
    update(v * 2);
    update(v * 2 + 1);
}

void build(int v, int l, int r, string& a) {
    if (l == r) {
        s[v] = {{a[l] == '4', a[l] == '7'}, {1, 1}, l, r, 0};
        return;
    }

    int mid = (l + r) / 2;
    build(v * 2, l, mid, a);
    build(v * 2 + 1, mid + 1, r, a);
    pushup(v);
    s[v].l = s[v * 2].l;
    s[v].r = s[v * 2 + 1].r;
}

void upd(int v, int l, int r) {
    if (s[v].l > r || s[v].r < l) return;
    if (s[v].l >= l && s[v].r <= r) {
        update(v);
        return;
    }
    pushdown(v);
    upd(v * 2, l, r);
    upd(v * 2 + 1, l, r);
    pushup(v);
}

int get() {
    return s[1].c[0];
}

void solve() {
    int q;
    string temp;
    cin >> n >> q >> temp;
    build(1, 0, n - 1, temp);

    for(int i = 0;i < q;i++) {
        cin >> temp;
        if (temp == "switch") {
            int l, r;
            cin >> l >> r;
            upd(1, l - 1, r - 1);

            /*for(int j = 0;j < 10;j++) {
                cout << j << " " << s[j].l << " " << s[j].r << " " << s[j].s[0] << " " << s[j].c[0] << endl;
            }*/
        }else {
            cout << get() << endl;
        }
    }
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}