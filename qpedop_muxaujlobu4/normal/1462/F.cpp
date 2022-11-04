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
#include<unordered_map>
#include<random>
#include<ctime>
//#define double long double
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;
long long gcd(long long i, long long j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
#ifdef _DEBUG
ll __builtin_popcount(ll x) { return x ? (__builtin_popcount(x >> 1) + (x & 1)) : 0; }
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
const long long INF = 1e9;
const int mod = 1000000007;
const double eps = 1e-12, pi = acos(-1);
const int maxN = 200100, maxT = 100010;
int sz;
vector<int>tree;
int get(int ql, int qr, int tl = 0, int tr = sz - 1, int v = 1) {
    if (ql <= tl && tr <= qr)return tree[v];
    int res = 0, m = (tr + tl) / 2;
    if (ql <= m)res += get(ql, qr, tl, m, 2 * v);
    if (qr > m)res += get(ql, qr, m + 1, tr, 2 * v + 1);
    return res;
}
void sett(int i, int v) {
    i |= sz;
    tree[i] = v;
    i >>= 1;
    while (i) {
        tree[i] = tree[2 * i] + tree[2 * i + 1];
        i >>= 1;
    }
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(11);
#ifdef _MY
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>vals;
        vector<pair<int, int>>seg(n);
        for (auto& x : seg) {
            cin >> x.first >> x.second;
            vals.push_back(x.first);
            vals.push_back(x.second);
        }
        sort(vals.begin(), vals.end());
        vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
        vector<int>add(vals.size()), del(vals.size());
        vector<vector<int>>qw(vals.size());
        for (auto& x : seg) {
            x.first = lower_bound(vals.begin(), vals.end(), x.first) - vals.begin();
            x.second = lower_bound(vals.begin(), vals.end(), x.second) - vals.begin();
            ++add[x.first];
            ++del[x.second];
            qw[x.second].push_back(x.first);
        }
        sz = 1;
        while (sz < vals.size())sz <<= 1;
        tree.assign(2 * sz, 0);
        int ans = INF;
        int open = 0;
        for (int i = 0; i < vals.size(); ++i) {
            open += add[i];
            open -= del[i];
            sett(i, del[i]);
            for (auto x : qw[i]) {
                ans = min(ans, n - open - get(x, i));
            }
        }
        cout << ans << "\n";
    }
    return 0;
}