#include<bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;
int INF = 3e16;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    if (k == 1)
    {
        cout << "! 1" << endl;
        return 0;
    }
    set<int> s;
    for (int i = 0; i < k - 1; ++i)
    {
        s.insert(i);
    }
    set<pair<int, int>> used;
    vector<int> u(n);
    for (int i = k - 1; i < n; ++i)
    {
        s.insert(i);
        cout << "? ";
        for (auto el : s)
        {
            cout << el + 1 << " ";
        }
        cout << endl;
        int pos, val;
        cin >> pos >> val;
        --pos;
        u[pos] = true;
        s.erase(pos);
        used.insert({val, pos});
    }
    auto it = used.begin();
    auto it2 = used.rbegin();
    vector<int> res;
    for (int i = 0; i < n; ++i)
    {
        if (!u[i])
        {
            res.push_back(i);
        }
    }
    int ans = 0;
    for (int i = 0; i < res.size(); ++i)
    {
        cout << "? ";
        for (int j = 0; j < res.size(); ++j)
        {
            if (i == j)
            {
                continue;
            }
            cout << res[j] + 1 << " ";
        }
        cout << it->second + 1 << " " << it2->second + 1;
        cout << endl;
        int pos, val;
        cin >> pos >> val;
        if (val == it2->first)
        {
            ++ans;
        }
    }
    cout << "! " << ans + 1 << endl;
    return 0;
}