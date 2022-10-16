#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <random>
#include <complex>
#include <iomanip>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>

#pragma comment(linker,"/STACK:200000000")

using namespace std;

const bool interactive = false;
const string filename = "records";
const double pi = 3.14159265358979323846;
const int inf = int (1e9) + 7;
const long long linf = (long long) 1e18 + 9;
const int dy[] = {1, 0, 0, -1}, dx[] = {0, -1, 1, 0};

bool empty (const vector<vector<char>> &field, int x, int y)
{
    return x >= 0 && y >= 0 && y < field.size () && x < field[y].size () &&
        (field[y][x] == '.' || field[y][x] == 'X');
}

void bfs (const vector<vector<char>> &field, vector<vector<int>> &dist, int sx, int sy)
{
    queue<pair<int, pair<int, int>>> q;
    q.push (make_pair (0, make_pair (sx, sy)));

    while (!q.empty ())
    {
        int x = q.front ().second.first, y = q.front ().second.second;
        int d = q.front ().first;

        q.pop ();

        if (dist[y][x] > d)
        {
            dist[y][x] = d;

            for (int i = 0; i < 4; i++)
                if (empty (field, x + dx[i], y + dy[i]))
                    q.push (make_pair (d + 1, make_pair (x + dx[i], y + dy[i])));
        }
    }
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n, m, k;

    cin >> n >> m >> k;

    vector<vector<char>> field (n, vector<char> (m));

    int sx, sy;

    for (int i = 0; i < field.size (); i++)
        for (int j = 0; j < field[i].size (); j++)
        {
            cin >> field[i][j];

            if (field[i][j] == 'X')
            {
                sx = j;
                sy = i;
            }
        }

    if (k % 2 == 1 || (!empty (field, sx + 1, sy) && !empty (field, sx - 1, sy) &&
                       !empty (field, sx, sy + 1) && !empty (field, sx, sy - 1)))
    {
        cout << "IMPOSSIBLE" << endl;

        return 0;
    }

    string path, dir = "DLRU";

    vector<vector<int>> dist (n, vector<int> (m, inf));

    bfs (field, dist, sx, sy);

    path.reserve (k);

    while (k-- > 0)
    {
        int i;
        for (i = 0; !empty (field, sx + dx[i], sy + dy[i]) || dist[sy + dy[i]][sx + dx[i]] > k; i++);

        sx += dx[i];
        sy += dy[i];

        path.push_back (dir[i]);
    }

    cout << path.c_str () << endl;

    return 0;
}