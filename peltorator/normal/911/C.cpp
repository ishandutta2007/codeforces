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
const int MAXN = 10000000;
const ld eps = 1e-8;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int k[MAXN], x[MAXN];
int used[MAXN];

int main()
{
    //freopen("in.txt", "r", stdin);
    fastRead;
    for (int i = 0; i < 3; i++)
    	cin >> k[i];
    sort(k, k + 3);
    if (k[0] == 1)
    {
    	cout << "YES";
    	return 0;
    }
    x[0] = 1;
    for (int _ = 0; _ < 2; _++)
    {
    	x[1] = 2;
    	for (int i = 0; i < MAXN; i++)
    		used[i] = 0;
    	for (int i = 0; i < 2; i++)
    		for (int j = 0; k[i] * j + x[i] < MAXN; j++)
    			used[k[i] * j + x[i]] = 1;
    	int start = 1;
    	while (start < MAXN && used[start])
    		start++;
    	if (start == MAXN)
    	{
    		cout << "YES";
    		return 0;
    	}
    	x[2] = start;
    	int i = 2;
    	for (int j = 0; k[i] * j + x[i] < MAXN; j++)
    		used[k[i] * j + x[i]] = 1;
    	bool ok = true;
    	for (int i = 1; i < MAXN; i++)
    		if (!used[i])
    			ok = false;
    	if (ok)
    	{
    		cout << "YES";
    		return 0;
    	}
    	swap(k[1], k[2]);
    }
    cout << "NO";
    return 0;
}