#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 20, P = 1 << N;
int c[N][N], ms[N][P], cc[N];
int dp[P];

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
    string s;
    cin >> n >> m >> s;
    s.resize(unique(all(s)) - s.begin());
    n = s.size();
    rep(i, n - 1) {
        cc[s[i] - 'a']++;
        cc[s[i + 1] - 'a']++;
        c[s[i] - 'a'][s[i + 1] - 'a']++;
        c[s[i + 1] - 'a'][s[i] - 'a']++;
    }
    int pw = 1 << m;
    for (int i = 1; i < pw; i++) {
        int r = 0;
        while (!(i & (1 << r)))
            r++;
        rep(j, m)
            ms[j][i] = ms[j][i ^ (1 << r)] + c[j][r];
    }
    for (int i = 1; i < pw; i++) {
        dp[i] = 1e9;
        int pc = __builtin_popcount(i) - 1;
        rep(j, m) {
            if (i & (1 << j))
                dp[i] = min(dp[i], dp[i ^ (1 << j)] + (ms[j][i] * 2 - cc[j]) * pc);
        }
    }
    cout << dp[pw - 1];
}