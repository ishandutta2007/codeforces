#include<bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;

int f(vector<int> & a)
{
    int res = 1;
    int cur = 1;
    int cc = 1;
    int n = a.size();
    for (int i = 1; i < n; ++i)
    {
        if (a[i] == a[i - 1])
        {
            ++cc;
            cur *= cc;
            cur %= mod;
        }
        else
        {
            res *= cur;
            res %= mod;
            cur = 1;
            cc = 1;
        }
    }
    res *= cur;
    res %= mod;
    return res;
}

int32_t main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i];
        a[i] = x[i] * (n + 1) + y[i];
    }
    int ans = 1;
    for (int i = 2; i <= n; ++i)
    {
        ans *= i;
        ans %= mod;
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(a.begin(), a.end());
    for (int i = 1; i < n; ++i)
    {
        if (a[i] % (n + 1) < a[i - 1] % (n + 1))
        {
            ans -= f(a);
            break;
        }
    }
    ans += f(a) - f(x) - f(y);
    ans %= mod;
    ans += mod;
    ans %= mod;
    cout << ans << endl;
    return 0;
}