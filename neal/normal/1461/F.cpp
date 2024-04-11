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


const double CUTOFF = 2e6;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    cin >> N;
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    string S;
    cin >> S;
    sort(S.begin(), S.end());

    if (S == "+-")
        S = "+";

    if (S.size() == 1) {
        for (int i = 0; i < N; i++)
            cout << A[i] << (i < N - 1 ? S[0] : '\n');

        return 0;
    }

    if (S.size() == 3)
        S = "*+";

    if (S == "*-") {
        cout << A[0];

        for (int i = 1; i < N; i++)
            cout << (A[i] == 0 ? '-' : '*') << A[i];

        cout << '\n';
        return 0;
    }

    assert(S == "*+");

    // 3 1 1 1 1 1 1 1 3
    // 1 1 1 3 4 1 1 1 1 1 2 2 1 1 1 1 7 8 1
    // 1+1+1+12 1 1 1 1 1 4 1 1 1 1 56+1
    // 12 1 1 1 1 1 4 1 1 1 1 56
    // 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 3 1 3
    // 2+1+1+1+1+1+...              +1+3*1*3
    // 2 1 1 2 1 1 2

    string answer(N + 1, '?');
    vector<int64_t> dp(N + 1, 0);
    vector<int> dp_prev(N + 1, -1);

    auto solve = [&](int start, int end) -> void {
        while (start < end && A[start] == 1) {
            answer[start + 1] = '+';
            start++;
        }

        while (start < end && A[end - 1] == 1) {
            answer[end - 1] = '+';
            end--;
        }

        if (start >= end)
            return;

        double greater_product = 1;

        for (int i = start; i < end; i++) {
            greater_product *= A[i];

            if (greater_product > CUTOFF)
                break;
        }

        if (greater_product > CUTOFF) {
            for (int i = start + 1; i < end; i++)
                answer[i] = '*';

            return;
        }

        for (int i = start; i <= end; i++) {
            dp[i] = 0;
            dp_prev[i] = -1;
        }

        for (int i = start; i < end; i++) {
            if (A[i] == 1) {
                dp[i + 1] = dp[i] + 1;
                dp_prev[i + 1] = i;
                continue;
            }

            int64_t product = 1;

            for (int j = i; j >= start; j--) {
                product *= A[j];

                if (product + dp[j] > dp[i + 1]) {
                    dp[i + 1] = product + dp[j];
                    dp_prev[i + 1] = j;
                }
            }
        }

        for (int current = end; current > start; current = dp_prev[current]) {
            for (int i = current - 1; i > dp_prev[current]; i--)
                answer[i] = '*';

            answer[dp_prev[current]] = '+';
        }
    };

    for (int i = 0, j = 0; i < N; i = j) {
        while (j < N && (A[i] > 0) == (A[j] > 0))
            j++;

        if (A[i] > 0)
            solve(i, j);
    }

    for (int i = 0; i < N; i++)
        if (A[i] == 0)
            answer[i] = answer[i + 1] = '+';

    for (int i = 0; i < N; i++)
        cout << A[i] << (i < N - 1 ? answer[i + 1] : '\n');
}