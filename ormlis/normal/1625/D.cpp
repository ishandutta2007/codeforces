#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 2e3 + 5;
const int LG = 29;

struct Node {
    int i;
    Node *l, *r;

    Node() : l(nullptr), r(nullptr), i(-1) {}
};

void add(Node *&a, int x, int i, int h) {
    if (!a) {
        a = new Node();
    }
    if (h == -1) {
        a->i = i;
        return;
    }
    if ((1 << h) & x) {
        add(a->r, x, i, h - 1);
    } else {
        add(a->l, x, i, h - 1);
    }
}

int k;
vi ans;

void dfs3(Node *a, int h) {
    if (!a) return;
    if (h == -1) {
        ans.push_back(a->i);
        return;
    }
    if (a->l) dfs3(a->l, h - 1);
    else dfs3(a->r, h - 1);
}

bool dfs2(Node *a, Node *b, int h) {
    if (!a || !b) return false;
    if (h == -1) {
        ans.push_back(a->i);
        ans.push_back(b->i);
        return true;
    }
    if ((1 << h) & k) {
        if (a->l && b->r) {
            if (dfs2(a->l, b->r, h - 1)) return true;
        }
        if (a->r && b->l) {
            if (dfs2(a->r, b->l, h - 1)) return true;
        }
        return false;
    } else {
        if (a->l && b->r) {
            dfs3(a->l, h - 1);
            dfs3(b->r, h - 1);
            return true;
        } else if (a->r && b->l) {
            dfs3(a->r, h - 1);
            dfs3(b->l, h - 1);
            return true;
        } else if (a->l) {
            return dfs2(a->l, b->l, h - 1);
        } else {
            return dfs2(a->r, b->r, h - 1);
        }
    }
}

void dfs1(Node *a, int h) {
    if (!a) return;
    if ((1 << h) & k) {
        if (!dfs2(a->l, a->r, h - 1)) {
            dfs3(a, h);
        }
    } else {
        dfs1(a->l, h - 1);
        dfs1(a->r, h - 1);
    }
}

void solve() {
    int n;
    cin >> n >> k;
    if (k == 0) {
        cout << n << '\n';
        rep(i, n) cout << i + 1 << ' ';
        cout << '\n';
        return;
    }
    Node *root = nullptr;
    rep(i, n) {
        int x;
        cin >> x;
        add(root, x, i + 1, LG);
    }
    dfs1(root, LG);
    if (ans.size() < 2) {
        cout << "-1\n";
        return;
    }
    cout << ans.size() << '\n';
    for (auto &i : ans) cout << i << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}