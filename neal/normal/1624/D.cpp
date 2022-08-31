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


const int ALPHABET = 26;
const char MIN_CHAR = 'a';

void run_case() {
    int N, K;
    string S;
    cin >> N >> K >> S;
    vector<int> freq(ALPHABET, 0);

    for (auto &ch : S)
        freq[ch - MIN_CHAR]++;

    vector<int> save_freq = freq;
    int best = 0;

    for (int parity = 0; parity <= 1; parity++) {
        freq = save_freq;
        int odd = 0;

        for (int c = 0; c < ALPHABET; c++)
            if (freq[c] % 2 != 0) {
                freq[c]--;
                odd++;
            }

        odd = min(odd, K);

        if (parity == 1) {
            while (odd < K) {
                for (int c = 0; c < ALPHABET; c++)
                    if (freq[c] >= 2) {
                        freq[c] -= 2;
                        odd += 2;
                        break;
                    }
            }
        }

        vector<int> lengths(K, 0);

        for (int i = 0; i < odd; i++)
            lengths[i % K]++;

        priority_queue<int, vector<int>, greater<int>> pq(lengths.begin(), lengths.end());

        for (int c = 0; c < ALPHABET; c++) {
            assert(freq[c] % 2 == 0);

            while (freq[c] > 0) {
                int top = pq.top(); pq.pop();
                top += 2;
                pq.push(top);
                freq[c] -= 2;
            }
        }

        best = max(best, pq.top());
    }

    cout << best << '\n';
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