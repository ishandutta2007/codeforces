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

string intToStr1(ll n)
{
    return n ? intToStr1(n / 10) + (char)('0' + n % 10) : "";
}

string intToStr(ll n)
{
    return n ? intToStr(n) : "0";
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

vector<int> g[200001], used;

ll s = 0, sum1 = 0;

void dfs(int v)
{
    used[v] = 1;
    s++;
    for (int u : g[v])
        if (!used[u])
            dfs(u);
}

int main()
{
    fastRead;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int k, l;
        cin >> k >> l;
        g[k].push_back(l);
        g[l].push_back(k);
    }
    used.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (used[i])
            continue;
        s = 0;
        dfs(i);
        sum1 += s * (s - 1) / 2;
    }
    cout << (sum1 == m ? "YES" : "NO");
    return 0;
}