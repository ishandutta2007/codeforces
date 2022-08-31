#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 1e6 + 1;
const int m = 1e9 + 7;
const int P = 998244353;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

struct seg_tree2 {
    vector<int> tree{}, upde{};
    int n{};

    void build(int k) {
        n = k;
        tree.resize(n * 8, 0);
        upde.resize(n * 8, 0);
    }

    void push(int v) {
        upde[v * 2] += upde[v];
        upde[v * 2 + 1] += upde[v];
        tree[v * 2] += upde[v];
        tree[v * 2 + 1] += upde[v];
        upde[v] = 0;
    }

    void upd(int v, int l, int r, int lq, int rq, int x) {
        if (r <= lq || l >= rq) return;
        push(v);
        if (lq <= l && r <= rq) {
            tree[v] += x;
            upde[v] += x;
            return;
        }
        upd(v * 2, l, (l + r) / 2, lq, rq, x);
        upd(v * 2 + 1, (l + r) / 2, r, lq, rq, x);
        tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
    }

    int get(int v, int l, int r, int lq, int rq) {
        if (r <= lq || l >= rq) return INFi;
        push(v);
        if (lq <= l && r <= rq) {
            return tree[v];
        }
        return min(get(v * 2, l, (l + r) / 2, lq, rq),
                   get(v * 2 + 1, (l + r) / 2, r, lq, rq));
    }

    void upd(int lq, int rq, int x) {
        upd(1, 0, n, lq, rq, x);
    }

    int get(int lq, int rq) {
        return get(1, 0, n, lq, rq);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), pos(n);
    range(i, n) cin >> p[i];
    range(i, n) pos[p[i] - 1] = i + 1;
    seg_tree2 st2;
    st2.build(n);
    int j = n - 1;
    st2.upd(0, pos[j], -1);
    range(i, n) {
        cout << j + 1 << " ";
        int q; cin >> q;
        st2.upd(0, q, 1);
        while(st2.get(0, n) >= 0) {
            j--;
            st2.upd(0, pos[j], -1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}