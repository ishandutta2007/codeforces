#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 5e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

struct seg_tree {
    struct Node {
        pair<ll, ll> mx = {-INF, -INF};
        ll upd = 0;
    };
    vector<Node> tree{};
    int n{};

    void build(int k) {
        n = k;
        tree.resize(n * 4);
        make(1, 0, n);
    }

    void make(int v, int l, int r) {
        if (l + 1 == r) {
            tree[v].mx = {-INF, l};
            return;
        }
        make(v * 2, l, (l + r) / 2);
        make(v * 2 + 1, (l + r) / 2, r);
        tree[v].mx = max(tree[v * 2].mx, tree[v * 2 + 1].mx);
    }

    void push(int v) {
        tree[v * 2].upd += tree[v].upd;
        tree[v * 2].mx.first += tree[v].upd;

        tree[v * 2 + 1].upd += tree[v].upd;
        tree[v * 2 + 1].mx.first += tree[v].upd;

        tree[v].upd = 0;
    }

    void upd(int v, int l, int r, int lq, int rq, ll x) {
        if (l >= rq || r <= lq) return;
        if (lq <= l && r <= rq) {
            tree[v].upd += x;
            tree[v].mx.first += x;
            return;
        }
        push(v);
        upd(v * 2, l, (l + r) / 2, lq, rq, x);
        upd(v * 2 + 1, (l + r) / 2, r, lq, rq, x);
        tree[v].mx = max(tree[v * 2].mx, tree[v * 2 + 1].mx);
    }

    pair<ll, ll> get(int v, int l, int r, int lq, int rq) {
        if (l >= rq || r <= lq) return {-INF, -INF};
        if (lq <= l && r <= rq) {
            return tree[v].mx;
        }
        push(v);
        return max(get(v * 2 + 1, (l + r) / 2, r, lq, rq), get(v * 2, l, (l + r) / 2, lq, rq));
    }

    void upd(int lq, int rq, ll x) {
        upd(1, 0, n, lq, rq, x);
    }

    pair<ll, ll> get(int lq, int rq) {
        return get(1, 0, n, lq, rq);
    }
};

void solve() {
    int n;
    cin >> n;
    seg_tree st;

    vector<ar<int, 3>> points(n);
    range(i, n) range(j, 3) cin >> points[i][j];

    st.build(n * 2 + 5);

    vector<int> cords;
    for (auto &p: points) {
        cords.push_back(p[0]);
        cords.push_back(p[1]);
    }
    sort(all(cords));
    cords.resize(unique(all(cords)) - cords.begin());

    map<int, int> mp;
    range(i, (int) cords.size()) mp[cords[i]] = i;

    sort(all(points), [](ar<int, 3> &a, ar<int, 3> &b) {
        return max(a[0], a[1]) < max(b[0], b[1]);
    });

    int i = 0;
    st.upd(i, i + 1, INF);
    ar<ll, 5> ans = {0, INFi, INFi, INFi, INFi};
    for (auto &point: points) {
        if (cords[i] != max(point[0], point[1])) {
            auto w = st.get(0, n * 2);
            int x1 = cords[w.second];
            ans = max(ans, {w.first, x1, x1, cords[i], cords[i]});
        }
        while (cords[i] != max(point[0], point[1])) {
            i++;
            st.upd(0, i, -(cords[i] - cords[i - 1]));
            st.upd(i, i + 1, INF);
        }
        int j = mp[min(point[0], point[1])];
        st.upd(0, j + 1, point[2]);
    }
    auto w = st.get(0, n * 2);
    int x1 = cords[w.second];
    ans = max(ans, {w.first, x1, x1, cords[i], cords[i]});
    cout << ans[0] << "\n";
    for(int j = 1; j <= 4; ++j) cout << ans[j] << " ";
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