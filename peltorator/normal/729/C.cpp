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

vector< pair<ll, ll> > a, b;
vector<ll> g;

int main()
{
    fastRead;
    ll n, k, s, t;
    cin >> n >> k >> s >> t;
    b.resize(n);
    for (ll i = 0; i < n; i++)
        cin >> b[i].fi >> b[i].se;
    sort(all(b));
    int MA = -1;
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i].se > MA)
        {
            a.push_back({b[i].se, b[i].fi});
            MA = b[i].se;
        }
    }
    sort(all(b));
    g.resize(k + 2);
    for (ll i = 0; i < k; i++)
        cin >> g[i];
    g[k] = 0;
    g[k + 1] = s;
    ll D = 0;
    sort(all(g));
    for (ll i = 0; i < g.size() - 1; i++)
        D = max(D, g[i + 1] - g[i]);
    ll l = -1, r = a.size();
    while (r - l > 1)
    {
        ll i = (r + l) / 2;
        if (D > a[i].fi)
        {
            l = i;
            continue;
        }
        ll time = 0;
        for (ll j = 0; j < g.size() - 1; j++)
        {
            ll x = g[j + 1] - g[j];
            ll p = min(x, a[i].fi - x);
            time += 2 * x - p;
        }
        if (time <= t)
            r = i;
        else
            l = i;
    }
    if (r == a.size())
        cout << -1;
    else
        cout << a[r].se;
    return 0;
}