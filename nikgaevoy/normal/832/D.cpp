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

void build (const vector<vector<int>> &gr, vector<pair<int, vector<int>>> &dub, int st = 0)
{
    static vector<int> path;

    dub[st].first = path.size ();

    for (int i = 1; i <= path.size (); i <<= 1)
        dub[st].second.push_back (path[path.size () - i]);

    path.push_back (st);

    for (auto it : gr[st])
        if (path.size () < 2 || it != path[path.size () - 2])
            build (gr, dub, it);

    path.pop_back ();
}

int lca (const vector<pair<int, vector<int>>> &dub, int a, int b)
{
    if (dub[a].first > dub[b].first)
        return lca (dub, b, a);

    if (dub[a].first < dub[b].first)
    {
        size_t rb = numeric_limits<size_t>::max ();

        while (rb > 0)
        {
            rb = min (rb, dub[b].second.size ());

            while (rb > 0 && dub[dub[b].second[rb - 1]].first < dub[a].first)
                rb--;

            if (rb > 0)
                b = dub[b].second[--rb];
        }
    }

    if (a == b)
        return a;

    size_t rb = numeric_limits<size_t>::max ();

    while (rb > 0)
    {
        rb = min (rb, dub[b].second.size ());

        while (rb > 0 && dub[a].second[rb - 1] == dub[b].second[rb - 1])
            rb--;

        if (rb > 0)
        {
            a = dub[a].second[--rb];
            b = dub[b].second[rb];
        }
    }

    return dub[a].second.front ();
}

int main ()
{
    int n, q;

    cin >> n >> q;

    vector<vector<int>> gr (n);

    for (int i = 1; i < n; i++)
    {
        int p;

        scanf ("%d", &p);
        p--;

        gr[i].push_back (p);
        gr[p].push_back (i);
    }

    vector<pair<int, vector<int>>> dub (n);

    build (gr, dub);

    for (int i = 0; i < q; i++)
    {
        int a, b, c;

        scanf ("%d%d%d", &a, &b, &c);
        a--;
        b--;
        c--;

        int ab = lca (dub, a, b), bc = lca (dub, b, c), ac = lca (dub, a, c);
        int abc = (ab + bc + ac - (ab ^ bc ^ ac)) / 2;

        int la = dub[a].first - max (dub[ab].first, dub[ac].first) + dub[bc].first - dub[abc].first;
        int lb = dub[b].first - max (dub[ab].first, dub[bc].first) + dub[ac].first - dub[abc].first;
        int lc = dub[c].first - max (dub[bc].first, dub[ac].first) + dub[ab].first - dub[abc].first;

        printf ("%d\n", max ({la, lb, lc}) + 1);
    }

    return 0;
}