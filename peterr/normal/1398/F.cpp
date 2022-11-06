#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E6;
int nextOne[MAXN + 1];
int nextZero[MAXN + 1];
vector<int> out[MAXN + 1];
int parent[MAXN + 1];
int sz[MAXN + 1];
int ans[MAXN + 1];
int mx[MAXN + 1];
bool visited[MAXN];

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
    if (sz[r1] > sz[r2])
        swap(r1, r2);
    sz[r2] += sz[r1];
    parent[r1] = r2;
    mx[r2] = max(mx[r2], mx[r1]);
}

int getMax(int x)
{
    return mx[getRoot(x)];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    cin >> n >> s;
    nextOne[n] = nextZero[n] = n;
    for (int i = n - 1; i >= 0; i--)
    {
        nextOne[i] = nextOne[i + 1];
        nextZero[i] = nextZero[i + 1];
        if (s[i] == '1')
            nextOne[i] = i;
        else if (s[i] == '0')
            nextZero[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        int last = max(nextOne[i], nextZero[i]);
        out[last - i].push_back(i);
    }
    for (int i = 0; i <= n; i++)
    {
        parent[i] = mx[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        int j = 0;
        while (j < n)
        {
            j = getMax(j);
            if (j < n)
            {
                ans[i]++;
                j += i;
            }
        }
        for (int x : out[i])
        {
            mge(x, x + 1);
            if (x && visited[x - 1])
                mge(x, x - 1);
            visited[x] = true;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
    return 0;
}