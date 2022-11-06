#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int trash = 0;
    for (int i = 0; i < k; i++)
    {
        cin >> trash >> trash >> trash >> trash;
    }
    cout << n + m + n * m - 3 << "\n";
    for (int i = 0; i < n - 1; i++)
        cout << "U";
    for (int i = 0; i < m - 1; i++)
        cout << "L";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            if (i % 2 == 0)
                cout << "R";
            else
                cout << "L";
        }
        if (i < n - 1)
            cout << "D";
    }
    cout << endl;
    return 0;
}