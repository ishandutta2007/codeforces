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

vector<ll> a;


bool f()
{
    ll sum = 0;
    for (ll i : a)
        sum += i;
    if (sum % 2 == 1)
        return 0;
    sum /= 2;
    ll q = 0;
    set<ll> b;
    for (int i = 0; i < a.size(); i++)
    {
        b.insert(a[i]);
        q += a[i];
        if (q == sum || b.count(q - sum))
            return 1;
    }
    return 0;
}



int main()
{
    cout.precision(100);
    int n;
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    if (f())
    {
        cout << "YES";
        return 0;
    }
    reverse(a.begin(), a.end());
    if (f())
    {
        cout << "YES";
        return 0;
    }
    cout << "NO";

    return 0;
}