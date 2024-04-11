#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
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


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    vector<vector<array<int, 2>>> intervals(M);

    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;

        while (k-- > 0) {
            int start, end;
            cin >> start >> end;
            start--;

            for (int x = start; x < end; x++)
                intervals[x].push_back({start, end});
        }
    }

    vector<vector<int>> dp(M + 1, vector<int>(M + 1, 0));

    for (int start = M - 1; start >= 0; start--)
        for (int end = start + 1; end <= M; end++)
            for (int pick = start; pick < end; pick++) {
                int count = 0;

                for (auto &inter : intervals[pick])
                    count += start <= inter[0] && inter[1] <= end;

                dp[start][end] = max(dp[start][end], dp[start][pick] + dp[pick + 1][end] + count * count);
            }

    cout << dp[0][M] << '\n';
}