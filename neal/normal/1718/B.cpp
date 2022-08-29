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

vector<int64_t> fibonacci;

void build_fibonacci() {
    fibonacci = {1, 1};

    while (fibonacci.back() <= int64_t(1e12))
        fibonacci.push_back(fibonacci[fibonacci.size() - 2] + fibonacci.back());
}


void run_case() {
    int N;
    cin >> N;
    vector<int64_t> C(N);

    for (auto &c : C)
        cin >> c;

    sort(C.begin(), C.end());
    int64_t length = accumulate(C.begin(), C.end(), 0LL);

    if (!binary_search(fibonacci.begin(), fibonacci.end(), length + 1)) {
        cout << "NO" << '\n';
        return;
    }

    int f_count = int(upper_bound(fibonacci.begin(), fibonacci.end(), length) - fibonacci.begin()) - 1;
    int last_used = -1;

    for (int f = f_count - 1; f >= 0; f--) {
        int biggest = -1;

        for (int i = 0; i < N; i++) {
            if (i == last_used)
                continue;

            if (biggest < 0 || C[i] > C[biggest])
                biggest = i;
        }

        if (biggest < 0 || C[biggest] < fibonacci[f]) {
            cout << "NO" << '\n';
            return;
        }

        C[biggest] -= fibonacci[f];
        last_used = biggest;
    }

    assert(all_of(C.begin(), C.end(), [](int64_t x) { return x == 0; }));
    cout << "YES" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    build_fibonacci();

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}