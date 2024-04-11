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
#include <unordered_set>
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

// Counts the number of pairs i < j such that compare(values[i], values[j]) is true.
template<typename T_array, typename T_compare>
int64_t count_pairs(T_array values, T_compare &&compare) {
    T_array buffer(values.size());

    return y_combinator([&](auto self, int start, int end) -> int64_t {
        if (end - start <= 1)
            return 0;

        int mid = (start + end) / 2;
        int64_t answer = self(start, mid) + self(mid, end);
        int left = start, right = mid, n = 0;

        while (left < mid || right < end)
            if (left < mid && (right == end || compare(values[left], values[right]))) {
                buffer[n++] = values[left++];
            } else {
                answer += left - start;
                buffer[n++] = values[right++];
            }

        copy(buffer.begin(), buffer.begin() + n, values.begin() + start);
        return answer;
    })(0, int(values.size()));
}


void run_case() {
    int N;
    cin >> N;
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    cout << (int(unordered_set<int>(A.begin(), A.end()).size()) < N || count_pairs(A, greater<int>()) % 2 == 0 ? "YES" : "NO") << '\n';
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