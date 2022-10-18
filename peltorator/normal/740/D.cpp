#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <time.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stdlib.h>
#include <deque>
#include <iomanip>
#include <complex>
#include <cassert>
#include <math.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define _GLIBCXX_DEBUG
#define fastRead cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(v) v.begin(), v.end()
#define randInt ((rand() << 15) | rand())
#define For(i, n) for (int i = 0; i < n; i++)
#define whatIs(x) cerr << #x << " is " << x << endl
#define in(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)
#define mp(x, y) make_pair(x, y)
#define fi first
#define se second

int gcd(int a, int b)
{
    return a ? gcd(b % a, a) : b;
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

string int_to_str_easy(ll n)
{
    return n ? int_to_str_easy(n / 10) + (char)('0' + n % 10) : "";
}

long long sum(vector<int> v)
{
    int ans = 0;
    For(i, v.size())
        ans += v[i];
    return ans;
}

bool prime(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

bool letter(char c)
{
    return 'a' <= c && c <= 'z';
}
bool LETTER(char c)
{
    return 'A' <= c && c <= 'Z';
}
bool digit(char c)
{
    return ('0' <= c && c <= '9');
}

const ld pi = 3.141592653589793238462643383279;
const ld eps = 1e-8;
const ld zero = 0;
const ll null = 0;
const ll INF = 1e18;
//const int INF = 1e9;
const ll MOD = 1000000007;
const int BIG = 1e9;
const int alf = 26;
const int MAXN = 200001;
const int MAXM = 1001;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

vector<pair<int, ll> > g[200001];
vector<ll> a, d, l, cur, ans;

int dfs(int v)
{
    cur.push_back(v);
    int tau = 0;
    for (int i = 0; i < g[v].size(); i++)
    {
        int u = g[v][i].first;
        d[u] = d[v] + g[v][i].second;
        tau += dfs(u);
    }
    int le = -1, ri = cur.size() - 1;
    while (ri - le > 1)
    {
        int med = (ri + le) / 2;
        if (d[v] - d[cur[med]] <= a[v])
            ri = med;
        else
            le = med;
    }
    ans[v] = tau;
    if (cur[ri] != v)
    {
        l[cur[ri]]++;
        tau++;
    }
    cur.pop_back();
    return tau - l[v];
}

int main()
{
    fastRead;
    int n;
    cin >> n;
    a.resize(n + 1);
    d.resize(n + 1, 1e16);
    l.resize(n + 1, 0);
    ans.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n; i++)
    {
        int k, w;
        cin >> k >> w;
        g[k].push_back({i, w});
    }
    d[1] = 0;
    dfs(1);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}