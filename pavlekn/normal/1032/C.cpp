#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

const int MAXN = 2e3 + 7;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); srand(clock());
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int p = -1;
    vector<int> ans(n);
    int pr = -1;
    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i + 1] > a[i])
        {
            if (p == -1 && pr == -1)
            {
                ans[i] = 1;
            }
            else
            {
                if (pr == 0 && p == 1)
                {
                    ans[i] = 2;
                }
                else if (pr == 0)
                {
                    ans[i] = 1;
                }
                if (pr == -1)
                {
                    if (p == 1)
                    {
                        cout << -1 << endl;
                        return 0;
                    }
                    ans[i] = 1;
                }
                if (pr == 1)
                {
                    if (p == 5)
                    {
                        cout << -1 << endl;
                        return 0;
                    }
                    ans[i] = p + 1;
                }
            }
            pr = 1;
        }
        else if (a[i + 1] < a[i])
        {
            if (p == -1 && pr == -1)
            {
                ans[i] = 5;
            }
            else
            {
                if (pr == 0 && p == 5)
                {
                    ans[i] = 4;
                }
                else if (pr == 0)
                {
                    ans[i] = 5;
                }
                if (pr == -1)
                {
                    if (p == 1)
                    {
                        cout << -1 << endl;
                        return 0;
                    }
                    ans[i] = p - 1;
                }
                if (pr == 1)
                {
                    if (p == 5)
                    {
                        cout << -1 << endl;
                        return 0;
                    }
                    ans[i] = 5;
                }
            }
            pr = -1;
        }
        else
        {
            if (p == -1)
            {
                ans[i] = 3;
            }
            else if (pr == -1)
            {
                ans[i] = p - 1;
            }
            else if (pr == 1)
            {
                ans[i] = p + 1;
            }
            else
            {
                ans[i] = 3;
                if (p == 3)
                {
                    ++ans[i];
                }
            }
            pr = 0;
        }
        if (ans[i] == 0 || ans[i] == 6)
        {
            cout << -1 << endl;
            return 0;
        }
        p = ans[i];
    }
    int i = n - 1;
    if (pr == 0)
    {
        ans[i] = 3;
        if (p == 3)
        {
            ans[i] = 4;
        }
    }
    if (pr == 1)
    {
        ans[i] = p + 1;
    }
    if (pr == -1)
    {
        ans[i] = p - 1;
    }
    if (p == -1)
    {
        ans[i] = 1;
    }
    if (ans[i] < 1 || ans[i] > 5)
    {
        cout << -1 << endl;
        return 0;
    }
    for (auto el : ans)
    {
        cout << el << " ";
    }
    cout << endl;
    return 0;
}