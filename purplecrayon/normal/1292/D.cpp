#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 5e3+10, MOD = 1e9+7;

bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++) if (x % i == 0) return 0;
    return 1;
}
auto lca(vector<int> a, vector<int> b) {
    int n = sz(a);
    int last = n-1;
    while (last >= 0 && a[last] == b[last]) last--;
    // last = index of the last unequal thing
    if (last < 0) return a;
    for (int i = 0; i < last; i++) a[i] = b[i] = 0;
    a[last] = b[last] = min(a[last], b[last]);
    return a;
}
int depth(vector<int> a) {
    return std::accumulate(a.begin(), a.end(), 0);
}

vector<ll> sub;
ll dfs_sub(const auto& edges, const auto& weights, int c) {
    sub[c] = weights[c];
    for (auto [nxt, d] : edges[c]) {
        sub[c] += dfs_sub(edges, weights, nxt);
    }
    return sub[c];
}
int dfs_centroid(const auto& edges, int c, ll total) {
    for (auto [nxt, d] : edges[c]) {
        if (sub[nxt] * 2 >= total)
            return dfs_centroid(edges, nxt, total);
    }
    return c;
}
int get_centroid(const auto& edges, const auto& weights) {
    sub.resize(sz(edges));
    dfs_sub(edges, weights, 0);
    return dfs_centroid(edges, 0, sub[0]);
}
ll dfs_answer(const auto& edges, const auto& weights, int c, int p, ll d) {
    ll ans = d * weights[c];
    for (auto [nxt, w] : edges[c]) if (nxt != p) {
        ans += dfs_answer(edges, weights, nxt, c, d + w);
    }
    return ans;
}
ll get_answer(const auto& edges, const auto& weights, int c) {
    return dfs_answer(edges, weights, c, -1, 0);
}
string ts(vector<int> v) {
    string ans = "{";
    for (int i = 0; i < sz(v); i++) {
        if (i) ans += " ";
        ans += to_string(v[i]);
    }
    ans += "}";
    return ans;
}
void solve() {
    int M; cin >> M;
    vector<int> cnt(N);
    while (M--) {
        int x; cin >> x;
        x = max(x, 1);
        cnt[x]++;
    }
    vector<int> prime;
    for (int i = 2; i < N; i++) {
        if (is_prime(i)) {
            prime.push_back(i);
        }
    }

    int n = sz(prime);
    vector<int> sum(n);

    vector<vector<int>> me(N);
    vector<vector<int>> tree;
    for (int i = 0; i < N; i++) {
        int c = i;
        for (int j = 0; j < n; j++) {
            while (c > 0 && c % prime[j] == 0) {
                sum[j]++;
                c /= prime[j];
            }
        }
        me[i] = sum;
        if (cnt[i]) tree.push_back(sum);
    }
    
    // sorting by time is equivalent to sorting by value (because everything is a factorial)
    int start_tree = sz(tree);
    for (int i = 0; i < start_tree-1; i++) {
        tree.push_back(lca(tree[i], tree[i+1]));
    }
    std::stable_sort(tree.begin(), tree.end(), [&](auto one, auto two) {
        assert(sz(one) == sz(two));
        for (int i = sz(one)-1; i >= 0; i--) if (one[i] != two[i]) {
            return one[i] < two[i];
        }
        return false;
    });
    tree.resize(unique(tree.begin(), tree.end()) - tree.begin());
    map<vector<int>, int> rev;
    for (int i = 0; i < sz(tree); i++) rev[tree[i]] = i;

    int k = sz(tree);
    vector<vector<pair<int, int>>> edges(k);
    for (int i = 0; i < sz(tree)-1; i++) {
        auto par = lca(tree[i], tree[i+1]);
        edges[rev[par]].emplace_back(i + 1, depth(tree[i+1]) - depth(par));
    }
    vector<int> weights(k);
    for (int i = 0; i < N; i++) {
        weights[rev[me[i]]] += cnt[i];
    }
    int root = get_centroid(edges, weights);

    auto new_edges = edges;
    for (int a = 0; a < k; a++) {
        for (auto [b, w] : edges[a]) {
            new_edges[b].emplace_back(a, w);
        }
    }

    cout << get_answer(new_edges, weights, root) << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}