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

ll phi(ll n)
{
	ll result = n;
	for (ll i = 2; i * i <= n; i++)
		if (n % i == 0)
        {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
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

vector<pair<ll, ll>> a;
vector<ll> b;

int main()
{
    cout.precision(100);
    ll n, w;
    cin >> n >> w;
    a.resize(n);
    ll t = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i].first, a[i].second = i;
    sort(a.begin(), a.end());
    ll last = 0;
    b.resize(n);
    for (int i = 0; i < n; i++)
    {
        ll q = max(last, (a[i].first + 1) / 2);
        last = max(last, q);
        b[a[i].second] = q;
        w -= q;
    }
    if (w < 0)
    {
        cout << -1;
        return 0;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        ll q = min(a[i].first - b[a[i].second], w);
        b[a[i].second] += q;
        w -= q;
    }
    for (int i : b)
        cout << i << " ";
    return 0;
}