#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

//#include <conio.h>

using namespace std;

const string filename = "sum";

int main ()
{
    //freopen ((filename + ".in").c_str (), "r", stdin);
    //freopen ((filename + ".out").c_str (), "w", stdout);

    ios_base::sync_with_stdio (false);

    int n, k;

    cin >> n >> k;

    vector<vector<bool>> field (n, vector<bool> (n));
    int l = 0;

    for (int i = 0; l < k && i < n; i++)
        for (int j = 0; l < k && j < n; j++)
            if ((i + j) % 2 == 0)
                l += field[i][j] = 1;

    if (l == k)
    {
        cout << "YES" << endl;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << (field[i][j] ? 'L' : 'S');
            cout << endl;
        }
    }
    else
        cout << "NO" << endl;

//    _getch ();

    return 0;
}