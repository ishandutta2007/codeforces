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
using ld = long double;

const int N = 62, MOD = 998244353;
ll cc[N][N][N], cnt[11][N][N];
int f[8] = {24, 12, 12, 4, 12, 6, 4, 1};

int chr(char c) {
    if ('a' <= c && c <= 'z')
        return c - 'a';
    if ('A' <= c && c <= 'Z')
        return 26 + c - 'A';
    return 52 + c - '0';
}

ll ans = 0;

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
    string s;
    cin >> n;
    set<string> ss;
    rep(i, n) {
        cin >> s;
        ss.insert(s);
        reverse(all(s));
        ss.insert(s);
    }
    for (string i : ss)
        cnt[i.size()][chr(i[0])][chr(i.back())]++;
    int d1, d2, d3;
    for (int i = 3; i <= 10; i++) {
        rep(c1, N)
            rep(c2, N)
                rep(c3, N)
                   cc[c1][c2][c3]  = 0;
        rep(c1, N)
            rep(c2, c1 + 1)
                rep(c3, c2 + 1) {
                    rep(c4, N)
                        cc[c1][c2][c3] += cnt[i][c1][c4] * cnt[i][c2][c4] * cnt[i][c3][c4];
                    cc[c1][c2][c3] %= MOD;
                }
        rep(c1, N)
            rep(c2, c1 + 1) {
                d1 = (c1 == c2 ? 1 : 0);
                rep(c3, c2 + 1) {
                    d2 = d1 * 2  + (c2 == c3 ? 1 : 0);
                    rep(c4, c3 + 1) {
                        d3 = d2 * 2 + (c3 == c4 ? 1 : 0);
                        ans = (ans + cc[c1][c2][c3] * cc[c1][c2][c4] % MOD * cc[c1][c3][c4] % MOD * cc[c2][c3][c4] % MOD * f[d3]) % MOD;
                    }
                }
            }
    }
    cout << ans;
}