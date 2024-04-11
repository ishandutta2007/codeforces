#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include<random>
#define double long double
//#define int short
using namespace std;
long long gcd(long long i, long long j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
template<typename T> inline T getint() {
    T val = 0;
    char c;

    bool neg = false;
    while ((c = getchar()) && !(c >= '0' && c <= '9')) {
        neg |= c == '-';
    }

    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));

    return val * (neg ? -1 : 1);
}
const long long INF = 2e17;
const long long mod = 1000000009, mod1 = 1000000007;
const int Y = 200101;
vector<long long>t, h, inn, outt;
vector<char>used;
vector < vector<long long>>dp;
vector<vector<int>>G;
bool cmp(int a, int b) {
    return dp[0][a] - dp[1][a] > dp[0][b] - dp[1][b];
}
void dfs(int v, int p) {
    used[v] = 1;
    for (auto x : G[v]) {
        if (x == p)continue;
        dfs(x, v);
    }
    sort(G[v].begin(), G[v].end(), cmp);
    long long s = 0;
    vector<long long>p1 = { 0 }, p2 = { 0 };
    int ct = 0;
    for (auto x : G[v]) {
        if (x == p)continue;
        ++ct;
        p1.push_back(p1.back() + dp[0][x]);
    }
    reverse(G[v].begin(), G[v].end());
    for (auto x : G[v]) {
        if (x == p)continue;
        p2.push_back(p2.back() + dp[1][x]);
    }
    if (p == -1) {
        for (int i = 0; i <= ct; ++i) {
            dp[0][v] = max(dp[0][v], p1[i] + p2[ct - i] + min(inn[v] + ct - i, outt[v] + i) * t[v]);
        }
    }
    else {
        for (int i = 0; i <= ct; ++i) {
            dp[1][v] = max(dp[1][v], p1[i] + p2[ct - i] + min(inn[v] + ct - i, outt[v] + i + 1) * t[v]);
            dp[0][v] = max(dp[0][v], p1[i] + p2[ct - i] + min(inn[v] + ct - i + 1, outt[v] + i) * t[v]);
        }
    }
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    int n;
    cin >> n;
    t.assign(n, 0);
    h.assign(n, 0);
    inn.assign(n, 0);
    outt.assign(n, 0);
    G.assign(n, {});
    for (auto& x : t)cin >> x;
    for (auto& x : h)cin >> x;
    long long s = 0;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        if (h[a] == h[b]) {
            G[a].push_back(b);
            G[b].push_back(a);
        }
        if (h[a] > h[b]) {
            ++outt[b];
            ++inn[a];
        }
        if (h[a] < h[b]) {
            ++outt[a];
            ++inn[b];
        }
        s += t[a] + t[b];
    }
    used.assign(n, 0);
    dp.assign(2, vector<long long>(n, -INF));
    for (int i = 0; i < n; ++i) {
        if (used[i] == 0) {
            dfs(i, -1);
            s -= dp[0][i];
        }
    }
    cout << s << endl;
    return 0;
}