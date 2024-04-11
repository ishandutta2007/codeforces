#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <queue>

#include <cassert>

using namespace std;

const int inf = (int)1e9 + 7;

vector<vector<pair<int, int>>> bordgen (const vector<string> &field)
{
    vector<vector<pair<int, int>>> bord (field.size (), vector<pair<int, int>>
        (field.front ().size (), {-1, -1}));

    for (int i = 0; i < bord.size (); i++)
    {
        int prev = -1;

        for (int j = 0; j < bord[i].size (); j++)
            if (field[i][j] == '#')
            {
                for (int k = prev + 1; k < j; k++)
                    bord[i][k] = {prev, j};

                prev = j;
            }

        for (int k = prev + 1; k < bord[i].size (); k++)
            bord[i][k] = {prev, bord[i].size ()};
    }

    return bord;
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n, m, k;

    cin >> n >> m >> k;

    vector<string> field (n);
    vector<string> transp (m);

    for (auto &row : field)
    {
        cin >> row;

        assert (row.size () == m);

        for (size_t i = 0; i < row.size (); i++)
            transp[i].push_back (row[i]);
    }

    vector<set<int>> frest (n), fretr (m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            frest[i].insert (j);
            fretr[j].insert (i);
        }

    auto bfi = bordgen (field), btr = bordgen (transp);

    int x, y, fx, fy;

    cin >> y >> x >> fy >> fx;
    y--;
    x--;
    fy--;
    fx--;

    queue<pair<int, int>> bfs;
    bfs.push ({x, y});

    vector<vector<int>> dist (n, vector<int> (m, -1));
    dist[y][x] = 0;
    frest[y].erase (x);
    fretr[x].erase (y);

    while (!bfs.empty ())
    {
        auto it = bfs.front ();
        bfs.pop ();

        int y = it.second;
        int x = it.first;

        int l = bfi[y][x].first + 1;
        int r = bfi[y][x].second - 1;
        l = max (l, x - k);
        r = min (r, x + k);

        while (frest[y].lower_bound (l) != frest[y].end () &&
               *frest[y].lower_bound (l) <= r)
        {
            int pos = *frest[y].lower_bound (l);
            frest[y].erase (pos);
            fretr[pos].erase (y);

            dist[y][pos] = dist[y][x] + 1;

            bfs.push ({pos, y});
        }

        l = btr[x][y].first + 1;
        r = btr[x][y].second - 1;
        l = max (l, y - k);
        r = min (r, y + k);

        while (fretr[x].lower_bound (l) != fretr[x].end () &&
               *fretr[x].lower_bound (l) <= r)
        {
            int pos = *fretr[x].lower_bound (l);
            fretr[x].erase (pos);
            frest[pos].erase (x);

            dist[pos][x] = dist[y][x] + 1;

            bfs.push ({x, pos});
        }
    }

    cout << dist[fy][fx] << endl;

    return 0;
}