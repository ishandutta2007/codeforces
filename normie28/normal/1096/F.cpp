/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "ming.inp"
#define FILE_OUT "ming.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
const ll mod = 998244353;
int n;
ll tot;
int a[200010];
bool vis[200010];
ll sum[200010] , cnt[200010];
int lowbit(int x)
{
	return x & (-x);
}
void add(int x)
{
	for (; x <= n; x += lowbit(x))
	{
		sum[x]++;
	}
}
ll getres(int x)
{
	ll res = 0;
	for (; x > 0; x -= lowbit(x))
	{
		res += sum[x];
	}
	return res;
}
ll Pow(ll x , ll y)
{
	ll res = 1;
	while (y)
	{
		if (y & 1)
		{
			res *= x;
			res %= mod;
		}
		x *= x;
		x %= mod;
		y >>= 1;
	}
	return res;
}
int main()
{
	scanf("%d" , &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d" , &a[i]);
		if (a[i] == -1)
		{
			tot++;
		}
		else
		{
			vis[a[i]] = 1;
		}
	}
	ll now = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			now++;
		}
		else
		{
			cnt[i] = now;
		}
	}
	now = 0;
	ll res = tot * (tot - 1) % mod * Pow(4 , mod - 2) % mod;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == -1)
		{
			now++;
			continue;
		}
		res += i - now - getres(a[i]) - 1;
		//cout << res << endl;
		res %= mod;
		add(a[i]);
		ll l = now , r = tot - now , low = cnt[a[i]] , high = tot - cnt[a[i]];
		res += high * l % mod * Pow(tot , mod - 2) % mod + low * r % mod * Pow(tot , mod - 2) % mod;
		res %= mod;
	}
	cout << res << endl;
}