#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <memory.h>
#include <map>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <deque>

#define deb(a) cerr << #a << " = " << (a) << "\n"
#define deb2(a, b) deb(a); deb(b)
#define deb3(a, b, c) deb(a); deb(b); deb(c)
#define deb4(a, b, c, d) deb(a); deb(b); deb(c); deb(d)

using namespace std;

const int MOD = 1000000;

typedef long long ll;
typedef long double ld;

set<pair<ll, ll> > q;

ll prod(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.first * b.second - a.second * b.first;
}

bool check(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c)
{
    return (prod({b.first - a.first, b.second - a.second}, {c.first - a.first, c.second - a.second}) > 0);
}

const ld eps = 1e-12;

void addPoint(ll x, ll y)
{
    while (q.size())
    {
        auto it = q.lower_bound({x, 0});
        if (it != q.end() && it->first == x)
        {
            if (it->second > y)
                q.erase(it);
            else
                return;
        }
        else
            break;
    }
    auto it1 = q.lower_bound({x, 0});
    if (it1 != q.end())
    {
        if (it1->second <= y)
            return;
        auto it2 = q.lower_bound({x, 0});
        it2--;
        if (!check(*it2, {x, y}, *it1))
            return;
    }
    while (q.size() > 1)
    {
        auto it1 = q.lower_bound({x, 0});
        if (it1 == q.end())
            break;
        auto it2 = q.upper_bound(*it1);
        if (it2 == q.end())
            break;
        if (!check({x, y}, *it1, *it2))
            q.erase(it1);
        else
            break;
    }
    while (q.size())
    {
        auto it1 = q.lower_bound({x, 0});
       /* if (it1 == q.end())
            it1 = q.rbegin();*/
        if (it1 == q.begin())
            break;
        it1--;
        if (it1 == q.begin())
            break;
        auto it2 = q.lower_bound({x, 0});
       /* if (it2 == q.end())
            it2 = q.rbegin();*/
        it2--;
        it2--;
        if (!check(*it2, *it1, {x, y}))
            q.erase(it1);
        else
            break;
    }
    q.insert({x, y});
}

ll maxx = 0, yy = 0;

ld f(ld x)
{
    if ((ld)q.rbegin()->first + eps < x)
        return 1e14;
    pair<int, int> it1 = *q.lower_bound({(ll)(x - eps), 0});
    if (abs(it1.first - x) < eps)
        return it1.second;
    auto kek = q.lower_bound({(ll)(x - eps), 0});
    kek--;
    pair<int, int> it2 = *kek;
    ld X = it1.first, Y = it1.second, XX = it2.first, YY = it2.second;
    ld a = YY - Y, b = X - XX, c = -a * X - b * Y;
    return (-a * x - c) / b;
}

int main()
{
   // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    int qq;
    ll m;
    cin >> qq >> m;
    int j = 0;
    q.insert({0, 0});
    int k = 0;
    for (int i = 1; i <= qq; i++)
    {
        int k, a, b;
        cin >> k >> a >> b;
        if (k == 1)
        {
            ll x = (a + j) % MOD + 1;
            ll y = (b + j) % MOD + 1;
            if (x > maxx)
            {
                maxx = x;
                yy = y;
            }
            else if (x == maxx)
                yy = min(yy, y);
            addPoint(x, y);
        }
        else
        {
            k++;
            ll t = (a + j) % MOD + 1;
            ll h = (b + j) % MOD + 1;
            ll x = (h + t - 1) / t;
            auto it1 = q.lower_bound({x, 0});
            bool ok = 0;
            //f(x) < m / t
            if (it1 != q.end())
            {
                auto it2 = prev(it1);
                ll a = it1->second - it2->second, b = it2->first - it1->first, c = -it1->first * a - it1->second * b;
                if (b < 0)
                    a *= -1, b *= -1, c *= -1;
                if (-a * h - c * t <= m * b)
                    ok = true;
            }
            if (ok)
            {
                j = i;
                cout << "YES\n";
            }
            else
                cout << "NO\n";
        }
    }
    return 0;
}