#include <iostream>

using namespace std;

const int MAXN = 500;
int mat[MAXN][MAXN];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum ^= mat[i][0];
    }
    if (sum > 0)
    {
        cout << "TAK" << endl;
        for (int i = 0; i < n; i++)
            cout << 1 << " ";
    }
    else
    {
        int row = n, col = m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (mat[i][j] != mat[i][0])
                {
                    row = i;
                    col = j;
                }
            }
        }
        if (row == n)
            cout << "NIE";
        else
        {
            cout << "TAK" << endl;
            for (int i = 0; i < n; i++)
            {
                if (i != row)
                    cout << 1 << " ";
                else
                    cout << (col + 1) << " ";
            }
        }
    }
    return 0;
}