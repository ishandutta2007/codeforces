#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


const int MAX = 2050;

int N, M;
vector<int> aggressive, recruit;
vector<int> profit;

int dp[MAX][MAX];
vector<int> max_count;

int compute_extra(int agg, int count, int limit = MAX) {
    int extra = 0;

    while (count > 1 && agg < limit) {
        count /= 2;
        agg++;
        extra += count * profit[agg];
    }

    return extra;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    aggressive.resize(N);
    recruit.resize(N);
    profit.assign(N + M + 1, 0);

    for (int &a : aggressive)
        cin >> a;

    for (int &r : recruit)
        cin >> r;

    for (int i = 1; i <= N + M; i++)
        cin >> profit[i];

    max_count.assign(N + M + 1, -1);
    memset(dp, -63, sizeof(dp));
    dp[0][0] = max_count[0] = 0;

    for (int i = N - 1; i >= 0; i--) {
        int agg = aggressive[i];

        for (int a = agg; a >= 0; a--)
            for (int c = max_count[a]; c >= 0; c--) {
                int extra = compute_extra(a, c, agg);
                int c_to_agg = c >> min(agg - a, 30);
                dp[agg][c_to_agg + 1] = max(dp[agg][c_to_agg + 1], dp[a][c] + extra + profit[agg] - recruit[i]);
                max_count[agg] = max(max_count[agg], c_to_agg + 1);
            }
    }

    int best = 0;

    for (int a = 0; a <= N + M; a++)
        for (int c = 0; c <= max_count[a]; c++)
            best = max(best, dp[a][c] + compute_extra(a, c));

    cout << best << '\n';
}