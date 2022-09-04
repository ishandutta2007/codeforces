#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")

#include <bits/stdc++.h>

using namespace std;

#ifdef NeverBeRed
#include "debug.h"
#else
#define debug(...) 9715
#endif
typedef long long ll;
typedef long double ld;
typedef complex<ld> point;
#define F first
#define S second

template<typename T, typename U>
T pow_mod(T a, U b, int mod)
{
    T r = 1;
    for (; b > 0; b >>= 1)
    {
        if (b & 1) r = (ll)r * a % mod;
        a = (ll)a * a % mod;
    }
    return r;
}

const int mod = 31607;

using OK = unsigned short;

template<bool inv = false>
void transform(OK a[], int n)
{
    for (int len = 1; len < n; len <<= 1)
    {
        for (int i = 0; i < n; i += len << 1)
            for (int j = i; j < i + len; ++j)
            {
                OK v = a[j + len];
                if (inv) {
                    if (a[j] >= v)
                        a[j] -= v;
                    else
                        a[j] -= v - mod;
                } else {
                    if (a[j] + v >= mod)
                        a[j] = a[j] + v - mod;
                    else
                        a[j] = a[j] + v;
                }
            }
//        if (len * 2 >= n || len == (1 << 12))
//            for (int i = 0; i < n; ++i)
//                a[i] %= mod;
    }
}

#define trans(x) transform((x).data(), sz)
#define itrans(x) transform<true>((x).data(), sz)

void mul(vector<OK> &x, vector<OK> &y)
{
    const int sz = x.size();
    for (int i = 0; i < sz; ++i)
        x[i] = x[i] * (int)y[i] % mod;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int inv = pow_mod(10000, mod - 2, mod);

    int n;
    cin >> n;
    const int sz = 1 << n;
    vector<vector<int>> a(n, vector<int>(n));
    for (auto &i : a)
        for (auto &j : i)
            cin >> j, j = j * inv % mod;


    vector<OK> x, x1, x2, x12;
    for (int j = 0; j < n; ++j)
    {
        vector<int> ii(n);
        for (int i = 0; i < n; ++i)
            ii[i] = pow_mod((1 - a[i][j] + mod) % mod, mod - 2, mod) * a[i][j] % mod;

        vector<OK> y(sz), y1, y2, y12;
        y[0] = 1;
        for (int i = 0; i < n; ++i)
            y[0] = y[0] * (1 - a[i][j] + mod) % mod;
        for (int i = 1; i < sz; ++i)
        {
            int l = __lg(i & -i);
            y[i] = y[i ^ 1 << l] * ii[l] % mod;
        }
        y[sz - 1] = 0;
        y1 = y2 = y12 = y;
        for (int i = 0; i < sz; ++i)
        {
            if (~i >> j & 1)
                y1[i] = 0, y12[i] = 0;
            if (~i >> (n-j-1) & 1)
                y2[i] = 0, y12[i] = 0;
        }
        trans(y), trans(y1), trans(y2), trans(y12);
        if (j == 0) x.swap(y), x1.swap(y1), x2.swap(y2), x12.swap(y12);
        else mul(x, y), mul(x1, y1), mul(x2, y2), mul(x12, y12);
    }
    itrans(x), itrans(x1), itrans(x2), itrans(x12);
    int ans = ((int)x[0] - x1[0] - x2[0] + x12[0]) % mod;
    cout << (1 - ans + mod) % mod << "\n";

    return 0;
}