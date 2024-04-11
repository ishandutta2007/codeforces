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
const int MAXN = 200001;
const int N = MAXN;
const ld eps = 1e-8;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

vector<ll> a;

string s[MAXN];

int used[MAXN], used1[MAXN];
int ans = 0;
string q;
int n, m;

bool check(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m && s[x][y] != '#';
}
int sx, sy, fx, fy;
void f(int t)
{
	if (t == 4)
	{
		int x = sx, y = sy;
		bool win = false, bad = false;
		for (int i = 0; i < q.size(); i++)
		{
			int go = q[i] - '0';
			x += dx[used[go]];
			y += dy[used[go]];
			if (!check(x, y))
			{
				bad = 1;
				break;
			}
			if (s[x][y] == 'E')
			{
				win = 1;
				break;
			}
		}
		if (win)
			ans++;
		return;
	}
	int i = t;
	for (int j = 0; j < 4; j++)
		if (used[i] == -1 && used1[j] == -1)
		{
			used[i] = j;
			used1[j] = i;
			f(t + 1);
			used[i] = -1;
			used1[j] = -1;
		}
}

int main()
{
    //freopen("in.txt", "r", stdin);
    fastRead;
    for (int i = 0; i < N; i++)
    	used[i] = used1[i] = -1;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    	cin >> s[i];
   	for (int i = 0; i < n; i++)
   		for (int j = 0; j < m; j++)
   			if (s[i][j] == 'S')
   				sx = i, sy = j;
   			else if (s[i][j] == 'F')
   				fx = i, fy = j;
   	cin >> q;
   	f(0);
   	cout << ans;
    return 0;
}