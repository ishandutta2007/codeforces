#include <bits/stdc++.h>

using namespace std;

const int INF = (int) 1E9;
const int MAXN = 2000;
string board[MAXN];
bool isFree[MAXN][MAXN];
int cost[MAXN * MAXN];

int getIndex(int r, int c, int m)
{
    return r * m + c;
}

void relax(int r, int c, int n, int m, int d, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> &pq)
{
    if (r < 0 || r >= n || c < 0 || c >= m)
        return;
    if (!isFree[r][c])
        return;
    int index = getIndex(r, c, m);
    if (cost[index] != INF)
        return;
    pq.push({d, index});
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, r, c, x, y;
    cin >> n >> m >> r >> c >> x >> y;
    r--;
    c--;
    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
        for (int j = 0; j < m; j++)
        {
            isFree[i][j] = board[i][j] == '.';
        }
    }
    for (int i = 0; i < n * m; i++)
        cost[i] = INF;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, getIndex(r, c, m)});
    while (!pq.empty())
    {
        pair<int, int> pr = pq.top();
        pq.pop();
        int d = pr.first;
        int index = pr.second;
        if (cost[index] != INF)
            continue;
        cost[index] = d;
        int curR = index / m;
        int curC = index % m;
        relax(curR + 1, curC, n, m, d, pq);
        relax(curR - 1, curC, n, m, d, pq);
        relax(curR, curC + 1, n, m, d + 1, pq);
        relax(curR, curC - 1, n, m, d + 1, pq);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!isFree[i][j])
                continue;
            //cout << i << " " << j << " " << cost[getIndex(i, j, m)] << endl;
            int right = 0;
            int left = 0;
            int curCost = cost[getIndex(i, j, m)];
            int offset = abs(j - c);
            right += (curCost - offset) / 2;
            left += (curCost - offset) / 2;
            if (j >= c)
            {
                right += offset;
            }
            else
            {
                left += offset;
            }
            if (left <= x && right <= y)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}