#include <bits/stdc++.h>

using namespace std;

const int MAGIC = 720720;
const int MAXN = 500;
const int NUM = 31;
int a[NUM];
int mat[MAXN][MAXN];
int ans[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 1; i <= NUM; i++)
    {
        a[i - 1] = i * i * i * i;
        //cout << a[i - 1] << endl;
    }
    for (int i = 1; i <= 16; i++)
    {
        bool flag = false;
        for (int j = 0; j < NUM; j++)
        {
            int x = a[j];
            if (x % i == 0)
                flag = true;
        }
        /*
        if (!flag)
            cout << "NO\n";
        else
            cout << "1\n";
        */
    }
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            if ((i + j) & 1)
                ans[i][j] = MAGIC;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i + j) & 1)
                continue;
            for (int k = 0; k < NUM; k++)
            {
                if ((MAGIC - a[k]) % mat[i][j] == 0)
                {
                    ans[i][j] = MAGIC - a[k];
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << ans[i][j] << " \n"[j == m - 1];
    }
    return 0;
}