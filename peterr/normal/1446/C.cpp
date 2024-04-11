#include <bits/stdc++.h>

using namespace std;

int clz(int x)
{
    if (x)
        return __builtin_clz(x);
    return 32;
}

int msb(int x)
{
    return 31 - clz(x);
}

int solve(vector<int> &v)
{
    if ((int) v.size() <= 2)
        return (int) v.size();
    bool same = true;
    for (int i = 0; i < (int) v.size(); i++)
    {
        if (clz(v[i]) != clz(v[0]))
            same = false;
    }
    if (same)
    {
        for (int i = 0; i < (int) v.size(); i++)
        {
            v[i] ^= 1 << msb(v[i]);
        }
        return solve(v);
    }
    vector<int> freq(33, 0);
    for (int x : v)
    {
        freq[clz(x)]++;
    }
    int ans = 0;
    for (int i = 0; i < 33; i++)
    {
        int cnt = 0;
        vector<int> temp;
        bool below = false;
        vector<bool> used(33, false);
        for (int x : v)
        {
            if (clz(x) == i)
            {
                temp.push_back(x);
            }
            else if (clz(x) > i && !below)
            {
                cnt++;
                below = true;
            }
            else if (clz(x) < i && !used[clz(x)])
            {
                used[clz(x)] = true;
                cnt++;
            }
        }
        ans = max(ans, cnt + solve(temp));
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << n - solve(v) << "\n";
    return 0;
}