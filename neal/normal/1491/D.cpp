#include <algorithm>
#include <array>
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


const int BITS = 30;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    auto query = [](int u, int v) -> bool {
        if (u == v)
            return true;

        if (u > v)
            return false;

        vector<int> v_bits;

        for (int b = BITS - 1; b >= 0; b--)
            if (v >> b & 1)
                v_bits.push_back(b);

        v_bits.push_back(-1);
        int current = BITS - 1;

        for (int i = 0; i < int(v_bits.size()) - 1; i++) {
            int high = v_bits[i];
            int low = v_bits[i + 1];
            current = min(current, high);
            int count = 0;

            while (current > low) {
                count += u >> current & 1;
                current--;
            }

            if (count == 0) {
                while (current >= 0 && count == 0) {
                    count += u >> current & 1;
                    current--;
                }

                if (count == 0)
                    return false;
            }
        }

        return true;
    };

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int u, v;
        cin >> u >> v;
        cout << (query(u, v) ? "YES" : "NO") << '\n';
    }
}