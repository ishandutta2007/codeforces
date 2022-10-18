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
//const int N = MAXN;
const ld eps = 1e-8;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

vector<ll> a;
vector<int> g[MAXN], w[MAXN];

const int N = 101, M = 28, K = 2;
int dp[K][M][N][N];

int f(int who, int num, int a, int b)
{
	if (dp[who][num][a][b] != -1)
		return dp[who][num][a][b];
	if (who == 0)
	{
		dp[who][num][a][b] = 0;
		for (int i = 0; i < g[a].size(); i++)
			if (w[a][i] >= num && f(1, w[a][i], g[a][i], b))
				dp[who][num][a][b] = 1;
	}
	else
	{
		dp[who][num][a][b] = 1;
		for (int i = 0; i < g[b].size(); i++)
			if (w[b][i] >= num && f(0, w[b][i], a, g[b][i]) == 0)
				dp[who][num][a][b] = 0;
	}
	//cout << who << " " << num << " " << a << " " << b << " " << dp[who][num][a][b] << endl;
	return dp[who][num][a][b];
}

int main()
{
    //freopen("in.txt", "r", stdin);
    for (int i = 0; i < K; i++)
    	for (int j = 0; j < M; j++)
    		for (int k = 0; k < N; k++)
    			for (int l = 0; l < N; l++)
    				dp[i][j][k][l] = -1;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
    	int u, v;
    	char c;
    	cin >> u >> v >> c;
    	g[u].push_back(v);
    	w[u].push_back(c - 'a');
    }
    for (int i = 1; i <= n; i++)
    {
    	for (int j = 1; j <= n; j++)
    	{
    		cout << (f(0, 0, i, j) ? "A" : "B");
    	}
    	if (i < n)
    		cout << endl;
    }
    return 0;
}