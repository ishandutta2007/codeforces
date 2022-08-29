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


const int64_t M_MAX = 1e14;
const int QUERIES_MAX = 105;

void run_case() {
    int64_t balance = 1;
    int queries = 0;

    auto query = [&](int64_t x) {
        assert(queries++ < QUERIES_MAX);
        cout << "? " << x << endl;
        string response;
        cin >> response;

        if (response[0] == 'L') {
            balance += x;
            return true;
        }

        assert(balance >= x);
        balance -= x;
        return false;
    };

    if (!query(1)) {
        cout << "! 0" << endl;
        return;
    }

    int64_t low = 1;

    while (balance <= M_MAX && query(balance))
        low = balance / 2;

    int64_t high = min(2 * low, M_MAX + 1);

    auto get_mid = [&](double ratio) {
        int64_t mid = int64_t(round(double(low) + ratio * double(high - low)));
        mid = min(max(mid, low + 1), high - 1);
        return mid;
    };

    while (high - low > 1) {
        int64_t money = balance / low;
        int64_t mid = get_mid((0.5 - 0.5 / double(money + 1)) * pow(high / low, 0.2));
        assert(low < mid && mid < high);

        if (balance < mid) {
            query(low);
            continue;
        }

        if (query(mid))
            low = mid;
        else
            high = mid;
    }

    cout << "! " << low << endl;
}

int main() {
    ios::sync_with_stdio(false);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}