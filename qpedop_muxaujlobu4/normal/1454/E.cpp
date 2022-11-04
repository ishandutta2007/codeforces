#pragma comment(linker, "/STACK:9759095000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include <unordered_map>
#include<random>
#include<ctime>
#define double long double
typedef long long ll;
typedef unsigned long long ull;
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
const long long INF = 1e9;
const int mod = 998244353;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 100100, maxT = 2001;
vector<vector<int>>G;
vector<int>used;
int cir_ver;
vector<int>c;
void dfs(int v, int p) {
    used[v] = 1;
    for (auto x : G[v]) {
        if (x == p)continue;
        if (used[x]) {
            cir_ver = x;
            c.push_back(v);
            return;
        }
        else {
            dfs(x, v);
            if (cir_ver != -1) {
                c.push_back(v);
                if (v == cir_ver)cir_ver = -1;
            }
            if (!c.empty())return;
        }
    }
}
void dfs2(int v, int& ct) {
    ++ct;
    used[v] = 1;
    for (auto x : G[v]) {
        if (!used[x])dfs2(x, ct);
    }
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
#ifdef _MY
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        G.assign(n, vector<int>());
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            --a; --b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        used.assign(n, 0);
        cir_ver = -1;
        c.assign(0, 0);
        dfs(0, -1);
        used.assign(n, 0);
        for (auto x : c)used[x] = 1;
        ll count = 0, ans = 0;
        for (auto x : c) {
            int ct = 0;
            dfs2(x, ct);
            ans += count * ct * 2;
            count += ct;
            ans += (ll)ct * (ct - 1) / 2;
        }
        cout << ans << "\n";
    }
    return 0;
}