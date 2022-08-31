#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
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


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M, K;
    cin >> N >> M >> K;
    vector<array<int, 2>> people(M);

    for (auto &p : people) {
        cin >> p[0] >> p[1];
        p[0]--;
    }

    sort(people.begin(), people.end(), [](const array<int, 2> &a, const array<int, 2> &b) {
        return a[0] + a[1] < b[0] + b[1];
    });

    auto compute_optimal = [&](int start, int end) {
        vector<int> change(N + 1, 0);

        for (int i = start; i < end; i++) {
            change[people[i][0]]++;
            change[people[i][1]]--;
        }

        vector<int> values = change;

        for (int i = 0; i < N; i++)
            values[i + 1] += values[i];

        vector<int> prefix_sum(N + 1, 0);

        for (int i = 0; i < N; i++)
            prefix_sum[i + 1] = prefix_sum[i] + values[i];

        int most = 0;

        for (int L = 0; L + K <= N; L++)
            most = max(most, prefix_sum[L + K] - prefix_sum[L]);

        return most;
    };

    int best = 0;

    for (int left = 0; left <= M; left++)
        best = max(best, compute_optimal(0, left) + compute_optimal(left, M));

    cout << best << '\n';
}