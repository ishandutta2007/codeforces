#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
const int MOD = 998244353;
vector<pair<int, int>> events;
int fac[MAXN + 1];
int invFac[MAXN + 1];

int modpow(int b, int e)
{
    int ans = 1;
    while (e)
    {
        if (e & 1)
            ans = (int) ((long long) ans * b % MOD);
        e >>= 1;
        b = (int) ((long long) b * b % MOD);
    }
    return ans;
}

int modinv(int x)
{
    return modpow(x, MOD - 2);
}

int choose(int n, int k)
{
    if (k > n)
        return 0;
    int ans = (int) ((long long) fac[n] * invFac[k] % MOD);
    return (int) ((long long) ans * invFac[n - k] % MOD);
}

int main()
{
    fac[0] = invFac[0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        fac[i] = (int) ((long long) i * fac[i - 1] % MOD);
        invFac[i] = modinv(fac[i]);
    }
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        events.push_back(make_pair(l, -i));
        events.push_back(make_pair(r, i));
    }
    sort(events.begin(), events.end());
    int ptr = 0;
    int cnt = 0;
    int ans = 0;
    while (ptr < (int) events.size())
    {
        int t = events[ptr].first;
        while (ptr < (int) events.size() && events[ptr].first == t && events[ptr].second < 0)
        {
            ans += choose(cnt, k - 1);
            if (ans >= MOD)
                ans -= MOD;
            cnt++;
            ptr++;
        }
        while (ptr < (int) events.size() && events[ptr].first == t && events[ptr].second > 0)
        {
            ptr++;
            cnt--;
        }
    }
    cout << ans << "\n";
    return 0;
}