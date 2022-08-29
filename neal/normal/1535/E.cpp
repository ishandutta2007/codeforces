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


const int LOG = 19;

int main() {
    ios::sync_with_stdio(false);

    vector<int> P, A, C;
    vector<array<int, LOG>> ancestor;

    auto add_node = [&](int p, int a, int c) -> void {
        P.push_back(p);
        A.push_back(a);
        C.push_back(c);
        array<int, LOG> anc;
        anc[0] = p;

        for (int k = 1; k < LOG; k++)
            anc[k] = anc[k - 1] < 0 ? -1 : ancestor[anc[k - 1]][k - 1];

        ancestor.push_back(anc);
    };

    auto get_anc = [&](int v, int up) -> int {
        for (int k = 0; 1 << k <= up; k++)
            if (up >> k & 1)
                v = ancestor[v][k];

        return v;
    };

    auto query = [&](int v, int w) -> pair<int64_t, int64_t> {
        int top = v, up = 0;

        for (int k = LOG - 1; k >= 0; k--)
            if (ancestor[top][k] >= 0 && A[ancestor[top][k]] > 0) {
                top = ancestor[top][k];
                up += 1 << k;
            }

        pair<int64_t, int64_t> result = {0, 0};

        for (int d = up; d >= 0 && w > 0; d--) {
            int node = get_anc(v, d);
            int take = min(w, A[node]);
            A[node] -= take;
            w -= take;
            result.first += take;
            result.second += int64_t(take) * C[node];
        }

        return result;
    };

    int Q, A0, C0;
    cin >> Q >> A0 >> C0;
    add_node(-1, A0, C0);
    vector<int> compress(Q, -1);

    for (int q = 0; q < Q; q++) {
        int type;
        cin >> type;

        if (type == 1) {
            int p, a, c;
            cin >> p >> a >> c;

            if (p > 0)
                p = compress[p - 1];

            compress[q] = int(P.size());
            add_node(p, a, c);
        } else {
            int v, w;
            cin >> v >> w;

            if (v > 0)
                v = compress[v - 1];

            pair<int64_t, int64_t> bought = query(v, w);
            cout << bought.first << ' ' << bought.second << endl;
        }
    }
}