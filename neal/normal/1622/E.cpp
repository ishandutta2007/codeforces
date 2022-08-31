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

struct identity {
    template<typename T>
    T operator()(const T &x) const {
        return x;
    }
};

// A stable sort that takes O(n + range) time, where range = max key - min key.
// Note that radix sort is almost always more efficient in practice.
template<typename T, typename T_extract_key = identity>
void counting_sort(vector<T> &data, const T_extract_key &extract_key = identity()) {
    if (data.empty())
        return;

    using T_key = decltype(extract_key(data.front()));
    T_key minimum = extract_key(data.front()), maximum = extract_key(data.front());

    for (T &x : data) {
        minimum = min(minimum, extract_key(x));
        maximum = max(maximum, extract_key(x));
    }

    int range = int(maximum - minimum);
    vector<int> counts(range + 1, 0);

    for (T &x : data)
        counts[extract_key(x) - minimum]++;

    int count_sum = 0;

    for (int &count : counts) {
        int current = count;
        count = count_sum;
        count_sum += current;
    }

    vector<T> buffer(data.size());

    for (T &x : data) {
        T_key key = T_key(extract_key(x) - minimum);
        buffer[counts[key]++] = x;
    }

    swap(data, buffer);
}

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


void run_case() {
    int N, M;
    cin >> N >> M;
    vector<int> X(N);

    for (auto &x : X)
        cin >> x;

    vector<string> answers(N);

    for (auto &row : answers)
        cin >> row;

    vector<int> column(M, 0);

    for (int i = 0; i < N; i++)
        for (int q = 0; q < M; q++)
            column[q] |= (answers[i][q] - '0') << i;

    int best = -1;
    vector<int> best_perm;

    for (int mask = 0; mask < 1 << N; mask++) {
        vector<pair<int, int>> question_value(M);

        for (int q = 0; q < M; q++) {
            int value = 2 * __builtin_popcount(column[q] & mask) - __builtin_popcount(column[q]);
            question_value[q] = {value, q};
        }

        // sort(question_value.begin(), question_value.end());
        counting_sort(question_value, [](const pair<int, int> &p) { return p.first; });
        vector<int> perm(M);
        int sum = 0;

        for (int i = 0; i < N; i++)
            sum += (mask >> i & 1 ? -1 : +1) * X[i];

        for (int q = 0; q < M; q++) {
            sum += question_value[q].first * (q + 1);
            perm[question_value[q].second] = q;
        }

        if (sum > best) {
            best = sum;
            best_perm = perm;
        }
    }

    output_vector(best_perm, true);
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