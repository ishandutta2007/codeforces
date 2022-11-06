#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int* b = new int[n];
    int* g = new int[m];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin >> g[i];
    }
    sort(b, b + n);
    sort(g, g + m);
    if (b[n-1] > g[0])
    {
        cout << -1;
    }
    else
    {
        long long sol = 0;
        for (int i = 0; i < n; i++)
        {
            sol += (long long) b[i] * m;
        }
        if (b[n-1] == g[0])
        {
            for (int i = 0; i < m; i++)
            {
                sol += g[i] - b[n-1];
            }
        }
        else
        {
            for (int i = 1; i < m; i++)
            {
                sol += g[i] - b[n-1];
            }
            sol += g[0] - b[n-2];
        }
        cout << sol;
    }

    return 0;
}