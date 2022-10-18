#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld;

#define fastRead cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define fi first
#define se second

int nod1(int a, int b)
{
    return a ? nod1(b % a, a) : b;
}

int nod(int a, int b)
{
    if (a > b)
        swap(a, b);
    return nod1(a, b);
}

int nok(int a, int b)
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
const ld eps = 1e-8;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

vector<ll> a, p, b;

set<pair<ll, int>> q[4];

int main()
{
    fastRead;
    ll n;
    cin >> n;
    p.resize(n);
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
    {
        q[a[i]].insert({p[i], b[i]});
        if (a[i] != b[i])
            q[b[i]].insert({p[i], a[i]});
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        ll x;
        cin >> x;
        if (q[x].empty())
        {
            cout << -1 << endl;
            continue;
        }
        auto z = q[x].begin();
        if (z->second != x)
            q[z->second].erase({z->first, x});
        cout << z->first << endl;
        q[x].erase(q[x].begin());
    }
    return 0;
}