#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


const int INF = 1e9 + 5;

void run_case() {
    int N;
    cin >> N;
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    map<int, vector<int>> occur;

    for (int i = 0; i < N; i++)
        occur[A[i]].push_back(i);

    vector<int> sorted = A;
    sort(sorted.begin(), sorted.end());
    vector<int> finish_dp(N + 1, -INF);

    auto &&get_above = [&](int a) {
        auto it = upper_bound(sorted.begin(), sorted.end(), a);

        if (it == sorted.end())
            return INF;

        return *it;
    };

    for (int i = N - 1; i >= 0; i--) {
        int a = A[i];
        int above = get_above(a);

        if (occur[a].front() == i) {
            finish_dp[i] = int(occur[a].size());

            if (above < INF) {
                auto &indices = occur[above];
                auto it = upper_bound(indices.begin(), indices.end(), occur[a].back());

                if (it != indices.end())
                    finish_dp[i] += finish_dp[*it];
            }
        } else {
            finish_dp[i] = int(occur[a].end() - lower_bound(occur[a].begin(), occur[a].end(), i));
        }
    }

    dbg(finish_dp);
    int best = 0;

    for (auto &pr : occur) {
        int a = pr.first;
        auto &indices = pr.second;
        int n = int(indices.size());
        best = max(best, n);
        int above = get_above(a);

        if (above >= INF)
            continue;

        for (int i = 0; i < n; i++) {
            int index = indices[i];
            auto it = upper_bound(occur[above].begin(), occur[above].end(), index);

            if (it != occur[above].end())
                best = max(best, i + 1 + finish_dp[*it]);
        }
    }

    cout << N - best << '\n';
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