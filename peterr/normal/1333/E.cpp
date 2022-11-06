#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500;
int mat[3][3] = {{1, 8, 5}, {2, 6, 3}, {9, 7, 4}};
int ans[MAXN][MAXN];

void flipHorz(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
            swap(ans[i][j], ans[i][n - j - 1]);
    }
}

void flipVert()
{
    swap(mat[0][0], mat[2][0]);
    swap(mat[0][1], mat[2][1]);
    swap(mat[0][2], mat[2][2]);
}

int main()
{
    int n;
    cin >> n;
    if (n <= 2)
        cout << -1 << endl;
    else
    {
        int cur = 1;
        for (int i = 0; i < n - 3; i++)
        {
            for (int j = 0; j < n; j++)
                ans[i][j] = cur++;
            flipHorz(n);
        }
        for (int j = 0; j < n - 3; j++)
        {
            if (j % 2 == 0)
            {
                for (int i = n - 3; i < n; i++)
                    ans[i][j] = cur++;
            }
            else
            {
                for (int i = n - 1; i >= n - 3; i--)
                    ans[i][j] = cur++;
            }
        }
        if (n % 2 == 0)
            flipVert();
        cur--;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                ans[n - 3 + i][n - 3 + j] = cur + mat[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << ans[i][j] << " \n"[j == n - 1];
        }

    }
    return 0;
}