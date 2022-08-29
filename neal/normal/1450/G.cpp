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

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


const int INF = int(1e9) + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, A, B;
    string str;
    cin >> N >> A >> B >> str;
    vector<int> S(N);
    vector<int> char_to_index(128, -1);
    string chars;
    int C = 0;

    for (int i = 0; i < N; i++) {
        char ch = str[i];

        if (char_to_index[ch] < 0) {
            char_to_index[ch] = C++;
            chars += ch;
        }

        S[i] = char_to_index[ch];
    }

    cerr << "C = " << C << endl;

    vector<int> char_start(C, INF);
    vector<int> char_end(C, -INF);
    vector<int> occur(C, 0);

    for (int i = 0; i < N; i++) {
        char_start[S[i]] = min(char_start[S[i]], i);
        char_end[S[i]] = max(char_end[S[i]], i + 1);
        occur[S[i]]++;
    }

    auto dense_enough = [&](int mask) {
        int start = INF, end = -INF, count = 0;

        for (int prefix = mask; prefix != 0; prefix &= prefix - 1) {
            int c = __builtin_ctz(prefix);
            start = min(start, char_start[c]);
            end = max(end, char_end[c]);
            count += occur[c];
        }

        return count * B >= (end - start) * A;
    };

    vector<bool> dp(1 << C, false);
    vector<bool> dp_up(1 << C, false);
    dp[0] = dp_up[0] = true;

    for (int mask = 1; mask < 1 << C; mask++) {
        for (int prefix = mask; prefix != 0; prefix &= prefix - 1) {
            int c = __builtin_ctz(prefix);

            if (dp_up[mask & ~(1 << c)]) {
                dp[mask] = true;
                break;
            }
        }

        if (dp[mask] && dense_enough(mask)) {
            dp_up[mask] = true;
        } else {
            for (int prefix = mask; prefix != 0; prefix &= prefix - 1) {
                int lower = mask ^ prefix;

                if (dp_up[lower] && dp_up[prefix]) {
                    dp_up[mask] = true;
                    break;
                }
            }
        }
    }

    string sorted;

    for (int c = 0; c < C; c++)
        if (dp_up[(1 << C) - 1 - (1 << c)])
            sorted += chars[c];

    sort(sorted.begin(), sorted.end());
    cout << sorted.size();

    for (auto &ch : sorted)
        cout << ' ' << ch;

    cout << '\n';
}