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

vector<pair<ll, ll>> a, b;
vector<ll> k1, k2, l1, l2;

int main()
{
    fastRead;
    ll n, c, d;
    cin >> n >> c >> d;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        char c;
        cin >> x >> y >> c;
        if (c == 'C')
            a.push_back({y, x});
        else
            b.push_back({y, x});
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ans = 0, q1 = 0, q2 = 0;
    for (int i = 0; i < a.size(); i++)
        if (a[i].first <= c)
            q1 = max(q1, a[i].second);
    for (int i = 0; i < b.size(); i++)
        if (b[i].first <= d)
            q2 = max(q2, b[i].second);
    if (min(q1, q2) > 0)
        ans = q1 + q2;
    k1.resize(a.size());
    l1.resize(b.size());
    k2.resize(a.size());
    l2.resize(b.size());
    for (int i = 0; i < a.size(); i++)
    {
        if (i > 0)
            k1[i] = k1[i - 1], k2[i] = k2[i - 1];
        else
            k1[i] = -1e9, k2[i] = -1e9;
        if (a[i].second > k1[i])
            k2[i] = k1[i], k1[i] = a[i].second;
        else if (a[i].second > k2[i])
            k2[i] = a[i].second;
    }
    for (int i = 0; i < b.size(); i++)
    {
        if (i > 0)
            l1[i] = l1[i - 1], l2[i] = l2[i - 1];
        else
            l1[i] = -1e9, l2[i] = -1e9;
        if (b[i].second > l1[i])
            l2[i] = l1[i], l1[i] = b[i].second;
        else if (b[i].second > l2[i])
            l2[i] = b[i].second;
    }
    for (int i = 0; i < a.size(); i++)
    {
        int l = -1, r = a.size();
        while (r - l > 1)
        {
            int med = (r + l) / 2;
            if (a[med].first > c - a[i].first)
                r = med;
            else
                l = med;
        }
        if (l == -1)
            continue;
        ll t = (k1[l] == a[i].second ? k2[l] : k1[l]);
        ans = max(ans, t + a[i].second);
    }
    for (int i = 0; i < b.size(); i++)
    {
        int l = -1, r = b.size();
        while (r - l > 1)
        {
            int med = (r + l) / 2;
            if (b[med].first > d - b[i].first)
                r = med;
            else
                l = med;
        }
        if (l == -1)
            continue;
        ll t = (l1[l] == b[i].second ? l2[l] : l1[l]);
        ans = max(ans, t + b[i].second);
    }
    cout << ans;
    return 0;
}