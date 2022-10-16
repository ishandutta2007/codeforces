#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = (int)1e9 + 7;

int up (int n)
{
    int r = 1;

    while (r < n)
        r <<= 1;

    return r;
}

int logb (int n)
{
    return n ? logb (n >>= 1) + 1 : -1;
}

class sparse_table
{
    vector<vector<int>> stmin, stmax;

public:
    sparse_table (const vector<int> &arr) : stmin (1, arr), stmax (1, arr)
    {
        for (int r = 2; r <= arr.size (); r <<= 1)
        {
            stmin.push_back (vector<int> (arr.size () - r + 1));

            for (int i = 0; i < stmin.back ().size (); i++)
                stmin.back ()[i] =
                min (stmin[stmin.size () - 2][i],
                     stmin[stmin.size () - 2]
                     [i + stmin[stmin.size () - 2].size () - stmin.back ().size ()]);

            stmax.push_back (vector<int> (arr.size () - r + 1));

            for (int i = 0; i < stmax.back ().size (); i++)
                stmax.back ()[i] =
                max (stmax[stmax.size () - 2][i],
                     stmax[stmax.size () - 2]
                     [i + stmax[stmax.size () - 2].size () - stmax.back ().size ()]);
        }
    }

    int segmin (int l, int r) const
    {
        int ind = logb (r - l);

        return min (stmin[ind][l], stmin[ind][r - (1 << ind)]);
    }

    int segmax (int l, int r) const
    {
        int ind = logb (r - l);

        return max (stmax[ind][l], stmax[ind][r - (1 << ind)]);
    }

    int operator[] (size_t pos) const
    {
        return stmin.front ()[pos];
    }
};

int jump (int n, int p, int s, const sparse_table &st, int dist)
{
    int l = p, r = n;

    while (l + 1 < r)
    {
        auto t = (l + r) / 2;

        int u = st.segmax (p, t + 1);
        int d = st.segmin (p, t + 1);

        (u - s <= dist && s - d <= dist ? l : r) = t;
    }

    return r;
}

bool check (int n, int s1, int s2, sparse_table &st, int dist)
{
    if (dist < abs (s1 - s2))
        return false;

    if (dist < abs (s1 - st[0]) &&
        dist < abs (s2 - st[0]))
        return false;

    vector<int> jumps (n);

    for (int i = 0; i < jumps.size (); i++)
        jumps[i] = jump (n, i, st[i], st, dist);

    int rb = max (jump (n, 0, s1, st, dist),
                  jump (n, 0, s2, st, dist));

    for (int i = 0; i < jumps.size (); i++)
    {
        if (i == rb)
            return false;

        rb = max (rb, jumps[i]);
    }

    return true;
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n, s1, s2;

    cin >> n >> s1 >> s2;

    vector<int> x (n);

    for (auto &it : x)
        cin >> it;

    sparse_table st (x);

    int l = 0, r = inf;

    while (l + 1 < r)
    {
        auto t = (l + r) / 2;

        (check (n, s1, s2, st, t) ? r : l) = t;
    }

    cout << r << endl;

    return 0;
}