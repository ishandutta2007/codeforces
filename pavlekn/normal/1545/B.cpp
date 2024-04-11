#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;

int pw(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return a;
    }
    int cur = pw(a, n / 2);
    cur *= cur;
    cur %= mod;
    if (n % 2)
    {
        cur *= a;
        cur %= mod;
    }
    return cur;
}

int f(int n)
{
    int ans = 1;
    for (int i = 1; i <= n; ++i)
    {
        ans *= i;
        ans %= mod;
    }
    return ans;
}

int mul(int A, int B)
{
    return (A * B) % mod;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt = 0;
        int pr = 1;
        int num = 0;
        int x = n;
        for (auto el : s)
        {
            if (el == '0')
            {
                --x;
                ++cnt;
                int cur = num % 2;
                if (cur == pr)
                {
                    --x;
                }
                pr = cur;
            }
            ++num;
        }
        if (n % 2 == pr)
        {
            --x;
        }
        int y = x / 2 + cnt;
        int N = y;
        int K = cnt;
        int ANS = mul(mul(f(N), pw(f(K), mod - 2)), pw(f(N - K), mod - 2));
        cout << ANS << endl;
    }
    return 0;
}