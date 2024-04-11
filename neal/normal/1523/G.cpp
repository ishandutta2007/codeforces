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

int highest_bit(int x) {
    return x == 0 ? -1 : 31 - __builtin_clz(x);
}

// Enables online insertion of (key, value) pairs and querying of maximum value out of keys at least a given limit.
// To query minimums instead, set maximum_mode = false.
template<typename T_key, typename T_value, bool maximum_mode, T_value V_INF>
struct online_suffix_max {
    map<T_key, T_value> optimal;

    static bool is_better(T_value a, T_value b) {
        return maximum_mode ? b < a : a < b;
    }

    static T_value default_value() {
        return maximum_mode ? (is_signed<T_value>::value ? -V_INF : 0) : V_INF;
    }

    int size() const {
        return int(optimal.size());
    }

    // Queries the maximum value in the map over all entries with key < `key_limit`.
    T_value query(T_key key_limit) const {
        auto it = optimal.lower_bound(key_limit);
        return it == optimal.end() ? default_value() : it->second;
    }

    // Adds an entry to the map and discards entries that are now obsolete.
    void insert(T_key key, T_value value) {
        auto it = optimal.lower_bound(key);

        // Quit if value is suboptimal.
        if (it != optimal.end() && !is_better(value, it->second))
            return;

        if (it != optimal.end() && it->first == key)
            it = optimal.erase(it);

        while (it != optimal.begin() && !is_better(prev(it)->second, value))
            optimal.erase(prev(it));

        optimal.insert(it, {key, value});
    }
};


const int INF = int(1e9) + 5;

using online_suffix_min = online_suffix_max<int, int, false, INF>;

struct interval {
    int L, R;

    int length() const {
        return R - L;
    }
};

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    vector<interval> offers(M);

    for (interval &offer : offers) {
        cin >> offer.L >> offer.R;
        offer.L--;
    }

    vector<pair<int, int>> offers_by_length(M);

    for (int i = 0; i < M; i++)
        offers_by_length[i] = {offers[i].length(), i};

    sort(offers_by_length.rbegin(), offers_by_length.rend());
    vector<online_suffix_min> tree(M + 1);

    auto add_offer = [&](int index) -> void {
        for (int x = index + 1; x <= M; x += x & -x)
            tree[x].insert(offers[index].L, offers[index].R);
    };

    auto search_offer = [&](int L, int R) -> int {
        int prefix = 0;

        for (int k = highest_bit(M); k >= 0; k--)
            if (prefix + (1 << k) <= M && tree[prefix + (1 << k)].query(L) > R)
                prefix += 1 << k;

        return prefix;
    };

    vector<int> answers(N + 1, 0);
    int o_index = 0;

    for (int x = N; x > 0; x--) {
        while (o_index < M && offers_by_length[o_index].first == x)
            add_offer(offers_by_length[o_index++].second);

        y_combinator([&](auto divide, int L, int R) -> void {
            if (R - L < x)
                return;

            int next_offer = search_offer(L, R);

            if (next_offer >= M)
                return;

            answers[x] += offers[next_offer].R - offers[next_offer].L;
            divide(L, offers[next_offer].L);
            divide(offers[next_offer].R, R);
        })(0, N);
    }

    for (int x = 1; x <= N; x++)
        cout << answers[x] << '\n';
}