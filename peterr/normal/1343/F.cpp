#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200;
int s[MAXN];
int a[MAXN][MAXN];
bool mat[MAXN + 1][MAXN];
int freq[MAXN + 1];
int ans[MAXN];

bool solve(int n, int start, int end)
{
    int ind = n - 1;
    vector<int> vec;
    vec.push_back(end);
    priority_queue<pair<int, vector<int>>> pq;
    pq.push(make_pair(ind, vec));
    while (ind >= 1)
    {
        while (pq.top().first > ind)
            pq.pop();
        vector<int> cur = pq.top().second;
        end = 0;
        for (int x : cur)
        {
            if (x == start)
                continue;
            if (freq[x] == 1)
                end = x;
        }
        if (end == 0)
            return false;
        for (int i = 0; i < n - 1; i++)
        {
            if (mat[end][i])
            {
                vector<int> v;
                for (int j = 1; j <= n; j++)
                {
                    if (mat[j][i])
                    {
                        mat[j][i] = false;
                        freq[j]--;
                        v.push_back(j);
                    }
                }
                pq.push(make_pair(ind - (int) v.size() + 1, v));
            }
        }
        ans[ind--] = end;
    }
    ans[0] = start;
    return true;
}

void reset(int n)
{
    fill(freq + 1, freq + n + 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < s[i]; j++)
        {
            mat[a[i][j]][i] = true;
            freq[a[i][j]]++;
        }
    }
}

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
            fill(mat[i], mat[i] + n, false);
        fill(freq + 1, freq + n + 1, 0);
        int x, y;
        x = y = 0;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> s[i];
            for (int j = 0; j < s[i]; j++)
            {
                cin >> a[i][j];
                freq[a[i][j]]++;
                mat[a[i][j]][i] = true;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (freq[i] == 1)
            {
                if (x == 0)
                    x = i;
                else
                    y = i;
            }
        }
        //swap(x, y);
        bool found = false;
        for (int i = 1; i <= n; i++)
        {
            if (i == x)
                continue;
            if (solve(n, i, x))
            {
                found = true;
                break;
            }
            reset(n);
        }
        if (!found)
        {
            for (int i = 1; i <= n; i++)
            {
                if (i == y)
                    continue;
                if (solve(n, i, y))
                {
                    found = true;
                    break;
                }
                reset(n);
            }
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] << " \n"[i == n - 1];
    }
    return 0;
}