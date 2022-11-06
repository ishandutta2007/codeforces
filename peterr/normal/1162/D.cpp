#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
const int MAXM = 2E5;
unordered_set<int> adjList[MAXN + 1];

bool check(int k, int n)
{
    for (int i = 1; i <= n; i++)
    {
        int x = (i + k - 1) % n + 1;
        for (int j : adjList[i])
        {
            int y = (j + k - 1) % n + 1;

            if (adjList[x].find(y) == adjList[x].end())
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].insert(b);
        adjList[b].insert(a);
    }

    if (check(1, n))
    {
        cout << "Yes";
        return 0;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (check(i, n) || check(n / i, n))
            {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";

    return 0;
}