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


const string LETTERS = "ANOT";

void run_case() {
    string A;
    cin >> A;
    int N = int(A.size());

    auto evaluate = [&](const vector<int> &char_index) -> int64_t {
        array<int, 4> counts;
        counts.fill(0);
        int64_t total = 0;

        for (int i = 0; i < N; i++) {
            int index = char_index[A[i]];
            counts[index]++;

            for (int x = index + 1; x < 4; x++)
                total += counts[x];
        }

        return total;
    };

    string perm = LETTERS;
    assert(is_sorted(perm.begin(), perm.end()));
    vector<int> char_index(128, -1);
    int64_t best = -1;
    string solution;

    do {
        for (int i = 0; i < int(perm.size()); i++)
            char_index[perm[i]] = i;

        int64_t option = evaluate(char_index);

        if (option > best) {
            best = option;
            solution = A;
            sort(solution.begin(), solution.end(), [&](char x, char y) {
                return char_index[x] < char_index[y];
            });
        }
    } while (next_permutation(perm.begin(), perm.end()));

    cout << solution << '\n';
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