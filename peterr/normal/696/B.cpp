#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
vector<int> children[MAXN + 1];
int s[MAXN + 1];
long double timee[MAXN + 1];

void build(int cur)
{
    s[cur] = 1;
    for (int child : children[cur])
    {
        build(child);
        s[cur] += s[child];
    }
}

void solve(int cur)
{
    long double totalSize = s[cur] - 1;
    for (int child : children[cur])
    {
        timee[child] += timee[cur];
        timee[child] += (totalSize - s[child]) / 2 + 1;
        solve(child);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int p;
        cin >> p;
        children[p].push_back(i);
    }
    build(1);
    timee[1] = 1;
    solve(1);
    for (int i = 1; i <= n; i++)
    {
        cout << fixed << setprecision(7) << timee[i] << " ";
    }

    return 0;
}