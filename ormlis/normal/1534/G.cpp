#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int INFi = 2e9 + 5;
const int maxN = 4e5 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Treap {
    int y{};
    int xs{};
    int x{};
    int p{};
    int addp{};
    //int sz{};

    Treap *l = nullptr, *r = nullptr;

    Treap(int _x, int _p = 0) : y(rng()), xs(_x), p(_p), addp(0), x(_x) {}
};

int get_xs(Treap *a) {
    if (!a) return 0;
    return a->xs;
}

void upd(Treap *a) {
    if (!a) return;
    a->xs = a->x + get_xs(a->l) + get_xs(a->r);
}

void check(Treap *a, int x) {
    if (!a) return;
    a->addp += x;
    a->p += x;
}

void push(Treap *a) {
    if (!a || !a->addp) return;
    check(a->l, a->addp);
    check(a->r, a->addp);
    a->addp = 0;
}

typedef pair<Treap *, Treap *> ptt;

Treap *merge(Treap *a, Treap *b) {
    if (!a) return b;
    if (!b) return a;
    if (a->y > b->y) {
        push(a);
        a->r = merge(a->r, b);
        upd(a);
        return a;
    } else {
        push(b);
        b->l = merge(a, b->l);
        upd(b);
        return b;
    }
}

// Try : [0, x]
ptt split1(Treap *a, int x) {
    if (!a) return {nullptr, nullptr};
    push(a);
    if (get_xs(a->l) + a->x <= x) {
        auto[b, c] = split1(a->r, x - get_xs(a->l) - a->x);
        a->r = b;
        upd(a);
        return {a, c};
    } else {
        auto[b, c] = split1(a->l, x);
        a->l = c;
        upd(a);
        return {b, a};
    }
}


ptt split2(Treap *a, int x) {
    if (!a) return {nullptr, nullptr};
    push(a);
    if (get_xs(a->l) < x) {
        auto[b, c] = split2(a->r, x - get_xs(a->l) - a->x);
        a->r = b;
        upd(a);
        return {a, c};
    } else {
        auto[b, c] = split2(a->l, x);
        a->l = c;
        upd(a);
        return {b, a};
    }
}

ptt splitP(Treap *a, int p) {
    if (!a) return {nullptr, nullptr};
    push(a);
    if (a->p < p) {
        auto[b, c] = splitP(a->r, p);
        a->r = b;
        upd(a);
        return {a, c};
    } else {
        auto[b, c] = splitP(a->l, p);
        a->l = c;
        upd(a);
        return {b, a};
    }
}

ll ans = 0;
void dfs(Treap *t) {
    if (!t) return;
    push(t);
    dfs(t->l);
    if (t->p < 0) {
        ans += 1ll * t->p * t->x;
    }
    dfs(t->r);
}

void solve() {
    int n; cin >> n;
    vector<int> x(n), y(n);
    range(i, n) cin >> x[i] >> y[i];
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&] (const int &i, const int &j) {
        return x[i] + y[i] < x[j] + y[j];
    });
    priority_queue<int> sl;
    priority_queue<int, vector<int>, greater<int>> sr;
    sl.push(0);
    sr.push(0);
    for(auto &i : ord) {
        ans += x[i];
        if (x[i] < sl.top()) {
            sl.push(x[i]);
            sl.push(x[i]);
            sr.push(sl.top() - x[i] - y[i]);
            sl.pop();
        } else if (x[i] > sr.top() + x[i] + y[i]) {
            sr.push(-y[i]);
            sr.push(-y[i]);
            sl.push(sr.top() + x[i] + y[i]);
            sr.pop();
        } else {
            sl.push(x[i]);
            sr.push(-y[i]);
        }
    }
    int coef = 0;
    int p = 0;
    range(_, n + 1) {
        int w = sl.top();
        sl.pop();
        ans -= 1ll * (p - w) * coef;
        coef++;
        p = w;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}