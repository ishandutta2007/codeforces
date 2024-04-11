#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 75;

int a[MAXN];
int pr[MAXN];

const int mod = 2e9 + 179;
const int p = 3;

int p1[MAXN];
int h[MAXN];
int h2[MAXN];

int get_hash(int l, int r, int m)
{
    if (m == 0)
    {
        int ans = h[r] - h[l] * p1[r - l];
        ans %= mod;
        if (ans < 0)
        {
            ans += mod;
        }
        return ans;
    }
    else
    {
        int ans = h2[r] - h2[l] * p1[r - l];
        ans %= mod;
        if (ans < 0)
        {
            ans += mod;
        }
        return ans;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    p1[0] = 1;
    for (int i = 1; i < MAXN; ++i)
    {
        p1[i] = (p1[i - 1] * p) % mod;
    }
    pr[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        pr[i + 1] = pr[i];
        if (s[i] == '1')
        {
            pr[i + 1]++;
        }
    }
    int cur = 0;
    vector<int> a;
    vector<int> zero;
    for (int i = 0; i < n; ++i)
    {
        cur += (s[i] - '0');
        if (s[i] == '0')
        {
            a.push_back(cur % 2);
            zero.push_back(i);
        }
    }
    h[0] = 0;
    h2[0] = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        h[i + 1] = ((h[i] * p + (a[i] + 1)) % mod + mod) % mod;
        h2[i + 1] = ((h2[i] * p + ((1 - a[i]) + 1)) % mod + mod) % mod;
    }
    int q;
    cin >> q;
    for (int _ = 0; _ < q; ++_)
    {
        int l1, l2, len;
        cin >> l1 >> l2 >> len;
        --l1; --l2;
        int l = -1;
        int r = zero.size();
        while (r - l > 1)
        {
            int med = (l + r) / 2;
            if (zero[med] >= l1)
            {
                r = med;
            }
            else
            {
                l = med;
            }
        }
        int st1 = r;
        l = -1;
        r = zero.size();
        while (r - l > 1)
        {
            int med = (l + r) / 2;
            if (zero[med] >= l2)
            {
                r = med;
            }
            else
            {
                l = med;
            }
        }
        int st2 = r;
        l = -1;
        r = zero.size();
        while (r - l > 1)
        {
            int med = (l + r) / 2;
            if (zero[med] < l1 + len)
            {
                l = med;
            }
            else
            {
                r = med;
            }
        }
        int end1 = r;
        l = -1;
        r = zero.size();
        while (r - l > 1)
        {
            int med = (l + r) / 2;
            if (zero[med] < l2 + len)
            {
                l = med;
            }
            else
            {
                r = med;
            }
        }
        int end2 = r;
        if (get_hash(st1, end1, pr[l1] % 2) == get_hash(st2, end2, pr[l2] % 2))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}