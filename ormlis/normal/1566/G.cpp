#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
using namespace __gnu_pbds;


typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

/*
typedef tree<
        pair<ll, int>,
        null_type,
        less<pair<ll, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

const int INFi = 1e9 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;
const int maxN = 2e5 + 5;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

int V[maxN], U[maxN], W[maxN];
set<pair<int, int>> wedges[maxN];
set<pair<int, int>> good_edges;
ll current[maxN];
vector<int> cnt;
vector<int> us;
multiset<ll> values;

void check_edge(int i) {
    if (us[i] && cnt[i] == 2) return;
    if (!us[i] && cnt[i] != 2) return;
    if (us[i]) {
        good_edges.erase({W[i], i});
    } else {
        good_edges.insert({W[i], i});
    }
    us[i] ^= 1;
}

void check_vertex(int a) {
    if (current[a] != -1) {
        values.erase(values.find(current[a]));
    }
    if (wedges[a].size() < 3) {
        current[a] = -1;
        return;
    }
    current[a] = 0;
    auto it = wedges[a].begin();
    range(_, 3) {
        current[a] += it->first;
        it++;
    }
    values.insert(current[a]);
}

void check_edges_from_vertex(int v, int x) {
    auto it = wedges[v].begin();
    range(_, min((int)wedges[v].size(), 3)) {
        cnt[it->second] += x;
        check_edge(it->second);
        it++;
    }
}

void add(int i) {
    int a = V[i];
    int b = U[i];
    int w = W[i];
    check_edges_from_vertex(a, -1);
    check_edges_from_vertex(b, -1);
    wedges[a].insert({w, i});
    wedges[b].insert({w, i});
    check_edges_from_vertex(a, 1);
    check_edges_from_vertex(b, 1);
    check_vertex(a);
    check_vertex(b);
}

void del(int i) {
    int a = V[i];
    int b = U[i];
    int w = W[i];
    check_edges_from_vertex(a, -1);
    check_edges_from_vertex(b, -1);
    wedges[a].erase({w, i});
    wedges[b].erase({w, i});
    check_edges_from_vertex(a, 1);
    check_edges_from_vertex(b, 1);
    check_vertex(a);
    check_vertex(b);
}

const int K = 4;

ll get_ans() {
    vector<int> edges;
    auto it = good_edges.begin();
    range(_, min((int)good_edges.size(), K)) {
        edges.push_back(it->second);
        it++;
    }
    ll ans = INF;
    if (!values.empty()) ans = *values.begin();
    for(auto &i : edges) {
        for(auto &j : edges) {
            if (i == j) break;
            int a = V[i];
            int b = U[i];
            int c = V[j];
            int d = U[j];
            if (a == d || a == c || b == d || b == c) continue;
            ans = min(ans, 1ll * W[j] + W[i]);
        }
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    map<pair<int, int>, int> to;
    range(i, m) {
        cin >> V[i] >> U[i] >> W[i];
        if (V[i] > U[i]) swap(V[i], U[i]);
        to[{V[i], U[i]}] = i;
    }
    int q;
    cin >> q;
    vector<pair<int, int>> qs;
    int cur = m;
    range(_, q) {
        int t;
        cin >> t;
        int u, v;
        cin >> u >> v;
        if (v > u) swap(u, v);
        if (t == 1) {
            int w;
            cin >> w;
            V[cur] = v;
            U[cur] = u;
            W[cur] = w;
            to[{v, u}] = cur;
            qs.push_back({1, cur});
            cur++;
        } else {
            qs.push_back({0, to[{v, u}]});
        }
    }
    cnt.resize(cur);
    us.resize(cur);
    range(i, n + 1) current[i] = -1;
    range(i, m) {
        add(i);
    }
    cout << get_ans() << '\n';
    for (auto &[tp, j] : qs) {
        if (tp == 1) {
            add(j);
        } else {
            del(j);
        }
        cout << get_ans() << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}