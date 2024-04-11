#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const int inf = (int)1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (false);

    int h, w;

    cin >> h >> w;

    vector<string> field (h);

    for (auto &it : field)
        cin >> it;

    int minx = numeric_limits<int>::max (), maxx = numeric_limits<int>::min ();
    int miny = numeric_limits<int>::max (), maxy = numeric_limits<int>::min ();
    int cnt = 0;

    for (int y = 0; y < field.size (); y++)
    {
        int l = field[y].find ('B'), r = field[y].find_last_of ('B');

        if (l < string::npos)
        {
            minx = min (minx, l);
            maxx = max (maxx, r);
            miny = min (miny, y);
            maxy = max (maxy, y);

            cnt += count (field[y].begin (), field[y].end (), 'B');
        }
    }

    if (maxx < minx)
        cout << 1 << endl;
    else
    {
        int r = 1 + max (maxx - minx, maxy - miny);

        cout << (r <= min (h, w) ? r * r - cnt : -1) << endl;
    }

    return 0;
}