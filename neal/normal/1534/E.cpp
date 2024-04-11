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


int main() {
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    if (N % 2 != 0 && K % 2 == 0) {
        cout << -1 << endl;
        return 0;
    }

    auto solve = [&](int ones) -> bool {
        if (ones % K != 0)
            return false;

        int extra = ones - N;
        int moves = ones / K;

        if (extra % 2 != 0)
            return false;

        int remaining = extra / 2;
        int max_column = 1 + 2 * ((remaining + N - 1) / N);

        if (max_column > moves)
            return false;

        cerr << ones << " ones" << endl;
        vector<int> columns(N, 1);

        for (int i = 0; i < N; i++)
            columns[i] += 2 * ((remaining + i) / N);

        dbg(ones, columns);
        assert(*max_element(columns.begin(), columns.end()) <= moves);
        int64_t xor_sum = 0;

        for (int m = 0; m < moves; m++) {
            vector<int> indices(N);
            iota(indices.begin(), indices.end(), 0);

            nth_element(indices.begin(), indices.begin() + K, indices.end(), [&](int a, int b) {
                return columns[a] > columns[b];
            });

            indices.resize(K);
            string str(N, '0');

            for (int index : indices) {
                str[index] = '1';
                columns[index]--;
            }

            dbg(str);
            cout << '?';

            for (int index : indices)
                cout << ' ' << index + 1;

            cout << endl;
            int64_t x;
            cin >> x;
            xor_sum ^= x;
        }

        cout << "! " << xor_sum << endl;
        return true;
    };

    int ones = N;

    while (!solve(ones))
        ones++;
}