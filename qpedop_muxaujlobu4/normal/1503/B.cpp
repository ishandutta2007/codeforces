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
#include<complex>
#include<numeric>
typedef long long ll;
typedef long double ld;
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
const ll INF = 1e9 + 100;
const int mod = 1000000007;
const ld eps = 1e-4, pi = acosl(-1);
const ll maxN = 4010, maxT = 301, A = 179, mid = 150;
ll bp(ll et, ll b) {
    ll res = 1;
    for (int i = 30; i >= 0; --i) {
        res = (res * res) % mod;
        if ((b & (1 << i)) != 0)res = (res * et) % mod;
    }
    return res;
}
void panic() {
    cout << "-1\n";
    exit(0);
}
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>>f, s;
    vector<vector<int>>a(n, vector<int>(n));
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i + j) % 2 == 0) {
                a[i][j] = 1;
                ++c1;
                f.push_back({ i,j });
            }
            else {
                a[i][j] = 2;
                ++c2;
                s.push_back({ i,j });
            }
        }
    }
    for (int t = 0; t < n * n; ++t) {
        int v;
        cin >> v;
        if (c1 == 0) {
            int viv = 2;
            if (v == viv)++viv;
            cout << viv << " " << s.back().first + 1 << " " << s.back().second + 1 << endl;
            s.pop_back();
            continue;
        }
        if (c2 == 0) {
            int viv = 1;
            if (v == 1)viv = 3;
            cout << viv << " " << f.back().first + 1 << " " << f.back().second + 1 << endl;
            f.pop_back();
            continue;
        }
        if (v != 1) {
            --c1;
            cout << "1 " << f.back().first + 1 << " " << f.back().second + 1 << endl;
            f.pop_back();
        }
        else {
            --c2;
            cout << "2 " << s.back().first + 1 << " " << s.back().second + 1 << endl;
            s.pop_back();
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.precision(10);
#ifdef _DEBUG
   // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
    //freopen("dishes.in", "r", stdin); freopen("dishes.out", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/*
solve: 900
my solve: 810
simple solve: 0

solve: 990
my solve: 810
simple solve: 0
*/