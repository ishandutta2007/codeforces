#include<bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e6 + 5;

const int mod = 2e9 + 87;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> d(n);
    vector<pair<int, int>> ans;
    vector<int> p(2 * n + 1);
    vector<int> pt(2 * n + 1);
    vector<int> ind(2 * n + 1);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> d[i].first;
        d[i].second = i;
    }
    sort(d.begin(), d.end());
    reverse(d.begin(), d.end());
    for (int i = 0; i < n; ++i)
    {
        a[i] = d[i].second * 2 + 1;
        ind[a[i]] = i;
    }
    for (int i = 1; i < n; ++i)
    {
        ans.push_back({d[i - 1].second * 2 + 1, d[i].second * 2 + 1});
        p[d[i].second * 2 + 1] = d[i - 1].second * 2 + 1;
        pt[d[i - 1].second * 2 + 1] = d[i].second * 2 + 1;
    }
    ans.push_back({d[0].second * 2 + 2, d[d[0].first - 1].second * 2 + 1});
    p[d[0].second * 2 + 2] = d[d[0].first - 1].second * 2 + 1;
    int len = d[0].first;
    int root = d[d[0].first - 1].second * 2 + 1;
    for (int i = 1; i < n; ++i)
    {
        if (ind[root] >= i)
        {
            --len;
        }
        else
        {
            ++len;
        }
        int v = d[i - 1].second * 2 + 2;
        while (len > d[i].first - 1)
        {
            --len;
            if (v == root)
            {
                if (ind[root] >= i)
                {
                    v = p[v];
                    root = v;
                }
                else
                {
                    v = pt[v];
                    root = v;
                }
            }
            else
            {
                v = p[v];
            }
        }
        ++len;
        p[d[i].second * 2 + 2] = v;
        ans.push_back({v, d[i].second * 2 + 2});
    }
    for (auto el : ans)
    {
        cout << el.first << " " << el.second << endl;
    }
    return 0;
}