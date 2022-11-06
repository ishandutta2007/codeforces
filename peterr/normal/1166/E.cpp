#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    bool** table = new bool*[m];
    for (int i = 0; i < m; i++)
    {
        table[i] = new bool[n + 1];
        fill(table[i], table[i] + n + 1, false);
    }

    for (int i = 0; i < m; i++)
    {
        int s;
        cin >> s;
        for (int j = 0; j < s; j++)
        {
            int store;
            cin >> store;
            table[i][store] = true;
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            bool good = false;
            for (int k = 1; k <= n; k++)
            {
                if (table[i][k] && table[j][k])
                {
                    good = true;
                    break;
                }
            }
            if (!good)
            {
                cout << "impossible";
                return 0;
            }
        }
    }
    cout << "possible";

    return 0;
}