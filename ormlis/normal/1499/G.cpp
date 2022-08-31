#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

typedef long long ll;

using namespace std;
//using namespace __gnu_pbds;

const int INFi = 2e9 + 5;
const int maxN = 4e5 + 100;
const int md = 998244353;
const ll INF = 2e18;

inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

int color[maxN];
int to[maxN];

int hashes[maxN];
int H = 0;

struct path {
    deque<int> vd;
    deque<int> edges;
    int i;
    int start_col;
    int end_col;

    void add_edge(int v, int u, int k) {
        if (vd.empty()) {
            vd.push_back(u);
            vd.push_back(v);
            to[v] = to[u] = i;
            edges.push_back(k);
            H = add(H, hashes[k]);
            color[k] = 1;
            start_col = end_col = 1;
            return;
        }
        to[v] = -1;
        if (vd.back() == v) {
            vd.push_back(u);
            edges.push_back(k);
            end_col ^= 1;
            if (end_col) {
                H = add(H, hashes[k]);
                color[k] = 1;
            } else {
                color[k] = -1;
            }
        } else if (vd.front() == v) {
            vd.push_front(u);
            edges.push_front(k);
            start_col ^= 1;
            if (start_col) {
                H = add(H, hashes[k]);
                color[k] = 1;
            } else {
                color[k] = -1;
            }
        } else {
            assert(0);
        }
        if (vd.back() == vd.front()) {
            to[vd.back()] = to[vd.front()] = -1;
            return;
        }
        to[u] = i;
    }

    void merge(path &b, int v, int u, int k) {
        if (b.i == i) {
            add_edge(v, u, k);
            return;
        }
        for (int j = 0; j < b.edges.size(); ++j) {
            if ((j ^ b.start_col)&1 ) {
                H = sub(H, hashes[b.edges[j]]);
            }
        }
        if (b.vd.front() == u) {
            reverse(all(b.vd));
            reverse(all(b.edges));
        }
        to[b.vd.back()] = to[b.vd.front()] = -1;
        to[v] = -1;
        b.edges.push_back(k);
        if (vd.front() == v) {
            while (!b.vd.empty()) {
                k = b.edges.back();
                start_col ^= 1;
                if (start_col) {
                    H = add(H, hashes[k]);
                    color[k] = 1;
                } else {
                    color[k] = -1;
                }
                edges.push_front(k);
                vd.push_front(b.vd.back());
                b.vd.pop_back();
                b.edges.pop_back();
            }
        } else {
            assert(vd.back() == v);
            while (!b.vd.empty()) {
                k = b.edges.back();
                edges.push_back(k);
                end_col ^= 1;
                if (end_col) {
                    H = add(H, hashes[k]);
                    color[k] = 1;
                } else {
                    color[k] = -1;
                }
                vd.push_back(b.vd.back());
                b.vd.pop_back();
                b.edges.pop_back();
            }
        }
        assert(vd.back() != vd.front());
        to[vd.back()] = to[vd.front()] = i;
    }
};

path paths[maxN];
int R = 0;

int create() {
    paths[R].i = R;
    return R++;
}

int K = 1;

void init() {
    hashes[0] = 1;
    for (int i = 1; i < maxN; ++i) hashes[i] = mul(hashes[i - 1], 2);
}

void new_edge(int u, int v) {
    if (to[u] == -1 && to[v] == -1) {
        int nw = create();
        paths[nw].add_edge(v, u, K);
        K++;
        return;
    }
    if (to[u] != -1 && to[v] != -1) {
        if (paths[to[u]].vd.size() > paths[to[v]].vd.size()) {
            swap(u, v);
        }
        paths[to[v]].merge(paths[to[u]], v, u, K);
        K++;
        return;
    }
    if (to[v] == -1) swap(u, v);
    paths[to[v]].add_edge(v, u, K);
    K++;
}

void print() {
    vector<int> answer;
    for (int i = 1; i <= K; ++i) {
        if (color[i] == 1) answer.push_back(i);
    }
    cout << answer.size() << ' ';
    for (auto &u : answer) cout << u << ' ';
    cout << endl;
}

void solve() {
    init();
    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    range(i, n1 + n2 + 5) to[i] = -1;
    range(_, m) {
        int u, v;
        cin >> u >> v;
        v += n1;
        new_edge(u, v);
    }
    int q;
    cin >> q;
    range(_, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int v1, v2;
            cin >> v1 >> v2;
            v2 += n1;
            new_edge(v1, v2);
            cout << H << endl;
        } else {
            print();
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}