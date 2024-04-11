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

vector<ll> dp, a;

int main()
{
    fastRead;
    ll A, b, h, w, n;
    cin >> A >> b >> h >> w >> n;
    if (min(A, b) <= min(w, h) && max(A, b) <= max(w, h))
    {
        cout << 0;
        return 0;
    }
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.rbegin(), a.rend());
    int l = -1, r = min(1LL * 35, n);
    ll x = (A + w - 1) / w, y = (b + h - 1) / h;
    while (r - l > 1)
    {
        ll med = (r + l) / 2;
        bool ok = false;
        dp.assign(100001, 0);
        dp[1] = 1;
        for (int j = 0; j <= med; j++)
        {
            ll q = (x + a[j] - 1) / a[j];
            int z = -1;
            for (int i = q; i <= 100000; i++)
                if (dp[i])
                {
                    z = i;
                    break;
                }
            if (z != -1)
            {
                ll tau = z * a[j] * y, W = 1;
                for (int i = 0; i <= med; i++)
                {
                    if (W >= tau)
                        break;
                    W *= a[i];
                }
                if (W >= tau)
                    ok = true;
            }
            for (int k = 100000; k > 0; k--)
                if (dp[k] && 1LL * k * a[j] <= 100000)
                    dp[1LL * k * a[j]] = 1;
        }
        if (ok)
            r = med;
        else
            l = med;
    }
    ll ans = -1;
    if (r != n)
        ans = r + 1;
    l = -1;
    r = min(1LL * 35, n);
    x = (A + h - 1) / h;
    y = (b + w - 1) / w;
    while (r - l > 1)
    {
        ll med = (r + l) / 2;
        bool ok = false;
        dp.assign(100001, 0);
        dp[1] = 1;
        for (int j = 0; j <= med; j++)
        {
            ll q = (x + a[j] - 1) / a[j];
            int z = -1;
            for (int i = q; i <= 100000; i++)
                if (dp[i])
                {
                    z = i;
                    break;
                }
            if (z != -1)
            {
                ll tau = z * a[j] * y, W = 1;
                for (int i = 0; i <= med; i++)
                {
                    if (W >= tau)
                        break;
                    W *= a[i];
                }
                if (W >= tau)
                    ok = true;
            }
            for (int k = 100000; k > 0; k--)
                if (dp[k] && 1LL * k * a[j] <= 100000)
                    dp[1LL * k * a[j]] = 1;
        }
        if (ok)
            r = med;
        else
            l = med;
    }
    if (r != n)
    {
        if (ans == -1 || ans > r + 1)
            ans = r + 1;
    }
    cout << ans;
    return 0;
}