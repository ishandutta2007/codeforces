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



void run_case() {
    map<array<int, 2>, int> save;

    auto query = [&](int a, int b) -> int {
        if (save.find({a, b}) != save.end())
            return save[{a, b}];

        cout << "? " << a + 1 << ' ' << b + 1 << endl;
        int result;
        cin >> result;

        if (result < 0)
            exit(0);

        return save[{a, b}] = result;
    };

    auto bigger = [&](int a, int b) -> int {
        int result = query(a, b);
        assert(result != 0);
        return result == 1 ? a : b;
    };

    int N;
    cin >> N;
    vector<int> remain(1 << N);
    iota(remain.begin(), remain.end(), 0);
    int answer = -1;

    while (int(remain.size()) > 1) {
        if (remain.size() == 2) {
            answer = bigger(remain[0], remain[1]);
            break;
        }

        int R = int(remain.size());
        vector<int> nremain;

        for (int i = 0; i < R; i += 4) {
            int result = query(remain[i], remain[i + 2]);

            if (result == 1) {
                nremain.push_back(bigger(remain[i], remain[i + 3]));
            } else if (result == 2) {
                nremain.push_back(bigger(remain[i + 1], remain[i + 2]));
            } else {
                nremain.push_back(bigger(remain[i + 1], remain[i + 3]));
            }
        }

        remain.swap(nremain);
    }

    if (remain.size() == 1)
        answer = remain[0];

    cout << "! " << answer + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}