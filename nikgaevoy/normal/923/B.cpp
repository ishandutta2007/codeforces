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

#include <cassert>
#include <cmath>
#include <ctime>

#pragma comment(linker, "/STACK:200000000")

using namespace std;

mt19937 mt (736);

int up (int n)
{
    int r = 1;

    while (r < n)
        r <<= 1;

    return r;
}

template<class T>
class segtree
{
    vector<T> arr, laz;

    void add (int l, int r, int cl, int cr, int v, int x)
    {
        if (r <= cl || cr <= l)
            return;

        if (l <= cl && cr <= r)
        {
            laz[v] += x * (cr - cl);

            return;
        }

        auto ct = (cl + cr) / 2;

        add (l, r, cl, ct, 2 * v, x);
        add (l, r, ct, cr, 2 * v + 1, x);
    }

public:
    segtree (int n) : arr (2 * up (n)), laz (2 * up (n))
    {}

    void push (int v)
    {
        arr[v] += laz[v];

        if (v < (int)arr.size () / 2)
        {
            laz[2 * v] += laz[v] / 2;
            laz[2 * v + 1] += laz[v] / 2;
        }

        laz[v] = 0;
    }

    void to_vector (vector<T> &ans)
    {
        ans.resize (arr.size () / 2);

        for (int i = 0; i < (int)arr.size (); i++)
            push (i);

        copy (arr.begin () + arr.size () / 2, arr.end (), ans.begin ());
    }

    void add (int l, int r, int x)
    {
        add (l, r, 0, arr.size () / 2, 1, x);
    }
};

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int n;

    cin >> n;

    vector<long long> v (n), t (n);

    for (auto &it : v)
        cin >> it;
    for (auto &it : t)
        cin >> it;

    vector<long long> ps (t.size () + 1);

    for (int i = 1; i < ps.size (); i++)
        ps[i] = ps[i - 1] + t[i - 1];

    vector<long long> ans (n);

    segtree<long long> mult (n);

    for (int i = 0; i < v.size (); i++)
        if (v[i] > 0)
        {
            long long E = v[i] + ps[i];

            auto wh = lower_bound (ps.begin (), ps.end (), E) - ps.begin () - 1;

            if (wh < ans.size ())
                ans[wh] += E - ps[wh];

            mult.add (i, wh, 1);
        }

    vector<long long> tmp;

    mult.to_vector (tmp);

    for (int i = 0; i < ans.size (); i++)
        ans[i] += t[i] * (long long)tmp[i];

    for (auto it : ans)
        cout << it << ' ';
    cout << endl;
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);

#ifdef LOCAL
    solve ();

    cout << "clock: " << clock () << endl;
#else
    solve ();
#endif // LOCAL

    return 0;
}