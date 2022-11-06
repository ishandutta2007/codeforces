#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;
const int MAXN = 5000;
int s[MAXN + 1];
int pre[MAXN + 1][MAXN + 1];
vector<int> cows[MAXN + 1];
int solve(int pos, int n, int best)
{
    int hunger = 0;
    int f = s[pos];
    for (int i = 1; i <= pos; i++)
    {
        if (s[i] == f)
            hunger++;
    }
    bool valid = false;
    for (int x : cows[f])
    {
        if (x == hunger)
            valid = true;
    }
    if (!valid)
        return 0;
    int cnt = 1;
    int y = 0;
    for (int x : cows[f])
    {
        if (x != hunger && x <= pre[f][n] - pre[f][pos])
            y++;
    }
    if (y)
        cnt++;
    int ans = max(1, y);
    for (int i = 1; i <= n; i++)
    {
        if (i == f)
            continue;
        int left = pre[i][pos];
        int right = pre[i][n] - left;
        if ((int) cows[i].size() >= 2 && min(cows[i][0], cows[i][1]) <= min(left, right) && max(cows[i][0], cows[i][1]) <= max(left, right))
        {
            cnt += 2;
            int a, b;
            a = b = 0;
            for (int x : cows[i])
            {
                if (x <= left)
                    a++;
                if (x <= right)
                    b++;
            }
            if (a > b)
                swap(a, b);
            int temp = (int) (((long long) a * (b - 1)) % MOD);
            ans = (int) (((long long) ans * temp) % MOD);
        }
        else if ((int) cows[i].size() >= 1 && cows[i][0] <= max(left, right))
        {
            cnt++;
            int num = 0;
            for (int x : cows[i])
            {
                if (x <= left)
                    num++;
                if (x <= right)
                    num++;
            }
            ans = (int) (((long long) ans * num) % MOD);
        }
    }
    return ans * (cnt == best);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            pre[i][j] = pre[i][j - 1] + (s[j] == i);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int f, h;
        cin >> f >> h;
        cows[f].push_back(h);
    }
    for (int i = 1; i <= n; i++)
        sort(cows[i].begin(), cows[i].end());
    int best = 0;
    for (int i = 0; i <= n; i++)
    {
        int temp = 0;
        for (int j = 1; j <= n; j++)
        {
            int left = pre[j][i];
            int right = pre[j][n] - left;
            if ((int) cows[j].size() >= 2 && min(cows[j][0], cows[j][1]) <= min(left, right) && max(cows[j][0], cows[j][1]) <= max(left, right))
            {
                temp += 2;
            }
            else if ((int) cows[j].size() >= 1 && cows[j][0] <= max(left, right))
            {
                temp++;
            }
        }
        best = max(best, temp);
    }
    int ans = 0;
    int cnt = 0;
    int temp = 1;
    for (int i = 1; i <= n; i++)
    {
        int y = 0;
        for (int x : cows[i])
        {
            if (x <= pre[i][n])
            {
                y++;
            }
        }
        if (y == 0)
            continue;
        temp = (int) (((long long) temp * y) % MOD);
        if (y)
            cnt++;
    }
    if (cnt == best)
        ans += temp;
    for (int i = 1; i <= n; i++)
    {
        ans += solve(i, n, best);
        if (ans >= MOD)
            ans -= MOD;
    }
    cout << best << " " << ans << endl;
    return 0;
}