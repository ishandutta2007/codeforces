#pragma comment(linker, "/STACK:2759095000")
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
//#define int long long
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
const double INF = 1e17;
const int mod = 998244353;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 300100, maxT = 2001;
void file_inc() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
long long bin_pow(long long et, long long b) {
    if (b == 0)return 1;
    long long tmp = bin_pow(et, b / 2);
    tmp = (tmp * tmp) % mod;
    if (b % 2 == 1)tmp = (tmp * et) % mod;
    return tmp;
}
long long f[maxN];
long long g[maxN];
long long C(int n, int k) {
    return f[n] * g[k] % mod * g[n - k] % mod;
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
   // file_inc();
    int n, k;
    cin >> n >> k;
    f[0] = g[0] = 1;
    vector<int>vls;
    vector<pair<int, int>>seg(n);
    for (int i = 1; i <= n; ++i) {
        f[i] = (f[i - 1] * i) % mod;
        g[i] = bin_pow(f[i], mod - 2);
    }
    for (auto& x : seg) {
        cin >> x.first >> x.second;
        vls.push_back(x.first);
        vls.push_back(x.second);
    }
    sort(vls.begin(), vls.end());
    vls.resize(unique(vls.begin(), vls.end()) - vls.begin());
    vector <int>add(2 * n + 10);
    vector<int>del(2 * n + 10);
    for (auto x : seg) {
        x.first = lower_bound(vls.begin(), vls.end(), x.first) - vls.begin();
        x.second = lower_bound(vls.begin(), vls.end(), x.second) - vls.begin();
        ++add[x.first];
        ++del[x.second];
    }
    int count = 0;
    long long ans = 0;
    for (int i = 0; i < 2 * n + 10; ++i) {
        for (int j = 0; j < add[i]; ++j) {
            ++count;
            if (count >= k) {
                ans += C(count - 1, k - 1);
                ans %= mod;
            }
        }
        for (int j = 0; j < del[i]; ++j) {
            --count;
        }
    }
    cout << ans;
    return 0;
}