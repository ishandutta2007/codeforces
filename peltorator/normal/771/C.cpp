#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld;

#define fastRead cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define fi first
#define se second

ll nod(ll a, ll b)
{
    return __gcd(a, b);
}

ll nok(ll a, ll b)
{
    return a / __gcd(a, b) * b;
}

ll sum(vector<ll> v)
{
    ll ans = 0;
    for (ll i = 0; i < v.size(); i++)
        ans += v[i];
    return ans;
}

bool letter(char c)
{
    return 'a' <= c && c <= 'z';
}

bool LETTER(char c)
{
    return 'A' <= c && c <= 'Z';
}

string llToStr1(ll n)
{
    return n ? llToStr1(n / 10) + (char)('0' + n % 10) : "";
}

string llToStr(ll n)
{
    return n ? llToStr(n) : "0";
}

ll strToll(string s)
{
    ll ans = 0;
    for (ll i = 0; i < s.size(); i++)
        ans = 10 * ans + (s[i] - '0');
    return ans;
}

bool digit(char c)
{
    return '0' <= c && c <= '9';
}

bool prime(ll n)
{
    if (n == 1)
        return 0;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

const ld zero = 0;
const ll null = 0;
const ll INF = 1e18;
const ll MOD = 1000000007;
const ld PI = atan2(0, -1);
const ll MAXN = 200001;
const ld eps = 1e-8;
const ll dx[4] = {-1, 0, 1, 0};
const ll dy[4] = {0, 1, 0, -1};

vector<ll> g[200001], used;
vector<vector<ll>> dp, dp1;

ll ans = 0;

ll k, n;

ll dfs(ll v)
{
    used[v] = 1;
    for (ll u : g[v])
    {
        if (used[u])
            continue;
        dfs(u);
        for (ll i = 0; i < k; i++)
            for (ll j = 0; j < k; j++)
                dp1[v][(i + j + 1) % k] += dp[v][i] * dp[u][j];
        for (ll i = 0; i < k; i++)
            dp[v][(i + 1) % k] += dp[u][i];
    }
    dp[v][0]++;
    return 0;
}

ll dfs1(ll v)
{
    used[v] = 1;
    ll sum1 = 1;
    for  (ll u : g[v])
        if (!used[u])
        {
            ll x = dfs1(u);
            sum1 += x;
            ans += x * (n - x);
        }
    return sum1;
}

vector<ll> ost;

int main()
{
    fastRead;
    cin >> n >> k;
    used.assign(n + 1, 0);
    dp.assign(n + 1, vector<ll>(k, 0));
    dp1.assign(n + 1, vector<ll>(k, 0));
    for (ll i = 1; i < n; i++)
    {
        ll k, l;
        cin >> k >> l;
        g[k].push_back(l);
        g[l].push_back(k);
    }
    dfs(1);
    used.assign(n + 1, 0);
    dfs1(1);
    ost.assign(k, 0);
    for (ll i = 1; i <= n; i++)
        for (ll j = 0; j < k; j++)
            ost[j] += dp[i][j] + dp1[i][j];
    for (ll i = 1; i < k; i++)
        ans += ost[i] * (k - i);
    cout << ans / k << endl;
    return 0;
}