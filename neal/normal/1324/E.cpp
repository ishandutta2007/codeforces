#include <algorithm>
#include <cassert>
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


const int INF = 1e9 + 5;

int N, H, L, R;
vector<int> A;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> H >> L >> R;
    A.resize(N);

    for (int &a : A)
        cin >> a;

    vector<int> dp(H, -INF);
    dp[0] = 0;

    for (int a : A) {
        vector<int> next_dp(H, -INF);

        for (int x = 0; x < H; x++) {
            int nx = (x + a) % H;
            next_dp[nx] = max(next_dp[nx], dp[x] + (L <= nx && nx <= R));
            nx = (x + a - 1) % H;
            next_dp[nx] = max(next_dp[nx], dp[x] + (L <= nx && nx <= R));
        }

        dp = next_dp;
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';
}