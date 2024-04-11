#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;
const int MAXN = 5E5;
int where[MAXN + 1];
int parent[MAXN + 1];
int sz[MAXN + 1];
int id[MAXN + 1];

int getRoot(int x)
{
    if (parent[x] != x)
        parent[x] = getRoot(parent[x]);
    return parent[x];
}

void mge(int x, int y)
{
    int r1 = getRoot(x);
    int r2 = getRoot(y);
    if (r1 == r2)
        return;
    if (sz[r1] < sz[r2])
        swap(r1, r2);
    parent[r2] = r1;
    sz[r1] += sz[r2];
    id[r1] = min(id[r1], id[r2]);
}

void add(int &x, int y)
{
    x += y;
    if (x >= MOD)
        x -= MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    fill(where + 1, where + m + 1, -1);
    fill(sz + 1, sz + m + 1, 1);
    for (int i = 1; i <= m; i++)
    {
        parent[i] = i;
        id[i] = i;
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        if (k == 1)
        {
            int x;
            cin >> x;
            x = id[getRoot(x)];
            if (where[x] == -1)
            {
                ans.push_back(i);
                where[x] = x;
            }
        }
        else
        {
            int x, y;
            cin >> x >> y;
            if (x > y)
                swap(x, y);
            while (y != -1 && where[y] != -1)
            {
                //int nxt = id[getRoot(y)];
                //if (nxt == y)
                if (where[y] == y)
                {
                    y = x;
                    x = -1;
                    continue;
                }
                y = id[getRoot(y)];
                if (x == y)
                {
                    x = y = -1;
                }
                if (x > y)
                    swap(x, y);
            }
            if (y != -1)
            {
                ans.push_back(i);
                if (x != -1)
                {
                    where[y] = x;
                    mge(x, y);
                }
                else
                    where[y] = y;
            }
        }
    }
    int two = 1;
    for (int i = 0; i < (int) ans.size(); i++)
    {
        add(two, two);
    }
    cout << two << " " << ans.size() << "\n";
    for (int x : ans)
        cout << x << " ";
    cout << "\n";
    return 0;
}