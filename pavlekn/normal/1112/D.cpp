#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 2e18;

const int MAXN = 5003;

int mod;
int prime;

int p[MAXN];
int pr[MAXN];
int dp[MAXN];

int my_hash(int l, int r)
{
    int ans = pr[r] - pr[l];
    if (ans < 0)
    {
        ans += mod;
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(clock());
    vector<int> mods = {(int)1e9 + 7442, (int)1e9 + 9123, (int)2e9 + 123};
    vector<int> primes = {31, 37, 41, 43, 47, 53, 59, 61, 73, 79, 83, 89, 101};
    mod = mods[rand() % mods.size()];
    prime = primes[rand() % primes.size()];
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    p[0] = 1;
    for (int i = 0; i < n; ++i)
    {
        p[i + 1] = (p[i] * prime) % mod;
    }
    pr[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        pr[i + 1] = (pr[i] + p[i + 1] * (s[i] - 'a' + 1)) % mod;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = INF;
    }
    for (int i = 0; i < n; ++i)
    {
        int k = 0;
        for (int j = 0; j < i; ++j)
        {
            int l = 0;
            int r = min(n - i + 1, i - j + 1);
            while (r - l > 1)
            {
                int m = (l + r) / 2;
                if ((my_hash(j, j + m) * p[i - j]) % mod == my_hash(i, i + m))
                {
                    l = m;
                }
                else
                {
                    r = m;
                }
            }
            k = max(k, l);
        }
        dp[i + 1] = min(dp[i + 1], dp[i] + a);
        for (int j = i; j < i + k; ++j)
        {
            dp[j + 1] = min(dp[j + 1], dp[i] + b);
        }
    }
    cout << dp[n] << endl;
    return 0;
}