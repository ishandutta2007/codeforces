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

int a[MAXN];
set<int> q;
set<int> p;
int used[MAXN];
vector<int> b;

int main()
{
   // freopen("in.txt", "r", stdin);
    fastRead;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    	q.insert(i);
    for (int i = 0; i < k; i++)
    	cin >> a[i], q.erase(a[i]);
    for (int i = 0; i < k; i++)
    	if (q.count(a[i] - 1))
    		p.insert(a[i]);
    for (int i = k; i < n; i++)
    {
    	set<int>::iterator it = q.upper_bound((p.size() ? *p.begin() : 1e9));
    	if (it == q.begin())
		{
			cout << -1;
			return 0;
		}
    	it--;
    	a[i] = *it;
   		q.erase(it);
   		p.erase(a[i] + 1);
   		if (q.count(a[i] - 1))
   			p.insert(a[i]);
    }
    int go = 1;
    for (int i = 0; i < n; i++)
    {
    	b.push_back(a[i]);
    	while (b.size() && b.back() == go)
    	{
    		b.pop_back();
    		go++;
    	}
    }
    if (go <= n)
    	cout << "-1";
    else
    	for (int i = 0; i < n; i++)
    		cout << a[i] << " ";
    return 0;
}