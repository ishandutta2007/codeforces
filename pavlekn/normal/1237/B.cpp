#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> pos(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        --a[i];
        pos[a[i]] = i;
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
        --b[i];
        b[i] = pos[b[i]];
    }
    set<int> s;
    for (int i = 0; i < n; ++i)
    {
        s.insert(i);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if ((*s.begin()) < b[i])
        {
            ++ans;
        }
        s.erase(s.find(b[i]));
    }
    cout << ans << endl;
    return 0;
}