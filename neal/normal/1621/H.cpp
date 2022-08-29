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


const int64_t INF64 = int64_t(2e18) + 5;
const char MIN_CHAR = 'A';

struct query {
    vector<int> pass, fine;
    int index;
};

template<typename T>
int insertion_sort_add(vector<T> &v, T x) {
    int index = int(v.size());
    v.push_back(x);

    while (index > 0 && x < v[index - 1]) {
        swap(v[index], v[index - 1]);
        index--;
    }

    return index;
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    cin >> N;
    vector<vector<pair<int, int64_t>>> adj(N);

    for (int i = 0; i < N - 1; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        u--; v--;
        adj[u].emplace_back(v, t);
        adj[v].emplace_back(u, t);
    }

    int K;
    string zone;
    cin >> K >> zone;
    assert(zone[0] == 'A');
    vector<int> pass(K), fine(K);

    for (auto &p : pass)
        cin >> p;

    for (auto &f : fine)
        cin >> f;

    int T, Q;
    cin >> T >> Q;
    vector<vector<query>> queries(N);
    int query_count = 0;

    for (int q = 0; q < Q; q++) {
        int type;
        cin >> type;

        if (type == 1) {
            char z;
            int c;
            cin >> z >> c;
            pass[z - MIN_CHAR] = c;
        } else if (type == 2) {
            char z;
            int c;
            cin >> z >> c;
            fine[z - MIN_CHAR] = c;
        } else {
            int u;
            cin >> u;
            u--;
            query qry;
            qry.pass = pass;
            qry.fine = fine;
            qry.index = query_count++;
            queries[u].push_back(qry);
        }
    }

    vector<int64_t> answers(query_count, -1);

    y_combinator([&](auto self, int node, int parent, int64_t weighted_depth, int64_t parent_depth, vector<pair<int, int>> events,
                     vector<int64_t> zone_count, int start_mask, int64_t zone_start, char previous_zone) -> int64_t {
        bool is_new_zone = zone[node] != previous_zone;

        if (is_new_zone) {
            int z = previous_zone - MIN_CHAR;
            int64_t previous_length = parent_depth - zone_start;
            zone_count[z] = previous_length / T;

            int before = int(zone_start % T);
            int after = int(parent_depth % T);

            pair<int, int> before_event = {before + 1, z};
            pair<int, int> after_event = {after + 1, z};
            insertion_sort_add(events, before_event);
            insertion_sort_add(events, after_event);

            if (after < before)
                start_mask |= 1 << z;

            zone_start = parent_depth;
            previous_zone = zone[node];
        }

        int index = int(lower_bound(events.begin(), events.end(), make_pair(int(weighted_depth % T + 1), 0)) - events.begin());
        int64_t event_mask = 1LL << index;

        for (auto &e : adj[node])
            if (e.first != parent)
                event_mask |= self(e.first, node, weighted_depth + e.second, weighted_depth, events, zone_count, start_mask, zone_start, previous_zone);

        for (query &qry : queries[node]) {
            int current = zone[node] - MIN_CHAR;
            int mask = start_mask;
            int64_t cost = 0;

            auto eval_zone = [&](int z) -> int64_t {
                return int64_t(min<long double>(qry.pass[z], 1.0L * qry.fine[z] * (zone_count[z] + (mask >> z & 1))));
            };

            for (int z = 0; z < current; z++)
                cost += eval_zone(z);

            int64_t best = INF64;

            for (int i = 0; i < int(events.size()); i++) {
                if (event_mask >> i & 1)
                    best = min(best, cost);

                int z = events[i].second;
                cost -= eval_zone(z);
                mask ^= 1 << z;
                cost += eval_zone(z);
            }

            if (event_mask >> events.size() & 1)
                best = min(best, cost);

            answers[qry.index] = best;
        }

        return is_new_zone ? 0 : event_mask;
    })(0, -1, 0, 0, vector<pair<int, int>>(), vector<int64_t>(K, 0), 0, 0, zone[0]);

    for (auto &ans : answers)
        cout << ans << '\n';
}