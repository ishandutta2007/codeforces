#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
#include <functional>
#include <random>
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

struct segment_tree {
    struct Node {
        int ud = 0;
        pair<int, int> val = {0, 1};
    };

    vector<Node> tree{};
    int n{};

    void build(int k) {
        n = k;
        tree.resize(n * 8);
        make(1, 0, n);
    }

    void push(int v) {
        tree[v<<1].ud += tree[v].ud;
        tree[(v<<1)+1].ud += tree[v].ud;
        tree[v<<1].val.first += tree[v].ud;
        tree[(v<<1)+1].val.first += tree[v].ud;
        tree[v].ud = 0;
    }

    void make(int v, int l, int r) {
        if (l + 1 == r) {
            return;
        }
        make(v<<1, l, (l+r)>>1);
        make((v<<1)+1, (l+r)>>1, r);
        tree[v].val.second = r-l;
    }

    void upd(int v, int l, int r, int lq, int rq, int x) {
        if (r <= lq || l >= rq) return;
        if (lq <= l && r <= rq) {
            tree[v].ud += x;
            tree[v].val.first += x;
            return;
        }
        push(v);
        upd(v<<1, l, (l+r)>>1, lq, rq, x);
        upd((v<<1)+1, (l+r)>>1, r, lq, rq, x);
        auto a = tree[v<<1].val;
        auto b = tree[(v<<1)+1].val;
        tree[v].val = {min(a.first, b.first), a.second * (a.first <= b.first) + b.second * (b.first <= a.first)};
    }

    pair<int, int> get(int v, int l, int r, int lq, int rq) {
        if (r <= lq || l >= rq) return {INFi, 0};
        if (lq <= l && r <= rq) {
            return tree[v].val;
        }
        push(v);
        auto a = get(v<<1, l, (l+r)>>1, lq, rq);
        auto b = get((v<<1)+1, (l+r)>>1, r, lq, rq);
        return {min(a.first, b.first), a.second * (a.first <= b.first) + b.second * (b.first <= a.first)};
    }

    void upd(int lq, int rq, int x) {
        upd(1, 0, n, lq, rq, x);
    }

    pair<int, int> get(int lq, int rq) {
        return get(1, 0, n, lq, rq);
    }
};

void solve() {
    int n; cin >> n;
    segment_tree st; st.build(n);
    vector<int> a(n);
    range(i, n) cin >> a[i];
    vector<vector<int>> cl(n+1);
    range(i, n) cl[a[i]].push_back(i);
    ll ans = 0;
    range(i, n) {
        int j = lower_bound(all(cl[a[i]]), i) - cl[a[i]].begin();
        if(j) {
            st.upd(0, cl[a[i]][j-1]+1, -1);
            if (j - 1 >= 2) {
                int e = 0;
                if (j - 1 >= 3) {
                    e = cl[a[i]][j-4]+1;
                }
                st.upd(e, cl[a[i]][j-3]+1, 1);
            }
        }
        st.upd(0, i+1, 1);
        if (j >= 2) {
            int e = 0;
            if (j >= 3) {
                e = cl[a[i]][j-3]+1;
            }
            st.upd(e, cl[a[i]][j-2]+1, -1);
        }
        auto w = st.get(0, i+1);
        if (w.first == 0) ans += w.second;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}