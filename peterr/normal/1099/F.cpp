#include <bits/stdc++.h>

using namespace std;

const int LEN = (int) 1E6;
const int MAXN = (int) 1E5;
int cookies[MAXN + 1];
int timee[MAXN + 1];
vector<int> adjList[MAXN + 1];
int dist[MAXN + 1];
long long maxCookies[MAXN + 1];
long long cookieTimeBit[LEN + 1];
long long numCookiesBit[LEN + 1];

int binSearch(long long bit[LEN + 1], long long target)
{
    int ans = 0;
    for (int i = 19; i >= 0; i--)
    {
        if (ans + (1 << i) <= LEN && bit[ans + (1 << i)] <= target)
        {
            target -= bit[ans + (1 << i)];
            ans += (1 << i);
        }
    }
    return ans;
}

long long query(long long bit[LEN + 1], int pos)
{
    long long ans = 0;
    while (pos > 0)
    {
        ans += bit[pos];
        pos -= pos & -pos;
    }
    return ans;
}

void inc(long long bit[LEN + 1], int pos, long long amt)
{
    while (pos <= LEN)
    {
        bit[pos] += amt;
        pos += pos & -pos;
    }
}

void calcMaxCookies(int cur, int par, long long t)
{
    inc(numCookiesBit, timee[cur], cookies[cur]);
    inc(cookieTimeBit, timee[cur], (long long) cookies[cur] * timee[cur]);
    int maxTime = binSearch(cookieTimeBit, t);
    long long countCookies = query(numCookiesBit, maxTime);
    if (maxTime < LEN)
    {
        countCookies += (t - query(cookieTimeBit, maxTime)) / (maxTime + 1);
    }
    maxCookies[cur] = countCookies;
    for (int adj : adjList[cur])
    {
        if (adj != par)
        {
            calcMaxCookies(adj, cur, t - 2 * dist[adj]);
        }
    }
    inc(numCookiesBit, timee[cur], -cookies[cur]);
    inc(cookieTimeBit, timee[cur], (long long) -cookies[cur] * timee[cur]);
}

long long solve(int cur, int par)
{
    long long max1 = -1, max2 = -1;
    for (int adj : adjList[cur])
    {
        if (adj != par)
        {
            long long childAns = solve(adj, cur);
            if (childAns > max1)
            {
                max2 = max1;
                max1 = childAns;
            }
            else if (childAns > max2)
            {
                max2 = childAns;
            }
        }
    }
    if (cur == 1)
        return max(maxCookies[cur], max1);
    else
        return max(maxCookies[cur], max2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long t;
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> cookies[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> timee[i];
    }
    for (int i = 2; i <= n; i++)
    {
        int p, l;
        cin >> p >> l;
        adjList[i].push_back(p);
        adjList[p].push_back(i);
        dist[i] = l;
    }
    calcMaxCookies(1, 1, t);
    /*
    for (int i = 1; i <= n; i++)
        cout << i << ": " << maxCookies[i] << " cookies" << endl;
    */
    cout << solve(1, 1) << endl;
    return 0;
}