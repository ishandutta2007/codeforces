#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
    int n, m;
    cin >> n >> m;
    vector<pair<int , int>> a(n + m); for (int o = 0; o < n + m; o++) { cin >> a[o].first; }
    for (int o = 0; o < n + m; o++) { cin >> a[o].second; }
    sort(a.begin(), a.end());
    std::vector<int> p(n + m, -1);
    std::vector<int> dr;
    dr.pb(-1000000000);
    for (int i = 0; i < n + m; ++i)
    {
        if (a[i].second == 1)
        {
            dr.pb(a[i].first);
        }
    }
    dr.pb(2000000000);
    std::vector<int> pr(m, 0);
    for (int i = 0; i < n + m; ++i)
    {
        if (a[i].second == 0)
        {
            int justu = (upper_bound(dr.begin(), dr.end(), a[i].first) - dr.begin());
            if ((dr[justu] - a[i].first) >= (a[i].first - dr[justu - 1]))
            {
                justu--;
            }
            justu--;
            pr[justu]++;
        }
    }
    for (int i = 0; i < m; ++i)
    {
        cout << pr[i] << " ";
    }
    cout << "\n";
}