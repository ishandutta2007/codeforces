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
const long long m = 1000000007;
const int Y = 501;
vector < vector<pair<int, int>>>G;
vector<long long>dp;
vector<int>cc;
vector<pair<long long, long long>>reb;
int n;
void dfs(int v, int p) {
    dp[v] = 0;
    bool list = true;
    for (auto x : G[v]) {
        if (x.first == p)continue;
        list = false;
    }
    if (list) {
        dp[v] = 1;
        return;
    }
    for (auto x : G[v]) {
        if (x.first == p)continue;
        dfs(x.first, v);
        dp[v] += dp[x.first];
        reb[x.second].first = dp[x.first];
    }
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    int t;
    cin >> t;
    while (t--) {
        long long s;
        cin >> n >> s;
        dp.assign(n, 0);
        G.assign(n, {});
        reb.assign(n - 1, { 0,0 });
        cc.resize(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            int a, b, c;
            cin >> a >> b >> c >> cc[i];
            G[--a].push_back({ --b, i });
            G[b].push_back({ a, i });
            reb[i].second = c;
        }
        dfs(0, -1);
        long long s1 = 0, res = INF;
        priority_queue<pair<long long, int>>q1, q2;
        int tmp = 0;
        for (auto x : reb) {
            s1 += x.first * x.second;
            if (cc[tmp] == 1) q1.push({ (x.second - x.second / 2) * x.first,tmp++ });
            else q2.push({ (x.second - x.second / 2) * x.first,tmp++ });
        }
        vector<long long>slv1 = { 0 }, slv2 = { 0 };
        while (!q1.empty()) {
            long long cst, v;
            tie(cst, v) = q1.top();
            q1.pop();
            slv1.push_back(slv1.back() + cst);
            reb[v].second /= 2;
            if (reb[v].second) {
                q1.push({ (reb[v].second - reb[v].second / 2) * reb[v].first,v });
            }
        }
        while (!q2.empty()) {
            long long cst, v;
            tie(cst, v) = q2.top();
            q2.pop();
            slv2.push_back(slv2.back() + cst);
            reb[v].second /= 2;
            if (reb[v].second) {
                q2.push({ (reb[v].second - reb[v].second / 2) * reb[v].first,v });
            }
        }
        for (int i = 0; i < slv1.size(); ++i) {
            long long tt = s1 - s - slv1[i];
            int id = lower_bound(slv2.begin(), slv2.end(), tt) - slv2.begin();
            if (id == slv2.size())continue;
            res = min(res, (long long)i + 2 * id);
        }
        cout << res << "\n";
    }
    return 0;
}