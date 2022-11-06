#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E4;
long long added[MAXN][1001];
int d[MAXN];
vector<int> mod[1001];

void process(int g, long long dist, int m, int loc1, int loc2, vector<int> &v)
{
    if (loc2 < 0 || loc2 >= m)
        return;
    long long newDist = dist + abs(d[loc1] - d[loc2]);
    if (newDist % g == 0)
    {
        if (dist / g != newDist / g - 1)
            return;
    }
    else
    {
        if (dist / g != newDist / g)
            return;
    }
    if (added[loc2][newDist % g] == -1)
    {
        added[loc2][newDist % g] = newDist;
        mod[newDist % g].push_back(loc2);
        if (newDist % g == 0)
            v.push_back(loc2);
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> d[i];
    sort(d, d + m);
    int g, r;
    cin >> g >> r;
    for (int i = 0; i < m; i++)
        fill(added[i], added[i] + g, -1);
    long long ans = -1;
    vector<int> v;
    v.push_back(0);
    added[0][0] = 0;
    while (!v.empty())
    {
        for (int x : v)
            mod[0].push_back(x);
        v.clear();
        for (int i = 0; ans == -1 && i < g; i++)
        {
            for (int x : mod[i])
            {
                if (x == m - 1)
                {
                    ans = added[x][i];
                    break;
                }
                process(g, added[x][i], m, x, x + 1, v);
                process(g, added[x][i], m, x, x - 1, v);
            }
        }
        if (ans != -1)
            break;
        for (int i = 0; i < g; i++)
            mod[i].clear();
    }
    if (ans == -1)
        cout << -1 << endl;
    else
    {
        long long reds = (ans - 1) / g;
        cout << ans + reds * r << endl;
    }
    return 0;

}