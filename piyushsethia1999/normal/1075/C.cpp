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
    vector<int> vert(n); for (int o = 0; o < n; o++) { cin >> vert[o]; }
    sort(vert.begin(), vert.end());
    vert.pb(1000000000);
    vert.pb(1000000001);
    std::vector<int> u(n + 2, 0);
    int start = 0;
    for (int i = 0; i < m; ++i)
    {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        if (x1 == 1)
        {
            start++;
            int xx = (upper_bound(vert.begin(), vert.end(), x2) - vert.begin());
            u[xx]++;
        }
    }
    int mm = start;
    for (int i = 0; i < n + 1; ++i)
    {
        start -= u[i];
        mm = min(mm, start + i);
    }
    cout << mm ;
}