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

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


bool perfect_square(int64_t x) {
    int64_t s = int64_t(round(sqrt(x)));
    return s * s == x;
}

vector<int64_t> solve(int64_t N) {
    if (N == 1)
        return {};

    auto standard = [&]() -> vector<int64_t> {
        vector<int64_t> remove;

        while (N % 4 != 0)
            remove.push_back(N--);

        remove.push_back(N / 2);
        reverse(remove.begin(), remove.end());
        return remove;
    };

    if (N % 4 == 3) {
        if (perfect_square(N + 1))
            return {N / 2 + 1, N};
        else if (perfect_square(2 * (N / 2) * (N / 2 - 1)))
            return {N / 2 - 2, N};
        else if (perfect_square((N / 2 - 1) * N))
            return {N / 2 - 2, N - 2};
        else
            return {2, N / 2, N};
    } else if (N % 4 == 2) {
        if (perfect_square(2 * (N / 2 + 1)))
            return {N / 2 + 1};
        else if (perfect_square(2 * (N / 2) * (N / 2 - 1)))
            return {N / 2 - 2};
        else
            return {2, N / 2};
    }

    return standard();
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int64_t N;
    cin >> N;
    vector<int64_t> remove = solve(N);
    vector<int64_t> remaining;

    for (int64_t i = 1; i <= N; i++)
        if (find(remove.begin(), remove.end(), i) == remove.end())
            remaining.push_back(i);

    cout << remaining.size() << '\n';
    output_vector(remaining);
    // cerr << remove << endl;
}