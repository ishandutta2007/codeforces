#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <random>
#include <vector>
#include <unordered_map>

#include <cassert>

using namespace std;

int up (int n)
{
    int r = 1;

    while (r < n)
        r <<= 1;

    return r;
}

int down (int n)
{
    return n & (n - 1) ? down (n & (n - 1)) : n;
}

int logb (int n)
{
    return n ? 1 + logb (n >> 1) : -1;
}

class sparse_table
{
    vector<vector<int>> st;

public:
    sparse_table (const vector<int> &arr) : st (1, arr)
    {
        st.front ().resize (up (st.front ().size ()));

        while (st.back ().size () != 1)
        {
            st.push_back (vector<int> (st.front ().size () - (1 << st.size ()) + 1));

            for (int i = 0; i < st.back ().size (); i++)
                st.back ()[i] = st[st.size () - 2][i] |
                st[st.size () - 2][i + st[st.size () - 2].size () - st.back ().size ()];
        }
    }

    int op (int l, int r) const
    {
        int lvl = logb (r - l), d = down (r - l);

        return st[lvl][l] | st[lvl][r - d];
    }
};

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n;

    cin >> n;

    vector<int> arr (n);

    for (auto &it : arr)
        cin >> it;

    unordered_map<int, int> mem;

    vector<int> prev (arr.size (), -1);

    for (int i = 0; i < prev.size (); i++)
    {
        if (mem.count (arr[i]))
            prev[i] = mem[arr[i]];

        mem[arr[i]] = i;
    }

    sparse_table st (arr);

    long long ans = arr.size () * (arr.size () + 1ll) / 2;

    for (int i = 0; i < arr.size (); i++)
    {
        int le, ri;

        int l = prev[i], r = i;

        while (l + 1 < r)
        {
            auto t = (l + r) / 2;

            (st.op (t, i + 1) == arr[i] ? r : l) = t;
        }

        le = r;

        if (st.op (i, arr.size ()) == arr[i])
            ri = arr.size ();
        else
        {
            l = i + 1, r = arr.size ();

            while (l + 1 < r)
            {
                auto t = (l + r) / 2;

                (st.op (i, t) == arr[i] ? l : r) = t;
            }

            ri = l;
        }

        ans -= (i + 1ll - le) * (ri - i);
    }

    cout << ans << endl;

    return 0;
}