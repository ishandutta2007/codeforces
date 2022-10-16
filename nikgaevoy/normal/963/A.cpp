#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <random>
#include <limits>
#include <string>
#include <sstream>
#include <iomanip>

#include <cassert>
#include <cmath>
#include <ctime>

#pragma comment(linker, "/STACK:200000000")

using namespace std;

mt19937 mt (736);

template<class T>
T sqr (T x)
{
    return x * x;
}

long long powmod (long long x, int y, int mod)
{
    return y ? (y & 1 ? x * powmod (x, y - 1, mod) : sqr (powmod (x, y / 2, mod))) % mod : 1;
}

template<int mod = (int)1e9 + 9>
struct F
{
    int x;

    F<mod> operator* (const F<mod> &a) const
    {
        return F<mod> (x * (long long)a.x);
    }

    F<mod> &operator*= (const F<mod> &a)
    {
        x = (x * (long long)a.x) % mod;

        return *this;
    }

    F<mod> operator+ (const F<mod> &a) const
    {
        return F<mod> (x + a.x);
    }

    F<mod> &operator+= (const F<mod> &a)
    {
        x += a.x;

        if (x >= mod)
            x -= mod;

        return *this;
    }

    F<mod> operator- (const F<mod> &a) const
    {
        return F<mod> (x - a.x);
    }

    F<mod> operator- () const
    {
        return F<mod> (-x);
    }

    F<mod> &operator-= (const F<mod> &a)
    {
        x -= a.x;

        if (x < 0)
            x += mod;

        return *this;
    }

    F<mod> pow (int y) const
    {
        return F<mod> (powmod (x, y, mod));
    }

    F<mod> inv () const
    {
        return F<mod> (powmod (x, mod - 2, mod));
    }

    int val () const
    {
        return x;
    }

    template<class T = int>
    F (T a = 0) : x (a % mod)
    {
        if (x < 0)
            x += mod;
    }

    bool operator== (const F<mod> &a) const
    {
        return x == a.x;
    }
};

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int n, a, b, k;

    cin >> n >> a >> b >> k;

    string str;

    cin >> str;

    F<> ans, cur (a), mult (a);
    cur = cur.pow (n);
    mult = mult.inv () * b;

    for (auto it : str)
    {
        ans += (it == '+' ? cur : -cur);

        cur *= mult;
    }

    mult = mult.pow (k);

    n++;
    n /= k;

    if (mult == 1)
        ans *= n;
    else
        ans *= (mult.pow (n) - 1) * (mult - 1).inv ();

    cout << ans.x << endl;
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);

#ifdef LOCAL
    solve ();

    cout << "clock: " << clock () << endl;
#else
    solve ();
#endif // LOCAL

    return 0;
}