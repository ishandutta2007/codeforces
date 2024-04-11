#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

int a[MAXN];
int b[MAXN];
int c[MAXN];
int d[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<pair<int, int>, pair<int, int>>> op;
    vector<pair<pair<int, int>, pair<int, int>>> cl;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        op.push_back({{a[i], i}, {c[i], d[i]}});
        cl.push_back({{b[i], i}, {c[i], d[i]}});
    }
    set<pair<int, int>> l;
    set<pair<int, int>> r;
    sort(op.begin(), op.end());
    sort(cl.begin(), cl.end());
    int i = 0;
    int j = 0;
    string ans = "YES";
    while (i < op.size() || j < cl.size())
    {
        if ((j == cl.size()) || (i < op.size() && op[i].first.first <= cl[j].first.first))
        {
            l.insert({-op[i].second.first, op[i].first.second});
            r.insert({op[i].second.second, op[i].first.second});
            int p = -l.begin()->first;
            int q = r.begin()->first;
            if (p > q)
            {
                ans = "NO";
            }
            ++i;
        }
        else
        {
            l.erase({-cl[j].second.first, cl[j].first.second});
            r.erase({cl[j].second.second, cl[j].first.second});
            ++j;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        swap(a[i], c[i]);
        swap(b[i], d[i]);
    }
    op = {};
    cl = {};
    l = {};
    r = {};
    for (int i = 0; i < n; ++i)
    {
        op.push_back({{a[i], i}, {c[i], d[i]}});
        cl.push_back({{b[i], i}, {c[i], d[i]}});
    }
    sort(op.begin(), op.end());
    sort(cl.begin(), cl.end());
    i = 0;
    j = 0;
    while (i < op.size() || j < cl.size())
    {
        if ((j == cl.size()) || (i < op.size() && op[i].first.first <= cl[j].first.first))
        {
            l.insert({-op[i].second.first, op[i].first.second});
            r.insert({op[i].second.second, op[i].first.second});
            int p = -l.begin()->first;
            int q = r.begin()->first;
            if (p > q)
            {
                ans = "NO";
            }
            ++i;
        }
        else
        {
            l.erase({-cl[j].second.first, cl[j].first.second});
            r.erase({cl[j].second.second, cl[j].first.second});
            ++j;
        }
    }
    cout << ans << endl;
    return 0;
}