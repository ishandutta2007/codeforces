#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int x[MAXN];
int y[MAXN];
unordered_set<int> visited;
queue<pair<int, int>> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    visited.reserve(1 << 20);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        q.push({0, x[i]});
        visited.insert(x[i]);
    }
    for (int i = 0; i < n; i++)
    {
        int v = q.front().second;
        q.pop();
        if (visited.find(v + 1) == visited.end())
        {
            visited.insert(v + 1);
            q.push({1, v + 1});
        }
        if (visited.find(v - 1) == visited.end())
        {
            visited.insert(v - 1);
            q.push({1, v - 1});
        }
    }
    long long ans = 0;
    for (int i = 0; i < m; i++)
    {
        y[i] = q.front().second;
        int d = q.front().first;
        q.pop();
        int v = y[i];
        if (visited.find(v + 1) == visited.end())
        {
            visited.insert(v + 1);
            q.push({d + 1, v + 1});
        }
        if (visited.find(v - 1) == visited.end())
        {
            visited.insert(v - 1);
            q.push({d + 1, v - 1});
        }
        ans += d;
    }
    stringstream ss;
    ss << ans << endl;
    for (int i = 0; i < m; i++)
    {
        if (i > 0)
            ss << " ";
        ss << y[i];
    }
    ss << endl;
    cout << ss.str();
    return 0;
}