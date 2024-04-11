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


const int ALPHABET = 26;
const char MIN_CHAR = 'a';

void run_case() {
    int N, K;
    string S;
    cin >> N >> K >> S;

    if (N % K != 0) {
        cout << -1 << '\n';
        return;
    }

    auto finish = [&](const string &prefix, const vector<int> &freq) -> bool {
        dbg(prefix, freq);
        int additional = 0;

        for (int c = 0; c < ALPHABET; c++)
            if (freq[c] % K != 0)
                additional += K - freq[c] % K;

        if (int(prefix.size()) + additional > N)
            return false;

        string remain;

        for (int c = 0; c < ALPHABET; c++)
            if (freq[c] % K != 0)
                remain += string(K - freq[c] % K, char(MIN_CHAR + c));

        int extra = N - int(prefix.size() + remain.size());
        remain = string(extra, MIN_CHAR) + remain;
        cout << prefix + remain << '\n';
        return true;
    };

    vector<int> freq(ALPHABET, 0);

    for (auto &ch : S)
        freq[ch - MIN_CHAR]++;

    if (finish(S, freq))
        return;

    string prefix = S;

    for (int i = N - 1; i >= 0; i--) {
        freq[prefix.back() - MIN_CHAR]--;
        prefix.pop_back();

        for (int c = S[i] - MIN_CHAR + 1; c < ALPHABET; c++) {
            prefix += char(MIN_CHAR + c);
            freq[c]++;

            if (finish(prefix, freq))
                return;

            freq[c]--;
            prefix.pop_back();
        }
    }

    assert(false);
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