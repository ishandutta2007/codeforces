#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <complex>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <cassert>
#include <random>

#define sz(a) (int)((a).size())
#ifdef ONPC
    #define deb(a) cerr << "       " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif

using namespace std;

mt19937 rnd(time(0));

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll gcd(ll a, ll b)
{
    while (a)
    {
        b %= a;
        swap(a, b);
    }
    return b;
}

const ull INF = 1000000000000000000;
const ull T = 100000000;

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    vector<ll> x, y, xx, yy;
    xx.resize(n);
    yy.resize(n);
    y.resize(n);
    x.resize(n);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        x[i] = a;
        y[i] = b;
        xx[i] = c;
        yy[i] = d;
        //cin >> x[i] >> y[i] >> xx[i] >> yy[i];
        ans += gcd(abs(x[i] - xx[i]), abs(y[i] - yy[i])) + 1;
    }
    map<pair<ll, ll>, ll> qq;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {

            ll a = y[i] - yy[i], b = xx[i] - x[i], c = -a * x[i] - b * y[i];
            ll A = y[j] - yy[j], B = xx[j] - x[j], C = -A * x[j] - B * y[j];
            ll t1 = C * a;
            ll t2 = c * A;
            ull t;
            bool ok = 0;
            if (t2 > t1)
                ok = 1, swap(t1, t2);
            if (t1 > 0 && t2 < 0)
                t2 = -t2, t = (ull)t1 + (ull)(t2);
            else
            {
                ll qq = t1 - t2;
                t = qq;
            }
            ll q = A * b - a * B;
            ll fau = abs(q);
            ull fau2 = fau;
            if (!q || t % fau2 != 0)
                continue;
            if (q < 0)
                ok ^= 1, q = -q;
            ull yyyy = t / (ull)q;
            if (yyyy > T)
                continue;
            ll yyy = yyyy;
            if (ok)
                yyy = -yyy;
            //yyy = (C * a - c * A) / (A * b - a * B);
            if (!a)
            {
                swap(a, A);
                swap(b, B);
                swap(c, C);
            }
            ll tt = -c - b * yyy;
            if (tt % abs(a))
                continue;
            ll xxx = tt / a;
            if (max(min(x[i], xx[i]), min(x[j], xx[j])) <= xxx && min(max(x[i], xx[i]), max(x[j], xx[j])) >= xxx && max(min(y[i], yy[i]), min(y[j], yy[j])) <= yyy && min(max(y[i], yy[i]), max(y[j], yy[j])) >= yyy)
                qq[{xxx, yyy}]++;
        }
    for (auto it : qq)
    {
        ll t = it.second;
        ll l = 0, r = n + 5;
        while (r - l > 1)
        {
            ll mid = (r + l) / 2;
            if (mid * (mid - 1) / 2LL > t)
                r = mid;
            else
                l = mid;
        }
        ans -= (long long)(l - 1);
    }
    cout << ans << endl;
    return 0;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int T = 100;
    //cin >> T;
    for (int i = 1; i <= T; i++)
    {
        #ifdef ONPC
            cout << "Test #" << i << ":\n";
        #endif
        if (solve())
            break;
        #ifdef ONPC
            cout << "__________________________\n";
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
    #endif
    return 0;
}