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
#include <cassert>
#include <iomanip>
// #include <ext/pb_ds/assoc_container.hpp>

// using namespace __gnu_pbds;

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }


struct segment_tree {
    int n{};
    vector<int> tree{};

    void build(int k) {
        n = k;
        tree.resize(n * 4, -1);
    }


    void upd(int v, int l, int r, int pos, ll x) {
        if (l > pos || r <= pos) return;
        if (l + 1 == r) {
            tree[v] = x;
            return;
        }
        upd(v << 1, l, (l + r) >> 1, pos, x);
        upd((v << 1) + 1, (l + r) >> 1, r, pos, x);
        tree[v] = min(tree[v << 1], tree[(v << 1) + 1]);
    }

    ll get(int v, int l, int r, int lq, int rq) {
        if (l >= rq || r <= lq) return INF;
        if (lq <= l && r <= rq) {
            return tree[v];
        }
        return min(get(v << 1, l, (l + r) >> 1, lq, rq),
                   get((v << 1) + 1, (l + r) >> 1, r, lq, rq));
    }

    void upd(int pos, ll x) {
        upd(1, 0, n, pos, x);
    }

    ll get(int lq, int rq) {
        return get(1, 0, n, lq, rq);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool flag = false;
    range(i, n) {
        cin >> a[i];
        a[i]--;
        if (a[i]) flag = true;
    }
    if (!flag) {
        cout << "1\n";
        return;
    }
    segment_tree st;
    st.build(n + 5);
    vector<int> previous(n + 5, -1);
    vector<int> kek(n + 5, 0);
    range(i, n) {
        ll x = st.get(0, a[i]);
        if (x > previous[a[i]]) {
            kek[a[i]] = 1;
        }
        previous[a[i]] = i;
        st.upd(a[i], i);
    }
    range(i, n + 5) {
        ll x = st.get(0, i);
        if (x > previous[i]) {
            kek[i] = 1;
        }
        if (!kek[i]) {
            cout << i + 1 << "\n";
            return;
        }
    }
    cout << n + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}