#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 1e6 + 123;
const ll LINF = (ll) 1e18 + 1e9 + 123;

#define rep(i, s, t) for (auto i = (s); i < (t); ++(i))
#define per(i, s, t) for (auto i = (s); i >= (t); --(i))
#define sz(x) ((int)(x).size())
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

auto mini(auto &x, const auto &y) {
    if (y < x) {
        x = y;
        return 1;
    }
    return 0;
}

auto maxi(auto &x, const auto &y) {
    if (y > x) {
        x = y;
        return 1;
    }
    return 0;
}

void run();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}

const int N = 10005;

int n, q;
int x[N];
vector<int> tree[4 * N];
bitset<N> ans;

void add(int i, int tl, int tr, int l, int r, int ind) {
    if (tl >= r || tr <= l) {
        return;
    }
    if (l <= tl && tr <= r) {
        tree[i].pb(ind);
        return;
    }
    int tm = (tl + tr) / 2;
    add(2 * i + 1, tl, tm, l, r, ind);
    add(2 * i + 2, tm, tr, l, r, ind);
}

void solve(int i, int tl, int tr, bitset<N> cur) {
    if (tl >= tr) {
        return;
    }
    for (int id : tree[i]) {
        cur |= (cur << x[id]);
    }
    if (tl == tr - 1) {
        ans |= cur;
        return;
    }
    int tm = (tl + tr) / 2;
    solve(2 * i + 1, tl, tm, cur);
    solve(2 * i + 2, tm, tr, cur);
}

void run() {
    cin >> n >> q;
    rep(i, 0, q) {
        int l, r;
        cin >> l >> r >> x[i];
        add(0, 0, n, l - 1, r, i);
    }
    bitset<N> what;
    what[0] = 1;
    solve(0, 0, n, what);
    vector<int> res;
    rep(i, 1, n + 1) if (ans[i]) res.pb(i);
    cout << sz(res) << "\n";
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";
}