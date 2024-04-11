#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int inf = (int)1e9 + 7;
const pair<int, int> pinf = pair<int, int>(inf, inf);

int up (int n)
{
    int ret = 1;

    while (ret < n)
        ret <<= 1;

    return ret;
}

template<class T>
class segtree
{
    vector<T> arr;

    T min (int l, int r, int cl, int cr, int pos)
    {
        if (cr <= l || r <= cl)
            return pinf;
        if (l <= cl && cr <= r)
            return arr[pos];

        int ct = (cl + cr) / 2;

        return std::min (min (l, r, cl, ct, 2 * pos), min (l, r, ct, cr, 2 * pos + 1));
    }

    void pset (int pos, T x)
    {
        arr[pos] = x;

        while (pos /= 2)
            arr[pos] = std::min (arr[2 * pos], arr[2 * pos + 1]);
    }

public:
    segtree (int n) : arr (2 * up (n))
    {}

    T min (int l, int r)
    {
        return min (l, r, 0, arr.size () / 2, 1);
    }

    void set (int pos, T x)
    {
        pset (pos + arr.size () / 2, x);
    }
};

class sumtree
{
    vector<int> arr;

    int sum (int l, int r, int cl, int cr, int pos)
    {
        if (cr <= l || r <= cl)
            return 0;
        if (l <= cl && cr <= r)
            return arr[pos];

        int ct = (cl + cr) / 2;

        return sum (l, r, cl, ct, 2 * pos) + sum (l, r, ct, cr, 2 * pos + 1);
    }

    void pset (int pos, int x)
    {
        arr[pos] = x;

        while (pos /= 2)
            arr[pos] = arr[2 * pos] + arr[2 * pos + 1];
    }

public:
    sumtree (int n) : arr (2 * up (n))
    {}

    int sum (int l, int r)
    {
        return sum (l, r, 0, arr.size () / 2, 1);
    }

    void set (int p, int x)
    {
        pset (p + arr.size () / 2, x);
    }
};

int main ()
{
    ios_base::sync_with_stdio (false);

    int n;

    cin >> n;

    vector<int> arr (n);

    for (auto &it : arr)
        cin >> it;

    segtree<pair<int, int>> st (n);
    sumtree cards (n);

    for (int i = 0; i < arr.size (); i++)
        st.set (i, {arr[i], i});

    long long cnt = 0;
    int pos = 0;

    sort (arr.begin (), arr.end ());

    for (int i = 0; i < n; i++)
    {
        auto q = st.min (pos, n);

        if (q.first == arr[i])
        {
            cnt += q.second - pos - cards.sum (pos, q.second);
            pos = q.second;
            st.set (pos, pinf);
            cards.set (pos, 1);
        }
        else
        {
            cnt += n - pos - cards.sum (pos, n);
            i--;
            pos = 0;
        }
    }

    cout << cnt + n << endl;

    return 0;
}