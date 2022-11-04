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
vector<vector<pair<int, int>>>G;
vector<long long>li;
long long m, k;
long long wnt, wnt1 = 1;
vector<long long>vl;
pair<long long, long long>dp[10][10];
pair<long long, long long>dp1[10][10];
long long ans = 0;
void Mrec(int deep, long long sm, long long pr, long long s1, long long p1) {
    if (deep == k + 1) {
        if (sm == m && pr == wnt && s1 == m && p1 == wnt1)++ans;
        return;
    }
    for (int i = 1; i <= deep; ++i) {
        long long ts = sm + dp[deep][i].first;
        long long tp = (pr * dp[deep][i].second) % mod;
        Mrec(deep + 1, ts, tp, s1 + dp1[deep][i].first, (p1 * dp1[deep][i].second) % mod1);
    }
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    int n;
    cin >> n >> m >> k;
    wnt = 1;
    vl.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        vl[i] = rand() + 1;
    }
    for (int i = 0; i < n; ++i) {
        wnt = (wnt * vl[i]) % mod;
        wnt1 = (wnt1 * vl[i]) % mod1;
    }
    G.assign(n, {});
    li.assign(n, 0);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        G[--a].push_back({ c,--b });
        ++li[b];
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j)dp1[i][j] = dp[i][j] = { 0,1 };
    }
    for (int t = 0; t < n; ++t) {
        vector<pair<int, int>>x = G[t];
        sort(x.begin(), x.end());
        for (int i = 0; i < x.size(); ++i) {
            dp[x.size()][i + 1].first += li[x[i].second];
            dp[x.size()][i + 1].second = (dp[x.size()][i + 1].second * vl[x[i].second]) % mod;
            dp1[x.size()][i + 1].first += x.size();
            dp1[x.size()][i + 1].second = (dp1[x.size()][i + 1].second * vl[x[i].second]) % mod1;
        }
    }
    Mrec(1, 0, 1, 0 ,1);
    cout << ans;
    return 0;
}