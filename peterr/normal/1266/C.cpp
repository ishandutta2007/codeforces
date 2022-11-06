#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500;
int rows[MAXN];
int cols[MAXN];

int main()
{
    int r, c;
    cin >> r >> c;
    if (r == 1 && c == 1)
        cout << 0 << endl;
    else
    {
        if (r > 1)
        {
            int cnt = 2;
            for (int i = 0; i < r; i++)
            {
                rows[i] = cnt++;
            }
            cols[0] = 1;
            for (int i = 1; i < c; i++)
            {
                cols[i] = cnt++;
            }
        }
        else
        {
            int cnt = 2;
            for (int i = 0; i < c; i++)
            {
                cols[i] = cnt++;
            }
            rows[0] = 1;
            for (int i = 1; i < r; i++)
            {
                rows[i] = cnt++;
            }
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << rows[i] / __gcd(rows[i], cols[j]) * cols[j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}