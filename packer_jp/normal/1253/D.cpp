#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, n) for (int i = 1; i <= (n); i++)
#define all(x) (x).begin(), (x).end()
#define uniq(x) (x).erase(unique(all(x)), (x).end())
#define bit(n) (1LL << (n))
#define dump(x) cerr << #x " = " << (x) << endl
using vint=vector<int>;
using vvint=vector<vint>;
using pint=pair<int, int>;
using vpint=vector<pint>;
template<typename T> using priority_queue_rev=priority_queue<T, vector<T>, greater<T>>;
constexpr double pi = 3.1415926535897932384626433832795028;
constexpr int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
constexpr int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int gcd(int a, int b) {
    while (b) { swap(a %= b, b); }
    return a;
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }
template<typename T1, typename T2> bool chmax(T1 &a, const T2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<typename T1, typename T2> bool chmin(T1 &a, const T2 &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &rhs) {
    os << "(" << rhs.first << ", " << rhs.second << ")";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const vector<T> &rhs) {
    os << "{";
    for (auto itr = rhs.begin(); itr != rhs.end(); itr++) {
        os << *itr << (next(itr) != rhs.end() ? ", " : "");
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

struct union_find_tree {
    int n;
    std::vector<int> par, size;
    union_find_tree(int n) : n(n), par(n), size(n) {
        for (int i = 0; i < n; i++) {
            par[i] = i;
            size[i] = 1;
        }
    }
    int get_root(int i) {
        if (par[i] == i) { return i; }
        else { return par[i] = get_root(par[i]); }
    }
    void unite(int i, int j) {
        if ((i = get_root(i)) == (j = get_root(j))) { return; }
        if (size[i] < size[j]) { std::swap(i, j); }
        par[j] = i;
        size[i] += size[j];
    }
    bool are_same(int i, int j) { return get_root(i) == get_root(j); }
    int get_size(int i) { return size[get_root(i)]; }
};

int n, m;
int u[220000], v[220000];
int imos[220000];
signed main() {
    cin >> n >> m;
    rep(i, m) { cin >> u[i] >> v[i]; }
    int cc = n;
    union_find_tree uf(n + 1);
    rep(i, m) {
        if (u[i] > v[i]) { swap(u[i], v[i]); }
        imos[u[i]]++, imos[v[i]]--;
        if (!uf.are_same(u[i], v[i])) { cc--, uf.unite(u[i], v[i]); }
    }
    reps(i, n) { imos[i] += imos[i - 1]; }
    int f = 0;
    reps(i, n) { if (imos[i] == 0) { f++; }}
    cout << cc - f << endl;
}