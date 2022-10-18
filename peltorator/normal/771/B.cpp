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

vector<int> t;

vector<vector<int>> ans;

vector<int> f(vector<int> a)
{
    for (int i = a.size() - 1; i >= 0; i--)
        if (a[i] < 25)
        {
            a[i]++;
            return a;
        }
}

int main()
{
    fastRead;
    int n, k;
    cin >> n >> k;
    t.resize(n - k + 1, 0);
    for (int i = 0; i < n - k + 1; i++)
    {
        string s;
        cin >> s;
        if (s == "NO")
            t[i] = 1;
    }
    vector<int> c;
    for (int i = 0; i < 9; i++)
        c.push_back(0);
    for (int i = 0; i < n; i++)
    {
        if (i < k - 1 || !t[i - k + 1])
        {
            c = f(c);
            ans.push_back(c);
        }
        else
            ans.push_back(ans[i - k + 1]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << "A";
        for (int j = 0; j < ans[i].size(); j++)
            cout << (char)(ans[i][j] + 'a');
        cout << endl;
    }
    return 0;
}