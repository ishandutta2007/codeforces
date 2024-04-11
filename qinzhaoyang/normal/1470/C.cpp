
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
 
int n , k , t;

int lst = 0;

int change(int x)
{
	return ((x - 1) % n + n) % n + 1;
}
 
int main()
{
	ios::sync_with_stdio(false); 
	cin >> n >> k;
	int now = 1 , plus = 1;
	while(true)
	{
		cout << "? " << now << endl;
		cout.flush();
		cin >> t;
		if(t != k)
			break;
		now = change(now + (plus++));
	}
	int S = sqrt(n) , cnt = 0;
	if(t < k)
	{
		while(true)
		{
			cout << "? " << change(now + S) << endl;
			cout.flush();
			cin >> t;
			if(t >= k)
				break;
			now = change(now + S);
		}
		while(true)
		{
			cout << "? " << change(now + 1) << endl;
			cout.flush();
			cin >> t;
			if(t >= k)
				break;
			now = change(now + 1);
		}
		now = change(now + 1);
	}
	else
	{
		while(true)
		{
			cout << "? " << change(now - S) << endl;
			cout.flush();
			cin >> t;
			if(t <= k)
				break;
			now = change(now - S);
		}
		while(true)
		{
			cout << "? " << change(now - 1) << endl;
			cout.flush();
			cin >> t;
			if(t <= k)
				break;
			now = change(now - 1);
		}
		now = change(now - 1);
	}
	cout << "! " << now << endl;
	return 0;
}