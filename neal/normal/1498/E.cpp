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

    int N;
    cin >> N;
    vector<int> K(N);
    vector<int> freq(N, 0);

    for (auto &k : K) {
        cin >> k;
        freq[k]++;
    }

    if (*max_element(freq.begin(), freq.end()) == 1) {
        cout << "! 0 0" << endl;
        return 0;
    }

    vector<int> sorted(N);
    iota(sorted.begin(), sorted.end(), 0);
    sort(sorted.begin(), sorted.end(), [&](int a, int b) {
        return K[a] < K[b];
    });

    vector<array<int, 2>> pairs;

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            pairs.push_back({sorted[i], sorted[j]});

    sort(pairs.begin(), pairs.end(), [&](array<int, 2> a, array<int, 2> b) {
        int da = K[a[1]] - K[a[0]];
        int db = K[b[1]] - K[b[0]];

        if (da != db)
            return da > db;

        return K[a[0]] > K[b[0]];
    });

    for (auto &pr : pairs) {
        cout << "? " << pr[1] + 1 << ' ' << pr[0] + 1 << endl;
        string result;
        cin >> result;

        if (result == "Yes") {
            cout << "! " << pr[1] + 1 << ' ' << pr[0] + 1 << endl;
            return 0;
        }
    }

    assert(false);
}