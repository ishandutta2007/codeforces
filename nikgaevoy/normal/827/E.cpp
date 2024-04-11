#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <complex>

using namespace std;

const int inf = (int)1e9 + 7;
const double pi = 3.14159265358979323846;

template<class T>
T gcd (T a, T b)
{
    return b == 0 ? a : gcd (b, a % b);
}

int ilog (int n)
{
    int r = 0;

    while ((1 << r) < n)
        r++;

    return r;
}

complex<double> get_prim (int a, int b)
{
    static vector<complex<double>> dp = {1};

    if (dp.size () == 1)
    {
        dp.reserve (1 << 20);

        double ang = pi / (1 << 19);

        while (dp.size () < (1 << 20))
            dp.push_back ({cos (ang * dp.size ()), sin (ang * dp.size ())});
    }

    return dp[a * (dp.size () / b)];
}

void fft (vector<complex<double>> &a, bool invert = false)
{
    if (a.size () < 2)
        return;

    vector<complex<double>> a0 (a.size () / 2), a1 (a.size () / 2);

    for (int i = 0; i < a.size (); i++)
        (i & 1 ? a1 : a0)[i / 2] = a[i];

    fft (a0, invert);
    fft (a1, invert);

    for (int i = 0; i < a.size () / 2; ++i)
    {
        complex<double> w = get_prim (i, a.size ());

        if (invert)
            w.imag (-w.imag ());

        a[i] = a0[i] + w * a1[i];
        a[i + a.size () / 2] = a0[i] - w * a1[i];

        if (invert)
        {
            a[i] /= 2;
            a[i + a.size () / 2] /= 2;
        }
    }
}

template<class T>
T up (T n)
{
    T ret = 1;

    while (ret < n)
        ret <<= 1;

    return ret;
}

void mult (const vector<int> &a, const vector<int> &b, vector<int> &r)
{
    vector<complex<double>> fa (a.begin (), a.end ()),
        fb (b.begin (), b.end ());

    fa.resize (2 * up (max (fa.size (), fb.size ())));
    fb.resize (fa.size ());

    fft (fa);
    fft (fb);

    for (size_t i = 0; i < fa.size (); i++)
        fa[i] *= fb[i];

    fft (fa, true);

    fb.clear ();
    r.reserve (fa.size ());

    for (auto it : fa)
        r.push_back ((int)round (it.real ()));
}

int main ()
{
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int t;

        scanf ("%d", &t);

        char *s = new char[t + 1];

        scanf ("%s", s);
        vector<int> V (t), K (t), r;

        for (int i = 0; i < t; i++)
            if (s[i] == 'V')
                V[i] = 1;
            else if (s[i] == 'K')
                K[t - 1 - i] = 1;

        delete[] s;

        mult (V, K, r);

        vector<bool> bad (t);

        for (int i = 0; i < r.size (); i++)
            if (r[i])
                bad[abs (i - (int)t + 1)] = true;

        vector<int> ans;

        for (int i = 1; i <= t; i++)
        {
            bool good = true;

            for (int j = i; j < t; j += i)
                if (bad[j])
                {
                    good = false;
                    break;
                }

            if (good)
                ans.push_back (i);
        }

        printf ("%d\n", ans.size ());
        for (auto it : ans)
            printf ("%d ", it);
        printf ("\n");
    }

    return 0;
}