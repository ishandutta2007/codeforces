#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <cstring>
#include <map>

#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const int INF = 1e9 * 2;

struct segment_tree {
    struct Node {
        int digits[9]{};
        int bad = INF;

        Node(int x=0) {
            int fx = x;
            range(i, 9) {
                if (fx % 10) {
                    digits[i] = x;
                }
                fx /= 10;
            }
        }
    };

    Node combine(Node &a, Node &b) {
        Node res = 0;
        res.bad = min(a.bad, b.bad);
        range(i, 9) {
            if (a.digits[i] && b.digits[i]) {
                res.digits[i] = min(a.digits[i], b.digits[i]);
                res.bad = min(res.bad, a.digits[i] + b.digits[i]);
            } else {
                res.digits[i] = max(a.digits[i], b.digits[i]);
            }
        }
        return res;
    }

    int n;
    vector<Node> tree;

    segment_tree(const int &n, const vector<int> &a) : n(n), tree(n * 4) {
        range(i, n) {
            update(i, a[i]);
        }
    }

    void update(int pos, int x, int v = 1, int l = 0, int r = -1) {
        if (r == -1) r = n;
        if (l + 1 == r) {
            tree[v] = x;
            return;
        }
        int mid = (l + r) / 2;
        if (l <= pos && pos < mid) {
            update(pos, x, v * 2, l, mid);
        } else {
            update(pos, x, v * 2 + 1, mid, r);
        }
        tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
    }

    Node get(int lq, int rq, int v = 1, int l = 0, int r = -1) {
        if (r == -1) r = n;
        if (r <= lq || l >= rq) return 0;
        if (lq <= l && r <= rq) {
            return tree[v];
        }
        Node a = get(lq, rq, v * 2, l, (l + r) / 2);
        Node b = get(lq, rq, v * 2 + 1, (l + r) / 2, r);
        return combine(a, b);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    range(i, n) {
        cin >> a[i];
    }
    segment_tree st(n, a);
    while (m--) {
        int t;
        cin >> t;
        if (--t) {
            int l, r; cin >> l >> r;
            int ans = st.get(l - 1, r).bad;
            if (ans == INF) cout << -1;
            else cout << ans;
            cout << '\n';
        } else {
            int i, x;
            cin >> i >> x;
            st.update(i - 1, x);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}