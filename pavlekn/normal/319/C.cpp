#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e6 + 7;

int a[MAXN];
int b[MAXN];
int dp[MAXN];

const int INF = 1e9 + 118;

struct Line
{
    int k, m;
    Line() {}
    Line(int _k, int _m)
    {
        k = _k;
        m = _m;
    }
};

vector<int> pr;
vector<Line> lines;

int get(int x)
{
    int l = upper_bound(pr.begin(), pr.end(), x) - pr.begin() - 1;
    return lines[l].k * x + lines[l].m;
}

int cross(Line la, Line lb)
{
    return (lb.m - la.m) / (la.k - lb.k);
}

void upd(Line line)
{
    while (lines.size() && cross(line, lines.back()) < pr.back())
    {
        pr.pop_back();
        lines.pop_back();
    }
    int cur;
    if (lines.empty())
    {
        cur = -INF;
    }
    else
    {
        cur = cross(line, lines.back());
    }
    pr.push_back(cur);
    lines.push_back(line);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }
    upd(Line(b[0], 0));
    for (int i = 1; i < n; ++i)
    {
        dp[i] = get(a[i]);
        upd(Line(b[i], dp[i]));
    }
    cout << dp[n - 1] << endl;
    return 0;
}