#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e18 + 7;

struct Line {
    ll k, b;

    Line(ll k, ll b): k(k), b(b) {}

    Line(): k(0), b(INF) {}

    ll operator()(ll x) {
        return k * x + b;
    }
};

struct LiChaoSegmentTree {
    static const int T = (1 << 23);

    Line tree[T];

    int n;

    void init(int len) {
        n = len;
    }

    void update2(int v, int l, int r, Line newLine) {
        bool dominateLeft = (newLine(l) < tree[v](l));
        bool dominateRight = (newLine(r) < tree[v](r));
        if (l + 1 == r || dominateLeft == dominateRight) {
            if (dominateLeft) {
                tree[v] = newLine;
            }
            return;
        }
        int mid = (r + l) / 2;
        bool dominateMid = (newLine(mid) < tree[v](mid));
        if (dominateLeft == dominateMid) {
            if (dominateLeft) {
                update(2 * v + 1, mid, r, tree[v]);
                tree[v] = newLine;
            } else {
                update(2 * v + 1, mid, r, newLine);
            }
        } else {
            if (dominateRight) {
                update(2 * v, l, mid, tree[v]);
                tree[v] = newLine;
            } else {
                update(2 * v, l, mid, newLine);
            }
        }
    }

    void update(int v, int l, int r, Line newLine) {
        bool dominateLeft = (newLine(l) < tree[v](l));
        int mid = (r + l) / 2;
        bool dominateMid = (newLine(mid) < tree[v](mid));
        if (dominateMid) {
            swap(newLine, tree[v]);
        }
        if (l + 1 == r) {
            return;
        } else if (dominateLeft == dominateMid) {
            update(2 * v + 1, mid, r, newLine);
        } else {
            update(2 * v, l, mid, newLine);
        }
    }

    void update(Line newLine) {
        update(1, -n, n, newLine);
    }

    ll get(int v, int l, int r, int pos) {
        ll ans = tree[v](pos);
        if (l + 1 != r) {
            int mid = (r + l) / 2;
            if (pos < mid) {
                ans = min(ans, get(2 * v, l, mid, pos));
            } else {
                ans = min(ans, get(2 * v + 1, mid, r, pos));
            }
        }
        return ans;
    }

    ll get(int pos) {
        return get(1, -n, n, pos);
    }

} segTree;
/*
void solve() {
    int n;
    cin >> n;
    segTree.init(100001);
    for (int i = 0; i < n; i++) {
        int a0, a1, a2, a3;
        cin >> a0 >> a1 >> a2 >> a3;
        segTree.update(Line(a1, a0));
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        cout << segTree.get(x) << '\n';
    }
}

int main() {
    int tests;
    cin >> tests;
    while (tests--) {
        solve();
    }
}*/

const int MAXN = 200001;

ll a[MAXN], pref[MAXN];

int main()
{
    ll sum = 0;
    int n;
    cin >> n;
    pref[0] = 0;
    segTree.init(1123456);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
        sum += i * a[i];
    }
    ll ans = sum;
    for (int i = n; i >= 1; i--)
    {
        segTree.update(Line(i, pref[i]));
        ll cur = -segTree.get(-a[i]) + sum - i * a[i] + pref[i];
        ans = max(ans, cur);
    }
    for (int i = 0; i < segTree.T; i++) {
        segTree.tree[i] = Line();
    }
    for (int i = 1; i <= n; i++)
    {
        segTree.update(Line(-i, pref[i - 1]));
        ll cur = -segTree.get(a[i]) + sum - i * a[i] + pref[i - 1];
        ans = max(ans, cur);
    }
    cout << ans;
    return 0;
}