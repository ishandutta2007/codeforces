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
const ld eps = 1e-8;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int a[MAXN], q[MAXN];

int main()
{
    //freopen("in.txt", "r", stdin);
    fastRead;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    	cin >> a[i];
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
    	for (int j = 1; j < i; j++)
    		if (a[j] > a[i])
    			q[i]++;
    	for (int j = i + 1; j <= n; j++)
    		if (a[j] < a[i])
    			q[i]++;
    	sum += q[i];
    }
    sum /= 2;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
    	int l, r;
    	cin >> l >> r;
    	int x = (r - l + 1);
    	if (((x - 1) * x / 2) % 2)
    		sum++;
    	cout << (sum % 2 ? "odd\n" : "even\n");
    }
    return 0;
}