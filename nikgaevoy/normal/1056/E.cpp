#ifdef LOCAL
#include "stdafx.h"
#else
#include <bits/stdc++.h>
#endif // LOCAL


using namespace std;


mt19937 mt (736);


using ll = long long;

const int mod1 = 1e9 + 9, mod2 = 1e9 + 7;
const ll mult1 = 193, mult2 = 736;


template<class T>
T sqr (T x)
{
    return x * x;
}


ll powmod (ll x, int y, int mod)
{
    return y ? (y & 1 ? x * powmod (x, y - 1, mod) : sqr (powmod (x, y / 2, mod))) % mod : 1;
}


struct H
{
    int x, y;
    H (int x = 0) : x (x), y (x)
    {}

    H (int x, int y) : x (x), y (y)
    {}

    H &operator+= (const H &b)
    {
        x += b.x;
        if (x >= mod1)
            x -= mod1;
        y += b.y;
        if (y >= mod2)
            y -= mod2;

        return *this;
    }

    H &operator-= (const H &b)
    {
        x -= b.x;
        if (x < 0)
            x += mod1;
        y -= b.y;
        if (y < 0)
            y += mod2;

        return *this;
    }

    H &operator<<= (int i)
    {
        x = (x * powmod (mult1, i, mod1)) % mod1;
        y = (y * powmod (mult2, i, mod2)) % mod2;

        return *this;
    }


    H operator<< (int i) const
    {
        return H ((x * powmod (mult1, i, mod1)) % mod1, (y * powmod (mult2, i, mod2)) % mod2);
    }


    H &operator>>= (int i)
    {
        x = (x * powmod (mult1, mod1 - 1 - i, mod1)) % mod1;
        y = (y * powmod (mult2, mod2 - 1 - i, mod2)) % mod2;

        return *this;
    }


    H operator>> (int i) const
    {
        return H ((x * powmod (mult1, mod1 - 1 - i, mod1)) % mod1,
            (y * powmod (mult2, mod2 - 1 - i, mod2)) % mod2);
    }


    bool operator ==(const H &B) const
    {
        return x == B.x && y == B.y;
    }

    bool operator !=(const H &B) const
    {
        return x != B.x || y != B.y;
    }
};


H get_seg (const vector<H> &ph, int l, int r)
{
    H ans = ph[r];
    ans -= (ph[l] << (r - l));

    return ans;
}


bool check (const string &s, const vector<H> &ph, int q, int w)
{
    H z = -1, o = -1;
    int pos = 0;
    bool good = true;

    for (auto it : s)
    {
        if (it == '0')
        {
            if (z == -1)
                z = get_seg (ph, pos, pos + q);
            else
                good = z == get_seg (ph, pos, pos + q);

            pos += q;
        }
        else
        {
            if (o == -1)
                o = get_seg (ph, pos, pos + w);
            else
                good = o == get_seg (ph, pos, pos + w);

            pos += w;
        }

        if (!good)
            break;
    }

    return good && (z != o);
}


void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    string s, t;

    cin >> s >> t;

    vector<H> ph (t.size () + 1);

    for (int i = 1; i < ph.size (); i++)
    {
        ph[i] = ph[i - 1] << 1;
        ph[i] += t[i - 1];
    }

    if (s.front () == '1')
        for (auto &it : s)
            it ^= '0' ^ '1';

    int zeros = count (s.begin (), s.end (), '0');
    int ones = count (s.begin (), s.end (), '1');

    int ans = 0;

    if (ones == 0)
    {
        if (t.size () % zeros == 0)
            ans = check (s, ph, t.size () / zeros, 0) ? 1 : 0;
    }
    else
        for (int l = 1; zeros * l + ones <= (int)t.size (); l++)
        {
            int q = ((int)t.size () - zeros * l) / ones;

            if (q * ones + l * zeros != t.size ())
                continue;

            if (check (s, ph, l, q))
            {
#ifdef LOCAL
                cerr << l << endl;
#endif // LOCAL

                ans++;
            }
        }

    cout << ans << endl;
}


int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);

#ifdef LOCAL
    ifstream fin ("input.txt");

    solve (fin);

    cout << setprecision (4) << "clock: " << clock () / (double)CLOCKS_PER_SEC << endl;
#else
    solve ();
#endif // LOCAL

    return 0;
}