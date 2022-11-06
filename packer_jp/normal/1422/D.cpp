#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define reps(i, n) for (int i = 1; i <= (int) (n); i++)
#define all(a) (a).begin(), (a).end()
#define uniq(a) (a).erase(unique(all(a)), (a).end())
#define bit(n) (1LL << (n))
#define dump(a) cerr << #a " = " << (a) << endl
using vint = vector<int>;
using pint = pair<int, int>;
using vpint = vector<pint>;
template<typename T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
constexpr double PI = 3.1415926535897932384626433832795028;
constexpr int DY[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr int DX[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
int sign(int a) { return (a > 0) - (a < 0); }
int gcd(int a, int b) {
    while (b) { swap(a %= b, b); }
    return a;
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }
int cdiv(int a, int b) { return (a - 1 + b) / b; }
template<typename T> void fin(T a) {
    cout << a << endl;
    exit(0);
}
template<typename T> T sq(T a) { return a * a; }
template<typename T, typename U> bool chmax(T &a, const U &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<typename T, typename U> bool chmin(T &a, const U &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
template<typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &a) {
    os << "(" << a.first << ", " << a.second << ")";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const vector<T> &a) {
    os << "{";
    for (auto itr = a.begin(); itr != a.end(); itr++) {
        os << *itr << (next(itr) != a.end() ? ", " : "");
    }
    os << "}";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const deque<T> &a) {
    os << "{";
    for (auto itr = a.begin(); itr != a.end(); itr++) {
        os << *itr << (next(itr) != a.end() ? ", " : "");
    }
    os << "}";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const set<T> &a) {
    os << "{";
    for (auto itr = a.begin(); itr != a.end(); itr++) {
        os << *itr << (next(itr) != a.end() ? ", " : "");
    }
    os << "}";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &a) {
    os << "{";
    for (auto itr = a.begin(); itr != a.end(); itr++) {
        os << *itr << (next(itr) != a.end() ? ", " : "");
    }
    os << "}";
    return os;
}
template<typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &a) {
    os << "{";
    for (auto itr = a.begin(); itr != a.end(); itr++) {
        os << *itr << (next(itr) != a.end() ? ", " : "");
    }
    os << "}";
    return os;
}
struct setup {
    static constexpr int PREC = 20;
    setup() {
        cout << fixed << setprecision(PREC);
        cerr << fixed << setprecision(PREC);
    };
} setup;

template<typename S>
struct dijkstra {
    using T = typename S::T;
    using E = typename S::E;
    std::vector<std::vector<int>> adj;
    std::vector<std::vector<E>> cost;
    dijkstra(int n) : adj(n), cost(n) {}
    void add_edge(int from, int to, E cost) { adj[from].emplace_back(to), this->cost[from].emplace_back(cost); }
    std::vector<T> get_dist(int s) {
        std::vector<T> ret(adj.size(), S::inf());
        using P = std::pair<T, int>;
        auto c = [&](P a, P b) -> bool { return S::less(b.first, a.first); };
        std::priority_queue<P, std::vector<P>, decltype(c)> pq(c);
        ret[s] = S::zero();
        pq.emplace(ret[s], s);
        while (!pq.empty()) {
            P p = pq.top();
            pq.pop();
            int v = p.second;
            if (S::less(ret[v], p.first)) { continue; }
            for (int i = 0; i < adj[v].size(); i++) {
                int u = adj[v][i];
                T dist = S::plus(ret[v], cost[v][i]);
                if (S::less(dist, ret[u])) { ret[u] = dist, pq.emplace(ret[u], u); }
            }
        }
        return ret;
    }
};

struct int_dij {
    using T = int;
    using E = int;
    static T zero() { return 0; }
    static T inf() { return std::numeric_limits<T>::max(); }
    static T plus(const T &a, const E &b) { return a == inf() ? inf() : a + b; }
    static bool less(const T &a, const T &b) { return a < b; }
};

signed main() {
    int n, m;
    cin >> n >> m;
    vint a(m), b(m);
    int sy, sx, fy, fx;
    cin >> sy >> sx >> fy >> fx;
    rep(i, m) { cin >> a[i] >> b[i]; }
    vint ac(a), bc(b);
    sort(all(ac)), uniq(ac);
    sort(all(bc)), uniq(bc);
    int na = ac.size(), nb = bc.size();
    map<int, int> za, zb;
    rep(i, na) { za[ac[i]] = i; }
    rep(i, nb) { zb[bc[i]] = i; }
    dijkstra<int_dij> dij(na + nb + m + 2);
    int s = na + nb + m, t = na + nb + m + 1;
    rep(i, na - 1) { dij.add_edge(i, i + 1, ac[i + 1] - ac[i]), dij.add_edge(i + 1, i, ac[i + 1] - ac[i]); }
    rep(i, nb - 1) {
        dij.add_edge(na + i, na + i + 1, bc[i + 1] - bc[i]), dij.add_edge(na + i + 1, na + i, bc[i + 1] - bc[i]);
    }
    rep(i, m) {
        dij.add_edge(na + nb + i, za[a[i]], 0);
        dij.add_edge(za[a[i]], na + nb + i, 0);
        dij.add_edge(na + nb + i, na + zb[b[i]], 0);
        dij.add_edge(na + zb[b[i]], na + nb + i, 0);
    }
    rep(i, m) {
        dij.add_edge(s, na + nb + i, min(abs(a[i] - sy), abs(b[i] - sx)));
        dij.add_edge(na + nb + i, t, abs(fy - a[i]) + abs(fx - b[i]));
    }
    if (za.count(sy) != 0) { dij.add_edge(s, za[sy], 0); }
    if (zb.count(sx) != 0) { dij.add_edge(s, na + zb[sx], 0); }
    dij.add_edge(s, t, abs(fy - sy) + abs(fx - sx));
    cout << dij.get_dist(s)[t] << endl;
}