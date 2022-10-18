#ifdef ONPC
    # define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) (int)(a).size()


#include <bits/stdc++.h>

using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

const int N = 4e5;
const int INF = 1e9 + 7;
int dp[N];
int cnt[N];

ll gcd(ll a, ll b)
{
    while (a)
    {
        b %= a;
        swap(a, b);
    }
    return b;
}

int solve()
{
    int m;
    if (!(cin >> m))
        return 1;
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < N; i++)
        dp[i] = INF, cnt[i] = 0;
    dp[0] = 0;
    set<pair<int, int>> q;
    q.insert({0, 0});
    while (q.size())
    {
        int v = q.begin()->second;
        q.erase(q.begin());
        if (v >= b && dp[v - b] > dp[v])
        {
            q.erase({dp[v - b], v - b});
            dp[v - b] = dp[v];
            q.insert({dp[v - b], v - b});
        }
        if (v + a < N && dp[v + a] > max(v + a, dp[v]))
        {
            q.erase({dp[v + a], v + a});
            dp[v + a] = max(dp[v], v + a);
            q.insert({dp[v + a], v + a});
        }
    }
    for (int i = 0; i < N; i++)
        if (dp[i] != INF)
            cnt[dp[i]]++;
    for (int i = 1; i < N; i++)
        cnt[i] += cnt[i - 1];
    ll ans = 0;
    for (int i = 0; i <= min(m, N - 1); i++)
        ans += cnt[i];
    ll t = gcd(a, b);
    if (m - N < 1e6)
    {
        for (int i = N; i <= m; i++)
            ans += i / t;
    }
    else
    {
        ll l = N;
        while (l % t)
        {
            ans += l / t;
            l++;
        }
        ll r = m;
        while (r % t != t - 1)
        {
            ans += r / t;
            r--;
        }
        l /= t;
        r /= t;
        ans += (r * (r + 1) / 2LL - l * (l - 1) / 2LL) * t;
    }
    ans += max(m - N + 1, 0);
    cout << ans << endl;
    return 0;
}

int32_t main()
{
#ifdef ONPC
    freopen("out", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    //cin >> TET;
    while (TET--)
    {
        if (solve())
            break;
        #ifdef ONPC
            cout << "\n__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}