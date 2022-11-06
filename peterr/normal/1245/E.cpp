#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10;
int board[MAXN][MAXN];
pair<int, int> order[MAXN * MAXN];
long double ans[MAXN][MAXN];

int main()
{
    for (int i = 0; i < MAXN; i++)
    {
        for (int j = 0; j < MAXN; j++)
        {
            cin >> board[i][j];
        }
    }
    int index = 0;
    for (int i = 0; i < 10; i++)
    {
        int start = i % 2 == 0 ? 0 : MAXN - 1;
        int end = i % 2 == 0 ? MAXN : -1;
        int inc = i % 2 == 0 ? 1 : -1;
        for (int j = start; j != end; j += inc)
        {
            order[index++] = {i, j};
        }
    }
    for (int i = 1; i <= 6; i++)
    {
        ans[order[i].first][order[i].second] = 6;
    }
    for (int i = 7; i < MAXN * MAXN; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            ans[order[i].first][order[i].second] += min(ans[order[i - j].first][order[i - j].second], ans[order[i - j].first - board[order[i - j].first][order[i - j].second]][order[i - j].second]);
        }
        ans[order[i].first][order[i].second] /= 6;
        ans[order[i].first][order[i].second]++;
    }
    cout << fixed << setprecision(7) << ans[MAXN - 1][0] << endl;
    return 0;
}