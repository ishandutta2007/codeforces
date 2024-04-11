#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 2e18;

int32_t main()
{
    int RR = 18;
    int t;
    cin >> t;
    int l, r;
    vector<pair<int, int>> a;
    map<int, int> ans;
    vector<int> q;
    for (int i = 0; i < t; ++i)
    {
        cin >> l >> r;
        a.push_back({l, r + 1});
        q.push_back(l);
        q.push_back(r + 1);
    }
    sort(q.begin(), q.end());
    vector<int> ten(RR + 1);
    ten[0] = 1;
    for (int i = 1; i <= RR; ++i)
    {
        ten[i] = 10 * ten[i - 1];
    }
    set<int> s;
    for (int i = 0; i <= RR; ++i)
    {
        for (int j = i + 1; j <= RR; ++j)
        {
            for (int k = j + 1; k <= RR; ++k)
            {
                int res = 0;
                for (int a = 0; a < 10; ++a)
                {
                    for (int b = 0; b < 10; ++b)
                    {
                        for (int c = 0; c < 10; ++c)
                        {
                            res = ten[i] * a + ten[j] * b + ten[k] * c;
                            s.insert(res);
                        }
                    }
                }
            }
        }
    }
    s.insert(INF);
    int pos = 0;
    int i1 = 0;
    for (auto el : s)
    {
        while (i1 < q.size() && el >= q[i1])
        {
            ans[q[i1]] = pos;
            ++i1;
        }
        ++pos;
    }
    for (int i = 0; i < t; ++i)
    {
        cout << ans[a[i].second] - ans[a[i].first] << endl;
    }
}