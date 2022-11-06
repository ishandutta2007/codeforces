#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
int received[MAXN + 1];
int a[MAXN + 1];
pair<int, int> ans[MAXN + 1];
int timee[MAXN + 10];
int bitt[MAXN + 10];
bool visited[MAXN + 1];

int query(int pos, int bit[MAXN + 10])
{
    int ans = 0;
    while (pos)
    {
        ans += bit[pos];
        pos -= pos & -pos;
    }
    return ans;
}

void update(int pos, int amt, int bit[MAXN + 10])
{
    while (pos <= MAXN + 9)
    {
        bit[pos] += amt;
        pos += pos & -pos;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
        received[a[i]] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        ans[i].first = received[i] ? 1 : i;
        ans[i].second = i;
    }
    fill(received + 1, received + n + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        if (received[a[i]] == 0)
        {
            if (a[i] != n)
            {
                int suf = query(n, bitt) - query(a[i], bitt);
                ans[a[i]].second = max(ans[a[i]].second, a[i] + suf);
            }
            update(a[i], 1, bitt);
            update(i, 1, timee);
        }
        else
        {
            update(received[a[i]], -1, timee);
            if (received[a[i]] + 1 != i)
            {
                int between = query(i - 1, timee) - query(received[a[i]], timee);
                ans[a[i]].second = max(ans[a[i]].second, between + 1);
            }
            update(i, 1, timee);
        }
        received[a[i]] = i;
    }
    int cnt = 0;
    for (int i = m; i >= 1; i--)
    {
        if (!visited[a[i]])
        {
            visited[a[i]] = true;
            cnt++;
            ans[a[i]].second = max(ans[a[i]].second, cnt);
            if (cnt == n)
                break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cnt++;
            ans[i].second = max(ans[i].second, cnt);
        }
    }
    stringstream ss;
    for (int i = 1; i <= n; i++)
        ss << ans[i].first << " " << ans[i].second << endl;
    cout << ss.str();
    return 0;
}