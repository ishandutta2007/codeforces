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
#include <iomanip>

#include <cassert>
#include <cmath>
#include <ctime>

#pragma comment(linker, "/STACK:200000000")

using namespace std;

mt19937 mt (736);

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int r, c;

    cin >> r >> c;

    vector<string> field (r);

    for (auto &row : field)
        cin >> row;

    for (int y = 0; y < field.size (); y++)
        for (int x = 0; x < field[y].size (); x++)
        {
            int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};

            for (int i = 0; i < 4; i++)
                if (0 <= y + dy[i] && y + dy[i] < field.size () &&
                    0 <= x + dx[i] && x + dx[i] < field[y].size () &&
                    field[y][x] == 'S' && field[y + dy[i]][x + dx[i]] == 'W')
                {
                    cout << "No" << endl;

                    return;
                }
        }

    cout << "Yes" << endl;

    for (auto &row : field)
    {
        replace (row.begin (), row.end (), '.', 'D');
        cout << row << endl;
    }
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);

#ifdef LOCAL
    solve ();

    cout << "clock: " << clock () << endl;
#else
    solve ();
#endif // LOCAL

    return 0;
}