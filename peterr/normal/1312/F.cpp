#include <bits/stdc++.h>

using namespace std;

const int MAXM = 1E3;
const int MAXN = 3E5;
long long a[MAXN];

int mex(int a1, int a2, int a3)
{
    for (int i = 0; i < 4; i++)
    {
        if (a1 == i || a2 == i || a3 == i)
            continue;
        return i;
    }
    return -1;
}

int gett(int x, int pos)
{
    x >>= pos * 2;
    x &= 3;
    return x;
}

int getGrundy(long long x, vector<int> &states, int mod, int pos)
{
    if (x <= MAXM)
        return states[x];
    return states[pos + (x - MAXM) % mod];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y, z;
        cin >> n >> x >> y >> z;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> states;
        states.push_back(0);
        for (int i = 1; i <= MAXM; i++)
        {
            int cur = 0;
            int a1 = gett(states[max(0, i - x)], 0);
            int a2 = gett(states[max(0, i - y)], 1);
            int a3 = gett(states[max(0, i - z)], 2);
            cur += mex(a1, a2, a3);
            cur += mex(a1, a3, -1) * 4;
            cur += mex(a1, a2, -1) * 16;
            states.push_back(cur);
            //cout << i << " " << cur << endl;
        }
        int len = max(max(x, y), z);
        int pos = 0;
        int mod = 0;
        for (int i = MAXM - 1; i >= 0; i--)
        {
            bool flag = true;
            for (int k = 0; k < len; k++)
            {
                if (states[MAXM - k] != states[i - k])
                    flag = false;
            }
            if (flag)
            {
                mod = MAXM - i;
                pos = i;
                break;
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum ^= gett(getGrundy(a[i], states, mod, pos), 0);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            sum ^= gett(getGrundy(a[i], states, mod, pos), 0);
            long long newA = max(0LL, a[i] - x);
            if ((sum ^ gett(getGrundy(newA, states, mod, pos), 0)) == 0)
                ans++;
            newA = max(0LL, a[i] - y);
            if ((sum ^ gett(getGrundy(newA, states, mod, pos), 1)) == 0)
                ans++;
            newA = max(0LL, a[i] - z);
            if ((sum ^ gett(getGrundy(newA, states, mod, pos), 2)) == 0)
                ans++;
            sum ^= gett(getGrundy(a[i], states, mod, pos), 0);
        }
        cout << ans << endl;
    }
    return 0;
}