#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;

int a[MAXN];
int t[MAXN];

void inc(int r)
{
    for (int i = r; i < MAXN; ++t[i], i += i & -i);
}

int get(int r)
{
    int ans = 0;
    for (int i = r; i > 0; i -= i & -i)
    {
        ans += t[i];
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> b(n + 1);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        a[i] = min(a[i], n);
        b[min(i, a[i])].push_back(i);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (auto el : b[i])
        {
            ans += i - get(el);
        }
        inc(a[i]);
    }
    cout << ans << endl;
    return 0;
}