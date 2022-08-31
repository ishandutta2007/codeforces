#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstring>
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

const int A_MAX = 50000;
const int B_MAX = 50;


int A, B, N;
int dp[A_MAX][B_MAX];

int solve(int a, int b) {
    if (pow((long double) a, (long double) b) > N - 0.5)
        return 2;

    if (b >= B_MAX)
        return 1;

    if (a >= A_MAX)
        return (A - a) % 2 * 2;

    int &ans = dp[a][b];

    if (ans >= 0)
        return ans;

    int x = solve(a + 1, b);
    int y = solve(a, b + 1);

    if (x == 0 || y == 0)
        return ans = 2;
    else if (x == 1 || y == 1)
        return ans = 1;
    else
        return ans = 0;
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> A >> B >> N;

    // if (A == 1) {
    //     cout << "Missing" << '\n';
    //     return 0;
    // }

    memset(dp, -1, sizeof(dp));
    int ans = solve(A, B);

    if (ans == 2)
        cout << "Masha" << '\n';
    else if (ans == 1)
        cout << "Missing" << '\n';
    else
        cout << "Stas" << '\n';

    // cout << (solve(A, B) ? "Masha" : "Stas") << '\n';
}