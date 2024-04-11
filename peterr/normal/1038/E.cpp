#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int deg[5];
int adjMat[5][5];
vector<int> edges[5][5];
bool visited[5];

void dfs(int v)
{
    visited[v] = true;
    for (int i = 1; i <= 4; i++)
    {
        if (!visited[i] && adjMat[v][i])
            dfs(i);
    }
}

int main()
{
    int n;
    cin >> n;
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        int c1, v, c2;
        cin >> c1 >> v >> c2;
        if (c1 > c2)
            swap(c1, c2);
        deg[c1]++;
        deg[c2]++;
        adjMat[c1][c2]++;
        adjMat[c2][c1]++;
        edges[c1][c2].push_back(v);
        total += v;
    }
    int ans = 0;
    for (int i = 1; i <= 4; i++)
    {
        int sum = 0;
        for (int x : edges[i][i])
            sum += x;
        ans = max(ans, sum);
    }
    for (int i = 1; i <= 4; i++)
    {
        for (int j = i + 1; j <= 4; j++)
        {
            if (adjMat[i][j])
            {
                int sum = 0;
                for (int x : edges[i][i])
                    sum += x;
                for (int x : edges[j][j])
                    sum += x;
                for (int x : edges[i][j])
                    sum += x;
                ans = max(ans, sum);
            }
        }
    }
    for (int i = 1; i <= 4; i++)
    {
        for (int j = i + 1; j <= 4; j++)
        {
            for (int k = j + 1; k <= 4; k++)
            {
                fill(visited + 1, visited + 5, false);
                dfs(i);
                if (visited[j] && visited[k])
                {
                    int sum = 0;
                    for (int x : edges[i][j])
                        sum += x;
                    for (int x : edges[j][k])
                        sum += x;
                    for (int x : edges[i][k])
                        sum += x;
                    for (int x : edges[i][i])
                        sum += x;
                    for (int x : edges[j][j])
                        sum += x;
                    for (int x : edges[k][k])
                        sum += x;
                    ans = max(ans, sum);
                }
            }
        }
    }
    fill(visited + 1, visited + 5, false);
    dfs(1);
    if (visited[2] && visited[3] && visited[4])
    {
        int odds = 0;
        for (int i = 1; i <= 4; i++)
            if (deg[i] % 2 != 0)
                odds++;
        if (odds <= 2)
        {
            ans = total;
        }
        else
        {
            for (int i = 1; i <= 4; i++)
            {
                for (int j = i; j <= 4; j++)
                {
                    sort(edges[i][j].begin(), edges[i][j].end());
                }
            }
            for (int i = 1; i <= 4; i++)
            {
                for (int j = i + 1; j <= 4; j++)
                {
                    if (adjMat[i][j] == 0)
                        continue;
                    adjMat[i][j]--;
                    adjMat[j][i]--;
                    fill(visited + 1, visited + 5, false);
                    dfs(1);
                    if (visited[1] && visited[2] && visited[3] && visited[4])
                    {
                        ans = max(ans, total - edges[i][j][0]);
                    }
                    adjMat[i][j]++;
                    adjMat[j][i]++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}