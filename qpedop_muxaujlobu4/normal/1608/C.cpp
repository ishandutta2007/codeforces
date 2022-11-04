//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
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
#include<unordered_map>
#include<random>
#include<ctime>
//#include<complex>
#include<numeric>
typedef long long ll;
typedef long double ld;
typedef unsigned short us;
typedef unsigned long long ull;
//typedef complex<double> base;
using namespace std;
ll gcd(ll i, ll j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
#ifdef _DEBUG
int __builtin_popcount(int x) { return x ? (__builtin_popcount(x >> 1) + (x & 1)) : 0; }
#endif
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
//#define int long long
const ll INF = 1000000000;
const int mod = 1000000007;
const ld eps = 1e-11, pi = acos(-1);
const ll maxN = 30010, maxT = 310, A = 179, K = 450;
mt19937 mt_rand(time(0));
ll bp(ll et, ll b) {
    b %= mod - 1;
    et %= mod;
    ll res = 1;
    for (int i = 30; i >= 0; --i) {
        res = (res * res) % mod;
        if ((b & (1 << i)) != 0)res = (res * et) % mod;
    }
    return res;
}
void panic() {
    cout << "impossible\n";
    exit(0);
}
vector<vector<int>>g, g1;
vector<int>used, pth;
void dfs(int v) {
    used[v] = 1;
    for (auto x : g[v]) {
        if (!used[x])dfs(x);
    }
    pth.push_back(v);
}
void dfs1(int v) {
    used[v] = 1;
    for (auto x : g1[v]) {
        if (!used[x])dfs1(x);
    }
}
void solve() {
    int n;
    cin >> n;
    map<int, int>mp1, mp2;
    g.assign(n, vector<int>());
    g1.assign(n, vector<int>());
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        mp1[v] = i;
    }
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        mp2[v] = i;
    }
    for (auto x : mp1) {
        auto it = mp1.upper_bound(x.first);
        if (it == mp1.end())continue;
        g[(*it).second].push_back(x.second);
        g1[x.second].push_back((*it).second);
    }
    for (auto x : mp2) {
        auto it = mp2.upper_bound(x.first);
        if (it == mp2.end())continue;
        g[(*it).second].push_back(x.second);
        g1[x.second].push_back((*it).second);
    }
    used.assign(n, 0);
    pth.clear();
    for (int i = 0; i < n; ++i) {
        if (!used[i])dfs(i);
    }
    used.assign(n, 0);
    dfs1(pth.back());
    for (auto x : used)cout << x;
    cout << "\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.precision(20);
    srand(time(0));
#ifdef _DEBUG
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
    //freopen("hear.in", "r", stdin); freopen("hear.out", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}