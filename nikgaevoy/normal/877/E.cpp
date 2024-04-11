#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <queue>

#include <cassert>

using namespace std;

const int inf = (int)1e9 + 7;

int up (int n)
{
    int r = 1;

    while (r < n)
        r <<= 1;

    return r;
}

class segtree
{
    vector<int> arr;
    vector<bool> laz;

    void inv (int l, int r, int cl, int cr, int v)
    {
        if (r <= cl || cr <= l)
            return;

        push (v);

        if (l <= cl && cr <= r)
        {
            laz[v] = !laz[v];

            return;
        }

        int ct = (cl + cr) / 2;

        inv (l, r, cl, ct, 2 * v);
        inv (l, r, ct, cr, 2 * v + 1);

        upd (v);
    }

    int cnt (int l, int r, int cl, int cr, int v)
    {
        if (r <= cl || cr <= l)
            return 0;

        push (v);

        if (l <= cl && cr <= r)
            return arr[v];

        int ct = (cl + cr) / 2;

        ct = cnt (l, r, cl, ct, 2 * v) + cnt (l, r, ct, cr, 2 * v + 1);

        upd (v);

        return ct;
    }

    void push (int v)
    {
        if (laz[v])
        {
            laz[v] = false;
            arr[v] = arr.size () / up (v + 1) - arr[v];

            if (v < (int)arr.size () / 2)
            {
                laz[2 * v] = !laz[2 * v];
                laz[2 * v + 1] = !laz[2 * v + 1];
            }
        }
    }

    void upd (int v)
    {
        if (v < (int)arr.size () / 2)
        {
            push (2 * v);
            push (2 * v + 1);
            arr[v] = arr[2 * v] + arr[2 * v + 1];
        }
    }

public:
    segtree (int n) : arr (2 * up (n)), laz (2 * up (n))
    {}

    void inv (int l, int r)
    {
        inv (l, r, 0, arr.size () / 2, 1);
    }

    int cnt (int l, int r)
    {
        return cnt (l, r, 0, arr.size () / 2, 1);
    }
};

void dfs (const vector<vector<int>> &gr, int v, vector<int> &in, vector<int> &out, int &cnt)
{
    in[v] = cnt++;

    for (auto it : gr[v])
        dfs (gr, it, in, out, cnt);

    out[v] = ++cnt;
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n;

    cin >> n;

    vector<vector<int>> gr (n);

    for (int i = 1; i < n; i++)
    {
        int p;

        cin >> p;

        p--;

        gr[p].push_back (i);
    }

    vector<int> in (n), out (n);
    n = 0;

    dfs (gr, 0, in, out, n);

    segtree st (n);

    n /= 2;
    for (int i = 0; i < n; i++)
    {
        int t;

        cin >> t;

        if (t == 1)
        {
            st.inv (in[i], in[i] + 1);
            st.inv (out[i] - 1, out[i]);
        }
    }

    int q;

    cin >> q;

    for (int i = 0; i < q; i++)
    {
        string s;
        int t;

        cin >> s >> t;
        t--;

        if (s == "get")
        {
            cout << st.cnt (in[t], out[t]) / 2 << endl;
        }
        else
        {
            assert (s == "pow");

            st.inv (in[t], out[t]);
        }
    }

    return 0;
}