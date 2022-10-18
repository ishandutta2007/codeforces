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
const int MAXN = 200001;
const int N = MAXN;
const ld eps = 1e-8;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int cnt[N];
ll fact[N];

ll binpow(ll x, ll y)
{
    if (!y)
        return 1;
    ll t = binpow(x, y / 2);
    t = (t * t) % MOD;
    if (y % 2)
        t = (t * x) % MOD;
    return t;
}

ll c(ll n, ll k)
{
    if (k < 0)
        return 0;
    if (n < k)
        return 0;
    return (((fact[n] * binpow(fact[k], MOD - 2)) % MOD) * binpow(fact[n - k], MOD - 2)) % MOD;
}

vector<int> a;

int main()
{
   // freopen("in.txt", "r", stdin);
    //fastRead;
    for (int i = 1; i <= 1010; i++)
    {
        int k = 0;
        int j = i;
        while (j != 1)
        {
            j = __builtin_popcount(j);
            k++;
        }
        cnt[i] = k;
    }
    string n;
    cin >> n;
    int k;
    cin >> k;
    if (!k)
    {
        cout << 1;
        return 0;
    }
    k--;
    for (int i = 1; i <= 1010; i++)
        if (cnt[i] == k)
            a.push_back(i);
    fact[0] = fact[1] = 1;
    for (int i = 2; i < N; i++)
        fact[i] = (fact[i - 1] * (ll)i) % MOD;
    ll ans = 0;
    int kek = 0;
    for (int i = 0; i < n.size(); i++)
        if (n[i] == '1')
            kek++;
    if (cnt[kek] == k)
        ans = 1;
    kek = 0;
    for (int i = 0; i < n.size(); i++)
        if (n[i] == '1')
        {
            for (int j = 0; j < a.size(); j++)
                ans = (ans + c((int)n.size() - i - 1, a[j] - kek)) % MOD;
            //cout << ans << endl;
            kek++;
        }
    if (k == 0)
        ans = (ans + MOD - 1) % MOD;
    cout << ans;
    return 0;
}