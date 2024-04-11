#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000;
bool white[MAXN][MAXN];
bool colWhite[MAXN];
bool rowWhite[MAXN];
pair<int, int> col[MAXN];
pair<int, int> row[MAXN];
int ans1[MAXN][MAXN];
int ans2[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == 'W')
                white[i][j] = true;
        }
    }
    for (int i = 0; i < n; i++)
    {
        colWhite[i] = rowWhite[i] = true;
        for (int j = 0; j < n; j++)
        {
            if (!white[i][j])
                rowWhite[i] = false;
            if (!white[j][i])
                colWhite[i] = false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (colWhite[i])
        {
            col[i] = {0, n - 1};
        }
        else
        {
            int bot = 0;
            while (white[bot][i])
                bot++;
            int top = n - 1;
            while (white[top][i])
                top--;
            top -= k - 1;
            col[i] = {top, bot};
        }
        if (rowWhite[i])
        {
            row[i] = {0, n - 1};
        }
        else
        {
            int left = 0;
            while (white[i][left])
                left++;
            int right = n - 1;
            while (white[i][right])
                right--;
            right -= k - 1;
            row[i] = {right, left};
        }
    }
    for (int j = 0; j + k - 1 < n; j++)
    {
        for (int i = 0; i < k; i++)
        {
            if (!colWhite[i] && j >= col[i].first && j <= col[i].second)
                ans1[j][0]++;
        }
    }
    for (int i = 0; i + k - 1 < n; i++)
    {
        for (int j = 1; j + k - 1 < n; j++)
        {
            ans1[i][j] = ans1[i][j - 1];
            if (!colWhite[j - 1] && i >= col[j - 1].first && i <= col[j - 1].second)
            {
                ans1[i][j]--;
            }
            if (!colWhite[j + k - 1] && i >= col[j + k - 1].first && i <= col[j + k - 1].second)
            {
                ans1[i][j]++;
            }
        }
    }
    for (int j = 0; j + k - 1 < n; j++)
    {
        for (int i = 0; i < k; i++)
        {
            if (!rowWhite[i] && j >= row[i].first && j <= row[i].second)
                ans2[0][j]++;
        }
    }
    for (int i = 0; i + k - 1 < n; i++)
    {
        for (int j = 1; j + k - 1 < n; j++)
        {
            ans2[j][i] = ans2[j - 1][i];
            if (!rowWhite[j - 1] && i >= row[j - 1].first && i <= row[j - 1].second)
            {
                ans2[j][i]--;
            }
            if (!rowWhite[j + k - 1] && i >= row[j + k - 1].first && i <= row[j + k - 1].second)
            {
                ans2[j][i]++;
            }
        }
    }
    int sol = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sol = max(sol, ans1[i][j] + ans2[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        sol += colWhite[i] + rowWhite[i];
    }
    cout << sol << endl;

    return 0;
}