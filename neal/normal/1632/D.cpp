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

template<typename T>
struct RMQ {
    static int highest_bit(unsigned x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }

    int n = 0;
    vector<vector<T>> range_min;

    RMQ(const vector<T> &values = {}) {
        if (!values.empty())
            build(values);
    }

    static T better(T a, T b) {
        return __gcd(a, b);
    }

    void build(const vector<T> &values) {
        n = int(values.size());
        int levels = highest_bit(n) + 1;
        range_min.resize(levels);

        for (int k = 0; k < levels; k++)
            range_min[k].resize(n - (1 << k) + 1);

        if (n > 0)
            range_min[0] = values;

        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_min[k][i] = better(range_min[k - 1][i], range_min[k - 1][i + (1 << (k - 1))]);
    }

    T query_value(int a, int b) const {
        assert(0 <= a && a < b && b <= n);
        int level = highest_bit(b - a);
        return better(range_min[level][a], range_min[level][b - (1 << level)]);
    }
};

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    cin >> N;
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    RMQ<int> rmq(A);
    vector<int> answers(N, -1);
    int ans = 0, previous = -1;

    for (int i = 0; i < N; i++) {
        int low = previous + 1, high = i;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (rmq.query_value(mid, i + 1) >= i + 1 - mid)
                high = mid;
            else
                low = mid + 1;
        }

        int g = rmq.query_value(low, i + 1);

        if (g == i + 1 - low) {
            ans++;
            previous = i;
        }

        answers[i] = ans;
    }

    output_vector(answers);
}