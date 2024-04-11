#include <bits/stdc++.h>

using namespace std;

bool visited[4];
pair<int, int> pts[4];
vector<vector<pair<int, int>>> perm;
pair<int, int> cur[4];
long long dx[4];
long long dy[4];

void genPerms(int ind)
{
    if (ind == 4)
    {
        perm.push_back(vector<pair<int, int>>());
        for (int i = 0; i < 4; i++)
            perm.back().push_back(cur[i]);
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            if (visited[i])
                continue;
            visited[i] = true;
            cur[ind] = pts[i];
            genPerms(ind + 1);
            visited[i] = false;
        }
    }
}

long long solve(vector<pair<int, int>>& v, int side)
{
    long long ans = 0;
    int x = v[0].first;
    int y = v[0].second;
    long long dx_min = 1E15;
    long long dy_min = 1E15;
    long long dx_max = -1E15;
    long long dy_max = -1E15;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (i == 0 && j == 0)
                continue;
            int ind = i * 2 + j;
            long long newx = x + j * side;
            long long newy = y + i * side;
            dx[ind] = v[ind].first - newx;
            dy[ind] = v[ind].second - newy;
            dx_min = min(dx_min, dx[ind]);
            dy_min = min(dy_min, dy[ind]);
            dx_max = max(dx_max, dx[ind]);
            dy_max = max(dy_max, dy[ind]);
        }
    }
    if (dx_min > 0)
    {
        ans += dx_min;
        for (int i = 1; i < 4; i++)
            dx[i] -= dx_min;
    }
    if (dy_min > 0)
    {
        ans += dy_min;
        for (int i = 1; i < 4; i++)
            dy[i] -= dy_min;
    }
    if (dx_max < 0)
    {
        ans += -dx_max;
        for (int i = 1; i < 4; i++)
            dx[i] -= dx_max;
    }
    if (dy_max < 0)
    {
        ans += -dy_max;
        for (int i = 1; i < 4; i++)
            dy[i] -= dy_max;
    }
    for (int i = 1; i < 4; i++)
    {
        ans += abs(dx[i]) + abs(dy[i]);
    }
    return ans;
}

long long solve(vector<pair<int, int>>& v)
{
    int x = v[0].first;
    int y = v[0].second;
    int avg = abs((v[3].first - x + v[3].second - y) / 2);
    long long ans = 1E15;
    for (int i = -4; i <= 4; i++)
    {
        if (avg + i < 0)
            continue;
        ans = min(ans, solve(v, avg + i));
    }
    vector<int> sides;
    ans = min(ans, solve(v, abs(v[1].first - x)));
    ans = min(ans, solve(v, abs(v[2].second - y)));
    sides.push_back(max(v[2].second, v[3].second) + (y - v[1].second) - y);
    sides.push_back(min(v[2].second, v[3].second) + (y - v[1].second) - y);
    sides.push_back(max(v[1].first, v[3].first) + (x - v[2].first) - x);
    sides.push_back(min(v[1].first, v[3].first) + (x - v[2].first) - x);
    for (int s : sides)
        ans = min(ans, solve(v, abs(s)));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        perm.clear();
        for (int i = 0; i < 4; i++)
        {
            cin >> pts[i].first >> pts[i].second;
        }
        genPerms(0);
        /*
        vector<pair<int, int>> temp;
        for (int i = 0; i < 4; i++)
        {
            temp.push_back(pts[i]);
        }
        perm.push_back(temp);
        */
        long long ans = 1E15;
        for (vector<pair<int, int>> p : perm)
        {
            ans = min(ans, solve(p));
        }
        cout << ans << "\n";
    }
    return 0;
}