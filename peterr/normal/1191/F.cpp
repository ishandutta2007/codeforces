#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2 * 1E5;
pair<int, int> points[MAXN];
int bit[MAXN + 1];
bool visited[MAXN + 1];

bool mycmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

int query(int x)
{
    int ans = 0;
    while (x > 0)
    {
        ans += bit[x];
        x -= (-x & x);
    }
    return ans;
}

void inc(int x, int amt)
{
    while (x <= MAXN)
    {
        bit[x] += amt;
        x += (-x & x);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].first >> points[i].second;
    }
    sort(points, points + n);
    int curX = points[0].first;
    int countt = 1;
    points[0].first = 1;
    swap(points[0].first, points[0].second);
    for (int i = 1; i < n; i++)
    {
        if (points[i].first != curX)
        {
            curX = points[i].first;
            countt++;
        }
        points[i].first = countt;
        swap(points[i].first, points[i].second);
    }
    sort(points, points + n, mycmp);
    int idx = 0;
    long long ans = 0;
    while (idx < n)
    {
        int curY = points[idx].first;
        int left = 1;
        long long overCount = 0;
        int amt = 0;
        while (idx < n && points[idx].first == curY)
        {
            amt = max(0, query(points[idx].second - 1) - query(left - 1));
            overCount += (long long) amt * (amt + 1) / 2;
            left = points[idx].second + 1;
            if (!visited[points[idx].second])
            {
                inc(points[idx].second, 1);
                visited[points[idx].second] = true;
            }
            idx++;
        }
        amt = max(0, query(MAXN) - query(left - 1));
        overCount += (long long) amt * (amt + 1) / 2;
        amt = query(MAXN);
        long long totalAmount = (long long) amt * (amt + 1) / 2;
        ans += totalAmount - overCount;
    }
    cout << ans;

    return 0;
}