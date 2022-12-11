#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod1 = 998244353;
const int mod2 = 2e9 + 179;

const int b1 = 777;
const int b2 = 179;

const int MAXN = 1e6 + 7;

int p1[MAXN];
int p2[MAXN];

int h1[MAXN];
int h2[MAXN];

int get_hash1(int l, int r)
{
    int ans = h1[r] - h1[l] * p1[r - l];
    ans %= mod1;
    if (ans < 0)
    {
        ans += mod1;
    }
    return ans;
}

string s;

bool check(int l, int r)
{
    string t = s.substr(l, r - l);
    string a = t;
    reverse(t.begin(), t.end());
    return a == t;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    p1[0] = 1;
    p2[0] = 1;
    for (int i = 1; i < MAXN; ++i)
    {
        p1[i] = (p1[i - 1] * b1) % mod1;
        p2[i] = (p2[i - 1] * b2) % mod2;
    }
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        cin >> s;
        int n = s.size();
        int ans = 0;
        int cnt = 0;
        while (cnt < n && s[cnt] == s[n - cnt - 1])
        {
            ++cnt;
        }
        int cc = 0;
        int l1 = 0;
        int r1 = 0;
        for (int i = 0; i < n; ++i)
        {
            int l = 0;
            int r = min(i, n - i) + 1;
            while (r - l > 1)
            {
                int med = (l + r) / 2;
                if (check(i - med, i + med + 1))
                {
                    l = med;
                }
                else
                {
                    r = med;
                }
            }
            if (cnt >= min(i - l, n - (i + l + 1)) && ans < min(i, n - i - 1) * 2 + 1)
            {
                ans = max(ans, min(i, n - i - 1) * 2 + 1);
                cc = min(i - l, n - (i + l + 1));
                l1 = i - l;
                r1 = i + l + 1;
            }
            l = 0;
            r = min(i, n - i + 1) + 1;
            while (r - l > 1)
            {
                int med = (l + r) / 2;
                if (check(i - med, i + med))
                {
                    l = med;
                }
                else
                {
                    r = med;
                }
            }
            if (cnt >= min(i - l, n - (i + l)) && ans < min(i, n - i) * 2)
            {
                ans = max(ans, min(i, n - i) * 2);
                cc = min(i - l, n - (i + l));
                l1 = i - l;
                r1 = i + l;
            }
        }
        string tt;
        for (int i = 0; i < cc; ++i)
        {
            tt.push_back(s[i]);
        }
        for (int i = l1; i < r1; ++i)
        {
            tt.push_back(s[i]);
        }
        for (int i = n - cc; i < n; ++i)
        {
            tt.push_back(s[i]);
        }
        cout << tt << endl;
    }
    return 0;
}