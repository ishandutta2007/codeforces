#include <bits/stdc++.h>

using namespace std;

const long long INF = 1E16;
const int MAXN = 5E5;
vector<int> pos[MAXN + 2];
int a[MAXN + 2];
int p[MAXN + 2];
int b[MAXN + 2];
long long dp[MAXN + 3];
long long bit[MAXN + 2];

void inc(int loc, int amt)
{
    if (loc == 0)
    {
        bit[loc] += amt;
        return;
    }
    while (loc < MAXN + 2)
    {
        bit[loc] += amt;
        loc += loc & -loc;
    }
}

long long query(int loc)
{
    long long ans = 0;
    while (loc)
    {
        ans += bit[loc];
        loc -= loc & -loc;
    }
    return ans + bit[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        if (p[i] < 0)
            inc(i, p[i]);
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    a[n + 1] = b[m + 1] = n + 1;
    pos[0].push_back(0);
    pos[n + 1].push_back(n + 1);
    n += 2;
    m += 2;
    deque<pair<long long, int>> q;
    q.push_front(make_pair(0LL, n));
    for (int i = n; i > b[m - 2]; i--)
    {
        for (int ind : pos[i])
        {
            if (p[ind] > 0)
                inc(ind, p[ind]);
        }
    }
    for (int i = m - 1; i >= 1; i--)
    {
        for (int ind : pos[b[i - 1]])
        {
            dp[ind + 1] = INF;
            while (!q.empty() && q.front().second < ind + 1)
                q.pop_front();
            if (!q.empty())
            {
                int ind2 = q.front().second;
                dp[ind + 1] = dp[ind2] + query(ind2 - 2) - query(ind);
                //cout << ind + 1 << " " << dp[ind + 1] << endl;
            }
        }
        if (i > 1)
        {
            for (int j = b[i - 1]; j > b[i - 2]; j--)
            {
                for (int ind : pos[j])
                {
                    if (p[ind] > 0)
                        inc(ind, p[ind]);
                }
            }
            deque<pair<long long, int>> temp;
            for (int ind : pos[b[i - 1]])
            {
                if (dp[ind + 1] == INF)
                    continue;
                long long cost = dp[ind + 1] + query(ind - 1);
                while (!temp.empty() && cost <= temp.back().first)
                    temp.pop_back();
                temp.push_back(make_pair(cost, ind + 1));
            }
            q = temp;
        }
    }
    if (dp[1] == INF)
        cout << "NO\n";
    else
        cout << "YES\n" << dp[1] << "\n";
    return 0;
}