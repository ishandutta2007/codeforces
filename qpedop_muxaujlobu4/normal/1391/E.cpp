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
const int Y = 1000101;
vector<int>used;
vector<int>p;
vector<vector<int>>Gr;
vector<vector<int>>dp;
int mx;
void dfs(int v, int deep) {
    used[v] = 1;
    mx = max(mx, deep);
    dp[deep].push_back(v);
    for (auto x : Gr[v]) {
        if (used[x] == 1)continue;
        p[x] = v;
        dfs(x, deep + 1);
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
        int n, m;
        cin >> n >> m;
        used.assign(n, 0);
        p.assign(n, -1);
        Gr.assign(n, {});
        dp.assign(n, {});
        mx = 0;
        for (int j = 0; j < m; ++j) {
            int a, b;
            cin >> a >> b;
            --a;
            --b;
            Gr[a].push_back(b);
            Gr[b].push_back(a);
        }
        for (int i = 0; i < n; ++i) {
            if (used[i] == 0) {
                dfs(i, 0);
            }
        }
        if (mx >= n / 2) {
            cout << "PATH\n";
            int v = dp[n / 2][0];
            vector<int>cr = { v };
            while (p[v] != -1) {
                v = p[v];
                cr.push_back(v);
            }
            cout << cr.size() << "\n";
            for (auto x : cr)cout << x + 1 << " ";
            cout << "\n";
        }
        else {
            cout << "PAIRING\n";
            vector<pair<int, int>>vd;
            for (int i = 0; i < n; ++i) {
                while (dp[i].size() >= 2) {
                    int tmp1 = dp[i].back();
                    dp[i].pop_back();
                    int tmp2 = dp[i].back();
                    dp[i].pop_back();
                    vd.push_back({ tmp1,tmp2 });
                }
            }
            cout << vd.size() << "\n";
            for (auto x : vd)cout << x.first + 1 << " " << x.second + 1 << "\n";
        }
    }
    return 0;
}