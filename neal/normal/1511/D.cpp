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


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, K;
    cin >> N >> K;
    string choices(K, '?');
    iota(choices.begin(), choices.end(), 'a');
    string ans;

    for (int i = 0; i < K; i++) {
        ans += char('a' + i);
        ans += char('a' + i);

        for (int j = i + 2; j < K; j++)
            if (j != i && j != (i + 1) % K && j != (i + K - 1) % K) {
                ans += char('a' + j);
                ans += char('a' + i);
            }
    }

    for (int i = K - 1; i >= 0; i--)
        ans += char('a' + (i + 1) % K);

    if (K == 2)
        ans = "aabb";
    else if (K == 1)
        ans = "a";

    // cerr << ans << endl;

    // for (int i = 0; i < int(ans.size()) - 1; i++)
    //     for (int j = i + 1; j < int(ans.size()) - 1; j++)
    //         assert(ans.substr(i, 2) != ans.substr(j, 2));

    while (int(ans.size()) < N)
        ans += ans;

    while (int(ans.size()) > N)
        ans.pop_back();

    cout << ans << '\n';
}