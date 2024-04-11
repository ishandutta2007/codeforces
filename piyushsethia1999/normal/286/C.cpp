#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
    int n; cin >> n;
    vector<int> p(n); for (int o = 0; o < n; o++) { cin >> p[o]; }
    int t; cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int x; cin >> x; x--;
        p[x] = -p[x];
    }
    int i = n;
    stack<pair<int, int> > s;
    while (i-- > 0)
        if (s.empty())
            s.push({p[i], i});
        else if (s.top().first < 0 && (p[i] + s.top().first == 0))
            s.pop();
        else if (p[i] > 0 && s.top().first == p[i])
            p[s.top().second] = -p[s.top().second], s.pop();
        else
            s.push({p[i], i});
    if (s.empty())
    {
        cout << "YES\n";
        for (int i = 0; i < n; ++i)
            cout << p[i] << " ";
    }
    else
        cout << "NO\n";
}