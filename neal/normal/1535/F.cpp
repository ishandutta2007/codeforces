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


const int WHY = 1337;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    auto solve_pair = [](const string &x, const string &y) -> int {
        assert(x != y);
        int n = int(x.size());
        int prefix = 0, suffix = 0;

        while (x[prefix] == y[prefix])
            prefix++;

        while (x[n - 1 - suffix] == y[n - 1 - suffix])
            suffix++;

        return is_sorted(x.begin() + prefix, x.end() - suffix) || is_sorted(y.begin() + prefix, y.end() - suffix) ? 1 : 2;
    };

    auto solve = [&](vector<string> group) -> int64_t {
        assert(!group.empty());
        int n = int(group.size());
        int len = int(group[0].size());

        if (n <= 200 * len) {
            int64_t ans = 0;

            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++)
                    ans += solve_pair(group[i], group[j]);

            return ans;
        }

        sort(group.begin(), group.end());
        int64_t ans = 2 * n * (n - 1LL) / 2;

        for (const string &str : group)
            for (int i = 0; i < len; i++)
                for (int j = i + 2; j <= len; j++) {
                    string other = str;
                    sort(other.begin() + i, other.begin() + j);
                    ans -= str[i] != other[i] && str[j - 1] != other[j - 1] && binary_search(group.begin(), group.end(), other);
                }

        return ans;
    };

    int N;
    cin >> N;
    map<string, vector<string>> groups;
    int64_t ans = WHY * N * (N - 1LL) / 2;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        string sorted = s;
        sort(sorted.begin(), sorted.end());
        groups[sorted].push_back(s);
    }

    for (auto &pr : groups) {
        vector<string> group = pr.second;
        int n = int(group.size());
        ans -= WHY * n * (n - 1LL) / 2;
        ans += solve(group);
    }

    cout << ans << '\n';
}