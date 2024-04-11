#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const ll inf = 1e18 + 7;

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n;
    cin >> n;
    int me = n;
    vector <int> a;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            a.push_back(i);
            n /= i;
        }
    }
    if (n != 1) a.push_back(n);
    if (a.size() == 1)
    {
        cout << "NO\n";
        return 0;
    }
    else
    {
        n = me;
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
        int ret = *min_element(a.begin(), a.end());
        vector <ll> dist(ret, inf);
        vector <int> par(ret, -1);
        vector <int> who(ret, -1);
        dist[0] = 0;
        int op = (n - 1) % ret;
        set <pair <ll, int> > q;
        q.insert({dist[0], 0});
        while (!q.empty())
        {
            int v = q.begin()->second;
            q.erase(q.begin());
            for (int t : a)
            {
                int u = (v + t) % ret;
                if (dist[u] > dist[v] + t)
                {
                    q.erase({dist[u], u});
                    par[u] = v;
                    who[u] = t;
                    dist[u] = dist[v] + t;
                    q.insert({dist[u], u});
                }
            }
        }
        if (dist[op] <= n - 1)
        {
            vector <pair <int, int> > ans;
            {
                int ret = op;
                while (ret != 0)
                {
                    ans.push_back({1, who[ret]});
                    ret = par[ret];
                }
            }
            int cnt = ((n - 1) - dist[op]) / ret;
            ans.push_back({cnt, ret});
            cout << "YES\n";
            cout << ans.size() << '\n';
            for (auto c : ans)
            {
                cout << c.first << ' ' << n / c.second << '\n';
            }
        }
        else
        {
            cout << "NO\n";
        }
    }
}