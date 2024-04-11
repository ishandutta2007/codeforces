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
bool all_same(const vector<T> &v) {
    return all_of(v.begin(), v.end(), [&](T x) { return x == v.front(); });
}

void run_case() {
    int N;
    cin >> N;
    map<array<int, 3>, int> save;
    int max_query = -1;

    auto query = [&](int i, int j, int k) -> int {
        if (i > j) swap(i, j);
        if (j > k) swap(j, k);
        if (i > j) swap(i, j);

        assert(i < j && j < k);
        array<int, 3> key = {i, j, k};

        if (save.find(key) != save.end())
            return save[key];

        cout << "? " << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
        int result;
        cin >> result;

        if (result < 0)
            exit(0);

        max_query = max(max_query, result);
        save[key] = result;
        return result;
    };

    vector<int> first_results;
    int largest = 2;

    for (int i = 2; i < N; i++) {
        first_results.push_back(query(0, 1, i));

        if (query(0, 1, i) >= query(0, 1, largest))
            largest = i;
    }

    vector<int> second_results;
    int second = 1;

    for (int i = 1; i < N; i++)
        if (i != largest) {
            second_results.push_back(query(0, i, largest));

            if (query(0, i, largest) >= query(0, second, largest))
                second = i;
        }

    int occur = int(count(second_results.begin(), second_results.end(), max_query));

    if (occur == 1) {
        if (all_same(first_results) && (second == 1 || query(0, 1, second) == max_query) && query(0, 1, largest) == max_query)
            cout << "! " << 1 << ' ' << 2 << endl;
        else
            cout << "! " << second + 1 << ' ' << largest + 1 << endl;
    } else {
        cout << "! " << 1 << ' ' << largest + 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}