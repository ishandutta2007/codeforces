#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef long long ll;
typedef double ld;

#define fastRead cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define fi first
#define se second

ll nod1(ll a, ll b)
{
    return a ? nod1(b % a, a) : b;
}

ll nod(ll a, ll b)
{
    if (a > b)
        swap(a, b);
    return nod1(a, b);
}

ll nok(ll a, ll b)
{
    return a / nod(a, b) * b;
}

ll sum(vector<int> v)
{
    ll ans = 0;
    for (int i = 0; i < v.size(); i++)
        ans += v[i];
    return ans;
}

ll sum(vector<ll> v)
{
    ll ans = 0;
    for (int i = 0; i < v.size(); i++)
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

ll strToInt(string s)
{
    ll ans = 0;
    for (int i = 0; i < s.size(); i++)
        ans = 10 * ans + (s[i] - '0');
    return ans;
}

bool digit(char c)
{
    return '0' <= c && c <= '9';
}

bool prime(int n)
{
    if (n == 1)
        return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

const ld zero = 0;
const ll null = 0;
const ll INF = 1e18;
const ll MOD = 1000000007;
const ld PI = atan2(0, -1);
const int MAXN = 22;
const int MAXK = (1 << 22);
const ld eps = 1e-8;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

//vector<ll> a;

int d[MAXN];
int f[MAXN];

int used[MAXN][MAXN];
int a[MAXN];
int dp[MAXK];

int main()
{
   // freopen("in.txt", "r", stdin);
    fastRead;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        d[x] |= (1 << y);
        used[x][y] = used[y][x] = (1 << n) - 1;
        d[y] |= (1 << x);
    }
    for (int i = 0; i < n; i++)
        d[i] |= (1 << i);
    dp[0] = 0;
    for (int i = 1; i < (1 << n); i++)
    {
        int v = 0;
        while (((1 << v) & i) == 0)
            v++;
        dp[i] = (dp[(i ^ (1 << v))] | d[v]);
    }
   // cout << dp[1] << endl;
    if (m == n * (n - 1) / 2)
    {
        cout << 0;
        return 0;
    }
    int B = (1 << n);
    int ans = n;
    int T = B - 1;
    int ansmask = T;
    for (int mask = 1; mask < B; mask++)
    {
    //    for (int i = 0; i < n; i++)
     //       f[i] = d[i];//(d[i] & mask);
        int v = 0;
        for (int i = 0; i < n; i++)
            if ((mask & (1 << i)))
                v = i;
        /*int sz = 1;
        a[0] = v;
        int cur = (1 << v);
        int pos = 0;
        while (pos < sz)
        {
            int u = a[pos++];

        }*/
        int cur = (1 << v);
        for (int i = 0; i <= n; i++)
            cur = (dp[cur] & mask);
            /*for (int j = 0; j < n; j++)
                if ((mask & cur & (1 << j)))
                    cur |= d[j];*/
        /*bool ok = true;
        for (int i = 0; i < n; i++)
            if (f[i] != T)
                ok = false;
        bool ok = true;
        if (f[v] != T)
            ok = false;*/
        if (dp[cur] == T)
        {
            int cur = __builtin_popcount(mask);
            if (ans > cur)
            {
                ans = cur;
                ansmask = mask;
            }
        }
    }
    cout << ans << "\n";
    for (int i = 0; i < n; i++)
        if ((ansmask & (1 << i)))
            cout << i + 1 << " ";
    cout << endl;
    return 0;
}