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


const int N_MAX = 1e5 + 5;
const int Z_MAX = 5;

int N;
vector<int> A;
int dp[N_MAX][Z_MAX + 1][2];

int solve(int index, int k, int z, bool left) {
    if (k == 0)
        return 0;

    int &ans = dp[k][z][left];

    if (ans >= 0)
        return ans;

    assert(index < N - 1);
    ans = A[index + 1] + solve(index + 1, k - 1, z, false);

    if (index > 0 && z > 0 && !left)
        ans = max(ans, A[index - 1] + solve(index - 1, k - 1, z - 1, true));

    return ans;
}

void run_case() {
    int K, Z;
    cin >> N >> K >> Z;
    A.resize(N);

    for (auto &a : A)
        cin >> a;

    for (int i = 0; i <= N; i++)
        for (int z = 0; z <= Z_MAX; z++)
            for (int left = 0; left < 2; left++)
                dp[i][z][left] = -1;

    cout << A[0] + solve(0, K, Z, false) << '\n';
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