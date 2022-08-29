#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

struct union_find {
    // When data[x] < 0, x is a root and -data[x] is its tree size. When data[x] >= 0, data[x] is x's parent.
    vector<int> data;
    int components = 0;

    union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        data.assign(n + 1, -1);
        components = n;
    }

    int find(int x) {
        return data[x] < 0 ? x : data[x] = find(data[x]);
    }

    int get_size(int x) {
        return -data[find(x)];
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (-data[x] < -data[y])
            swap(x, y);

        data[x] += data[y];
        data[y] = x;
        components--;
        return true;
    }
};


const int INF = int(1e9) + 5;

void run_case() {
    int N, K;
    cin >> N >> K;
    vector<int> X(N), Y(N), T(N);
    map<int, set<pair<int, int>>> x_to_y, y_to_x;

    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i] >> T[i];
        x_to_y[X[i]].emplace(Y[i], i);
        y_to_x[Y[i]].emplace(X[i], i);
    }

    union_find UF(N);

    for (int i = 0; i < N; i++) {
        auto it = x_to_y[X[i]].lower_bound(make_pair(Y[i] + 1, 0));

        if (it != x_to_y[X[i]].end() && it->first <= Y[i] + K)
            UF.unite(i, it->second);

        it = y_to_x[Y[i]].lower_bound(make_pair(X[i] + 1, 0));

        if (it != y_to_x[Y[i]].end() && it->first <= X[i] + K)
            UF.unite(i, it->second);
    }

    vector<int> component_min_time(N, INF);

    for (int i = 0; i < N; i++) {
        int root = UF.find(i);
        component_min_time[root] = min(component_min_time[root], T[i]);
    }

    sort(component_min_time.begin(), component_min_time.end());
    component_min_time.resize(UF.components);
    int C = UF.components;
    int best = C - 1;

    for (int i = 0; i < C; i++) {
        int suffix_time = max(C - i - 2, 0);
        best = min(best, max(component_min_time[i], suffix_time));
    }

    cout << best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}