#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
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
const int MAXN = 200001;
const int N = MAXN;
const ld eps = 1e-8;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

vector<ll> a;

pair<int, int> dp[N];
int pref[N];

int main()
{
  //  freopen("in.txt", "r", stdin);
    fastRead;
    int n;
    cin >> n;
    string s;
    cin >> s;
    pref[1] = (s[0] == '?' ? 1 : 0);
    for (int i = 2; i <= n; i++)
        pref[i] = pref[i - 1] + (s[i - 1] == '?' ? 1 : 0);
    int m;
    cin >> m;
    int an = n, bn = n, ac = n, bc = n;
    for (int i = n - 1; i >= 0; i--)
    {
        int r;
        if (i % 2)
        {
            r = min(bn, ac) - i;
            if (s[i] == 'a')
                an = i;
            else if (s[i] == 'b')
                bn = i;
        }
        else
        {
            r = min(an, bc) - i;
            if (s[i] == 'a')
                ac = i;
            else if (s[i] == 'b')
                bc = i;
        }
        if (s[i] != 'b' && r >= m)
            dp[i] = make_pair(dp[i + m].first + 1, dp[i + m].second - (pref[i + m] - pref[i]));
        dp[i] = max(dp[i], dp[i + 1]);
    }
    pair<int, int> best = dp[0];
    cout << -best.second << endl;
  //  cout << best.first;
    cout << endl;
    return 0;
}