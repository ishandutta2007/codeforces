#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000;
bool visited[MAXN + 1];
int comp[MAXN + 1];
int parent[MAXN + 1];
int s[MAXN + 1];
vector<int> marks[MAXN + 1];

int getRoot(int a)
{
    if (parent[a] != a)
        parent[a] = getRoot(parent[a]);
    return parent[a];
}

void mge(int a, int b, int &trees)
{
    int r1 = getRoot(a);
    int r2 = getRoot(b);
    if (r1 == r2)
        return;
    trees--;
    if (s[r1] > s[r2])
        swap(r1, r2);
    parent[r1] = r2;
    s[r2] += s[r1];
}

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < q; i++)
    {
        int r, c;
        cin >> r >> c;
        marks[c].push_back(r);
        visited[r] = true;
    }
    for (int i = 1; i <= m; i++)
    {
        parent[i] = i;
        s[i] = 1;
    }
    int trees = m;
    for (int i = 1; i <= m; i++)
    {
        for (int r : marks[i])
        {
            if (comp[r] == 0)
            {
                comp[r] = i;
            }
            else
            {
                mge(i, comp[r], trees);
            }
        }
    }
    int ans = trees - 1;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            ans++;
    }
    cout << ans << endl;
    return 0;
}