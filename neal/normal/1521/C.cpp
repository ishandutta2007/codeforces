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

auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };

const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);


void run_case() {
    int N;
    cin >> N;

    auto query_max = [&](int i, int j) -> int {
        cout << "? " << 1 << ' ' << i + 1 << ' ' << j + 1 << ' ' << N - 1 << endl;
        int result;
        cin >> result;

        if (result == N - 1) {
            cout << "? " << 1 << ' ' << j + 1 << ' ' << i + 1 << ' ' << N - 1 << endl;
            int second;
            cin >> second;
            result = max(result, second);
        }

        return result;
    };

    auto query_min = [&](int i, int j) -> int {
        cout << "? " << 2 << ' ' << i + 1 << ' ' << j + 1 << ' ' << 1 << endl;
        int result;
        cin >> result;

        if (result == 2) {
            cout << "? " << 2 << ' ' << j + 1 << ' ' << i + 1 << ' ' << 1 << endl;
            int second;
            cin >> second;
            result = min(result, second);
        }

        return result;
    };

    vector<int> A(N);
    A[0] = query_min(0, 1);
    A[1] = query_max(0, 1);
    int x = query_min(1, 2);
    int y = query_max(1, 2);

    if (A[1] != x && A[1] != y) {
        swap(A[0], A[1]);
        assert(A[1] == x || A[1] == y);
    }

    A[2] = x + y - A[1];

    auto evaluate = [&](int index) -> int {
        return min(A[index] - 1, N - A[index]);
    };

    int extreme = 0;

    for (int i = 1; i <= 2; i++)
        if (evaluate(i) < evaluate(extreme))
            extreme = i;

    vector<int> order;

    for (int i = 3; i < N; i++)
        order.push_back(i);

    shuffle(order.begin(), order.end(), rng);

    for (int index : order) {
        int value = -1;

        if (A[extreme] <= N / 2) {
            value = query_max(extreme, index);

            if (value == A[extreme])
                value = query_min(extreme, index);
        } else {
            value = query_min(extreme, index);

            if (value == A[extreme])
                value = query_max(extreme, index);
        }

        A[index] = value;

        if (evaluate(index) < evaluate(extreme))
            extreme = index;
    }

    cout << '!';

    for (int a : A)
        cout << ' ' << a;

    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}