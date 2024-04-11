#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[2][MAXN];
bool visited[MAXN];
vector<int> where[MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            where[i].clear();
        }
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
                where[a[i][j]].push_back(j);
            }
        }
        bool valid = true;
        for (int i = 1; i <= n; i++)
        {
            if ((int) where[i].size() != 2)
            {
                valid = false;
                break;
            }
        }
        if (!valid)
        {
            cout << "-1\n";
            continue;
        }
        vector<int> cols;
        fill(visited, visited + n, false);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                continue;
            vector<int> t1;
            vector<int> t2;
            int num = a[1][i];
            int node = i;
            while (!visited[node])
            {
                visited[node] = true;
                if (a[1][node] == num)
                    t2.push_back(node);
                else
                    t1.push_back(node);
                if (where[num][0] != node)
                    node = where[num][0];
                else
                    node = where[num][1];
                if (num != a[0][node])
                    num = a[0][node];
                else
                    num = a[1][node];
            }
            if ((int) t1.size() > (int) t2.size())
                swap(t1, t2);
            ans += (int) t1.size();
            for (int x : t1)
                cols.push_back(x);
        }
        cout << ans << "\n";
        for (int x : cols)
            cout << x + 1 << " ";
        cout << "\n";
    }
    return 0;
}