#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <bitset>

using namespace std;

typedef long long ll;

vector< vector<char> > c;

int main()
{
    int n, m;
    cin >> n >> m;
    c.assign(n, vector<char>(m, 'a'));
    int minx = 1e9, maxx = -1, miny = 1e9, maxy = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> c[i][j];
            if (c[i][j] != '.')
            {
                minx = min(minx, i);
                maxx = max(maxx, i);
                miny = min(miny, j);
                maxy = max(maxy, j);
            }
        }
    for (int i = minx; i <= maxx; i++)
        for (int j = miny; j <= maxy; j++)
            if (c[i][j] == '.')
            {
                cout << "NO";
                return 0;
            }
            cout << "YES";
    return 0;
}