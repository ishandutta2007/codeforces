#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2 * 1e5;
const int MAX_K = (int) log2(MAX_N) + 2;
const int MAX_X = 5 * 1e5 + 1;
int n, m;
pair<int, int> intervals[MAX_N];
int nxt[MAX_X][MAX_K];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p;
        cin >> p.first >> p.second;
        intervals[i] = p;
    }

    sort(intervals, intervals + n);
    int index = 0;
    for (int i = 0; i < MAX_X; i++)
    {
        if (i > 0 && nxt[i-1][0] > i)
            nxt[i][0] = nxt[i-1][0];
        else
            nxt[i][0] = -1;
        while (index < n && intervals[index].first == i)
        {
            nxt[i][0] = max(nxt[i][0], intervals[index].second);
            index++;
        }
    }

    for (int k = 1; k < MAX_K; k++)
    {
        for (int i = 0; i < MAX_X; i++)
        {
            if (nxt[i][k-1] == -1)
                nxt[i][k] = -1;
            else
                nxt[i][k] = nxt[nxt[i][k-1]][k-1];
        }
    }

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        if (nxt[x][0] == -1)
        {
            cout << -1 << endl;
        }
        else
        {
            int steps = 0;
            while (nxt[x][0] != -1 && nxt[x][0] < y)
            {
                int i = 0;
                while (i + 1 < MAX_K && nxt[x][i + 1] != -1 && nxt[x][i + 1] < y)
                {
                    i++;
                }
                x = nxt[x][i];
                steps += 1 << i;
            }
            if (nxt[x][0] >= y)
                cout << (steps + 1) << endl;
            else
                cout << -1 << endl;
        }
    }

    return 0;
}