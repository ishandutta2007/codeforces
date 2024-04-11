/*

      #     #     #####  #####  #           #  #
     # #   # #    #      #   #  #     #     #  #
    #   # #   #   #####  #   #   #   # #   #   #
   #     #     #  #      #   #    # #   # #     
   #           #  #####  #####     #     #     @

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;
const ld EPS = (ld) 1e-7;
const ll MOD = (ll) 1e9 + 7;

#define sz(x) (int) (x).size()
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lb(s, t, x) (int) (lower_bound(s, t, x) - s)
#define ub(s, t, x) (int) (upper_bound(s, t, x) - s)
#define rep(i, f, t) for (int i = f; i < t; i++)

ll power(ll x, ll y, ll mod = MOD) {
    if (y == 0) {
        return 1;
    }
    if (y & 1) {
        return power(x, y - 1, mod) * x % mod;
    } else {
        ll tmp = power(x, y / 2, mod);
        return tmp * tmp % mod;
    }
}

template<typename A, typename B> bool mini(A &x, const B &y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

template<typename A, typename B> bool maxi(A &x, const B &y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

template<typename T> void read(T first, T last) {
    while (first != last) {
        cin >> *(first++);
    }
}

template<typename T> void print(T first, T last) {
    while (first != last) {
        cout << *(first++) << " ";
    }
    cout << "\n";
}  

void run();

#define TASK ""

int main() {
#ifdef LOCAL
    if (strlen(TASK) > 0) {
        cerr << "Reminder: you are using file i/o, filename: " TASK "!" << endl << endl;
    }
#endif
#ifndef LOCAL
    if (strlen(TASK)) {
        freopen(TASK ".in", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    cout << fixed << setprecision(12);
    run();
    return 0;
}

// == SOLUTION == //

struct Treap {
    Treap *l, *r;
    int x, y;
    int cnt, toadd;
    
    Treap(int x) : l(0), r(0), x(x), y(rand()), cnt(1), toadd(0) {}
};

int get_cnt(Treap *t) {
    return t == 0 ? 0 : t->cnt;
}

void push(Treap *t) {
    if (t == 0) {
        return;
    }
    t->x += t->toadd;
    if (t->l != 0) {
        t->l->toadd += t->toadd;
    }
    if (t->r != 0) {
        t->r->toadd += t->toadd;
    }
    t->toadd = 0;
}

void recalc(Treap *t) {
    if (t == 0) {
        return;
    }
    t->cnt = 1 + get_cnt(t->l) + get_cnt(t->r);
}

Treap* merge(Treap *a, Treap *b) {
    push(a);
    push(b);
    if (a == 0 || b == 0) {
        return a == 0 ? b : a;
    }
    
    Treap *res;
    if (a->y > b->y) {
        a->r = merge(a->r, b);
        res = a;
    } else {
        b->l = merge(a, b->l);
        res = b;
    }
    recalc(res);
    return res;
}

pair<Treap*, Treap*> split(Treap *t, int k) {
    push(t);
    if (k == 0 || t == 0) {
        return {0, t};
    }
    
    if (get_cnt(t->l) >= k) {
        auto a = split(t->l, k);
        t->l = a.second;
        a.second = t;
        recalc(t);
        return a;
    } else {
        auto a = split(t->r, k - get_cnt(t->l) - 1);
        t->r = a.first;
        a.first = t;
        recalc(t);
        return a;
    }
}

int lower_bound(Treap *t, int x) {
    push(t);
    if (t == 0) {
        return INF;
    }
    if (t->x >= x) {
        return min(lower_bound(t->l, x), get_cnt(t->l) + 1);
    } else {
        return lower_bound(t->r, x) + get_cnt(t->l) + 1;
    }
}

Treap *t;

void upd(int l, int r) {
    int bl = lower_bound(t, l);
    int br = lower_bound(t, r);
    auto a = split(t, br);
    auto b = split(a.first, br - 1);
    a.first = b.first;
    b = split(a.first, bl - 1);
    if (b.second != 0) {
        b.second->toadd++;
    }
    b.second = merge(new Treap(l), b.second);
    a.first = merge(b.first, b.second);
    t = merge(a.first, a.second);
}

void print(Treap *t, bool first = true) {
    push(t);
    if (t == 0) {
        return;
    }
    print(t->l, false);
    cerr << t->x << " ";
    print(t->r, false);
    if (first) {
        cout << "\n";
    }
}

void run() {
    int n;
    cin >> n;
    t = new Treap(0);
    rep(i, 0, n + 2) {
        t = merge(t, new Treap(INF));
    }
    rep(i, 0, n) {
        int l, r;
        cin >> l >> r;
        upd(l, r);
        //print(t);
    }
    
    int q = lower_bound(t, INF);
    cout << q - 2 << "\n";
}