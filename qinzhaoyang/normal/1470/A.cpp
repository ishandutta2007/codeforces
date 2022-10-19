#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
typedef long long ll;
inline ll add(ll x , ll y) {return (x + y >= MOD ? x + y - MOD : x + y);}
inline ll sub(ll x , ll y) {return (x - y < 0 ? x - y + MOD : x - y);}
inline ll mul(ll x , ll y) {return 1ll * x * y % MOD;}

void exgcd(ll a , ll b , ll &x , ll &y)
{
	if(b == 0)
		return (void)(x = 1 , y = 0);
	exgcd(b , a % b , y , x);
	y -= (a / b) * x;
}

inline ll get(ll a)
{
	ll x , y;
	exgcd(a , MOD , x , y);
	return (x % MOD + MOD) % MOD;
}

ll gcd(ll x ,  ll y)
{
	if(y == 0)
		return x;
	return gcd(y , x % y);
}

struct Edge
{
	int nxt , to;
	Edge(int nxt = 0 , int to = 0) : nxt(nxt) , to(to) {} 
};

int T;
int n , m;
int k[300010] , c[300010];

int main()
{
	ios::sync_with_stdio(false); 
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			cin >> k[i];
		for(int i = 1; i <= m; i++)
			cin >> c[i];
		sort(k + 1 , k + n + 1);
		ll ans = 0;
		int top = 1;
		for(int i = n; i >= 1; i--)
		{
			if(top < k[i] && top <= m)
				ans += c[top++];
			else
				ans += c[k[i]];
		}
		cout << ans << endl;
	}
	return 0; 
}