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
const int maxN = 200100, maxT = 2001;
int tree[maxN << 2];
int sz;
int get(int ql, int qr, int v = 1, int tl = 0, int tr = sz - 1) {
    if (ql <= tl && tr <= qr)return tree[v];
    int mx = INF, m = (tr + tl) / 2;
    if (ql <= m)mx = min(mx, get(ql, qr, 2 * v, tl, m));
    if (qr > m)mx = min(mx, get(ql, qr, 2 * v + 1, m + 1, tr));
    return mx;
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
        vector<int>a(n);
        sz = 1;
        while (sz < n)sz <<= 1;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            tree[sz + i] = a[i];
        }
        for (int i = sz - 1; i > 0; --i)tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
        int x = -1, y = -1, z = -1;
        vector<int>p_max = a, s_max = a;
        for (int i = 1; i < n; ++i)p_max[i] = max(p_max[i], p_max[i - 1]);
        for (int i = n - 2; i >= 0; --i)s_max[i] = max(s_max[i], s_max[i + 1]);
        for (int l = 1; l < n - 1; ++l) {
            int r = l - 1, r1 = n - 2;
            while (r + 1 != r1) {
                int m = (r + r1) / 2;
                if (p_max[l - 1] < s_max[m + 1] || p_max[l - 1] < get(l, m)) {
                    r = m;
                }
                else r1 = m;
            }
            r = r1;
            if (p_max[l - 1] == s_max[r + 1] && p_max[l - 1] == get(l, r)) {
                x = l;
                y = r - l + 1;
                z = n - x - y;
            }
        }

        if (x == -1) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
            cout << x << " " << y << " " << z << "\n";
        }
    }
    return 0;
}