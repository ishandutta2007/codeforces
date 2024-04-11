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
const int maxN = 1e3 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

const vector<string> strs = {"lock", "unlock", "red", "orange", "yellow", "green", "blue", "indigo", "violet"};

struct segment_tree {
    struct Node {
        bool lock = false;
        bool unlock = false;
        bool unlock_left = false;
        int col = -1;

        void combine(const Node &a, const Node &b) {
            lock = false;
            unlock = false;
            col = -1;
            if (b.col != -1 && (!a.lock || b.unlock_left)) {
                col = b.col;
                unlock_left = a.unlock | b.unlock_left;
            } else {
                col = a.col;
                unlock_left = a.unlock_left;
            }
            lock = b.lock;
            if (a.lock && !b.unlock) lock = true;
            unlock = a.unlock | b.unlock;
        }

        void check(int x) {
            lock = unlock = false;
            col = -1;
            if (x == 0) lock = true;
            else if (x == 1) unlock = true;
            else col = x;
        }
    };

    vector<Node> tree{};
    int n{};

    void build(int k) {
        n = k;
        tree.resize(n * 4);
    }

    void upd(int v, int l, int r, int &pos, int &val) {
        if (l > pos || r <= pos) return;
        if (l + 1 == r) {
            tree[v].check(val);
            return;
        }
        upd(v << 1, l, (l + r) >> 1, pos, val);
        upd(v << 1 | 1, (l + r) >> 1, r, pos, val);
        tree[v].combine(tree[v << 1], tree[v << 1 | 1]);
    }

    int get() {
        return tree[1].col;
    }

    void upd(int pos, int val) {
        upd(1, 0, n, pos, val);
    }
};

int num_col(const string &s) {
    return find(all(strs), s) - strs.begin();
}

void solve() {
    int n; cin >> n;
    segment_tree st;
    st.build(n + 1);
    st.upd(0, num_col("blue"));
    for(int i = 1; i <= n; ++i) {
        string s; cin >> s;
        st.upd(i, num_col(s));
    }
    int q; cin >> q;
    cout << strs[st.get()] << '\n';
    while(q--) {
        int i; cin >> i;
        string s; cin >> s;
        st.upd(i, num_col(s));
        cout << strs[st.get()] << '\n';
    }

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