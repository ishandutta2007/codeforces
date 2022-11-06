#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
pair<int, int> a[MAXN];
pair<int, int> b[MAXN];
int dx[MAXN];
int dy[MAXN];
int g[MAXN];

long long cross(int x1, int y1, int x2, int y2)
{
    return (long long) x1 * y2 - (long long) x2 * y1;
}

int side(int ind, int qx, int qy)
{
    long long c = cross(dx[ind], dy[ind], qx - b[ind].first, qy - b[ind].second);
    if (c > 0)
        return 1;
    else if (c < 0)
        return -1;
    return 0;
}

bool inRect(int x1, int y1, int x2, int y2, int qx, int qy)
{
    return qx >= min(x1, x2) && qx <= max(x1, x2) && qy >= min(y1, y2) && qy <= max(y1, y2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second >> b[i].first >> b[i].second;
        dx[i] = b[i].first - a[i].first;
        dy[i] = b[i].second - a[i].second;
        if (dx[i] && dy[i])
            g[i] = __gcd(dx[i], dy[i]);
        else if (dx[i])
            g[i] = dx[i];
        else
            g[i] = dy[i];
        g[i] = abs(g[i]);
        ans += g[i] + 1;
    }
    set<pair<int, int>> seen;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            pair<int, int> inter;
            if (a[i] == a[j] || a[i] == b[j])
                inter = a[i];
            else if (b[i] == a[j] || b[i] == b[j])
                inter = b[i];
            else if (side(j, a[i].first, a[i].second) == side(j, b[i].first, b[i].second))
                continue;
            else
            {
                if (side(j, a[i].first, a[i].second) == 0)
                    inter = a[i];
                else if (side(j, b[i].first, b[i].second) == 0)
                    inter = b[i];
                else
                {
                    int sidea = side(j, a[i].first, a[i].second);
                    int ind = 0;
                    for (int jump = g[i]; jump; jump >>= 1)
                    {
                        while (ind + jump < g[i] && side(j, a[i].first + dx[i] / g[i] * (ind + jump), a[i].second + dy[i] / g[i] * (ind + jump)) == sidea)
                            ind += jump;
                    }
                    ind++;
                    inter = make_pair(a[i].first + dx[i] / g[i] * ind, a[i].second + dy[i] / g[i] * ind);
                    if (side(j, inter.first, inter.second) != 0)
                        continue;
                }
                if (!inRect(a[j].first, a[j].second, b[j].first, b[j].second, inter.first, inter.second))
                    continue;
            }
            if (!seen.count(inter))
            {
                seen.insert(inter);
                ans--;
            }
        }
        seen.clear();
    }
    cout << ans << "\n";
    return 0;
}