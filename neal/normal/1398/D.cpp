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


const int N_MAX = 205;

int dp[N_MAX][N_MAX][N_MAX];
vector<int> sticks[3];

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    array<int, 3> N;
    cin >> N[0] >> N[1] >> N[2];

    for (int c = 0; c < 3; c++) {
        sticks[c].resize(N[c]);

        for (auto &s : sticks[c])
            cin >> s;

        sort(sticks[c].begin(), sticks[c].end());
    }

    for (int a = 0; a <= N[0]; a++)
        for (int b = 0; b <= N[1]; b++)
            for (int c = 0; c <= N[2]; c++) {
                array<int, 3> n = {a, b, c};

                for (int i = 0; i < 3; i++)
                    for (int j = i + 1; j < 3; j++)
                        if (n[i] > 0 && n[j] > 0) {
                            array<int, 3> p = n;
                            p[i]--; p[j]--;
                            dp[n[0]][n[1]][n[2]] = max(dp[n[0]][n[1]][n[2]], sticks[i][p[i]] * sticks[j][p[j]] + dp[p[0]][p[1]][p[2]]);
                        }
            }

    cout << dp[N[0]][N[1]][N[2]] << '\n';
}