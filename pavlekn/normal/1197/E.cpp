#include<bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e18;

bool cmp(pair<int, int> & a, pair<int, int> & b)
{
    return a.second > b.second;
}

const int MAXN = 3e5 + 25;

const int mod = 1e9 + 7;

int mn[MAXN];
int cnt[MAXN];

int32_t main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), cmp);
    vector<int> in(n);
    vector<int> out(n);
    for (int i = 0; i < n; ++i)
    {
        out[i] = a[i].first;
        in[i] = a[i].second;
    }
    for (int i = 0; i < n; ++i)
    {
        int l = -1;
        int r = i;
        while (r - l > 1)
        {
            int m = (l + r) / 2;
            if (in[m] >= out[i])
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        if (l == -1)
        {
            mn[i] = in[i];
            cnt[i] = 1;
        }
        else
        {
            mn[i] = mn[l] - (out[i] - in[i]);
            cnt[i] = cnt[l];
        }
        if (i > 0)
        {
            if (mn[i] == mn[i - 1])
            {
                cnt[i] += cnt[i - 1];
                cnt[i] %= mod;
            }
            if (mn[i] > mn[i - 1])
            {
                mn[i] = mn[i - 1];
                cnt[i] = cnt[i - 1];
            }
        }
    }
    cout << cnt[n - 1] % mod << endl;
    return 0;
}