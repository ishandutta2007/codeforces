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
const int MAXN = 100005;
int p[MAXN], pn = 1;
 
long long getLowerBound(int cur, int n, int b)
{
	long long ret = 0;
	
	if(b == 0)
		return getLowerBound(cur, n, 1) + 1;
	if(b == 1)
		return 1LL * (n + n - n / cur * cur) * (n / cur + 1) / 2;
 
	while(n)
	{
		ret += n;
		n -= cur;
		cur = (int)min(1LL * cur * b, 1LL * n);
	}
 
	return ret;
}
 
void work(int n, int b, long long s)
{
	int cur = 1;
 
	while(n != cur)
	{
		int nxl = 1;
   		int nxr	= (int)min(1LL * n - cur, 1LL * cur * b);
 
		while(nxl < nxr)
		{
			int nxt = (nxl + nxr) >> 1;
			long long low = getLowerBound(nxt, n - cur, b);
			long long upp = getLowerBound(nxt, n - cur, 1);
 
			if(s - n < low)
				nxl = nxt + 1;
			else if(s - n > upp)
				nxr = nxt;
			else
				nxl = nxr = nxt;
		}
 
		for(int i = 1; i <= nxr; ++i)
			p[pn + i] = pn - cur + 1 + i % cur;
		pn += nxr;
 
		s -= n;
		n -= cur;
		cur = nxr;
	}
 
	return;
}
 
int main()
{
    fio;
	int n, bl, br;
	long long s;
 
    cin>>n>>s;
	bl = 0; br = n;
	while(bl < br)
	{
		int b = (bl + br) >> 1;
 
		if(getLowerBound(1, n, b) <= s)
			br = b;
		else
			bl = b + 1;
	}
	if(br == 0 || br == n)
	cout<<"No";
	else
	{
		work(n, br, s);
		cout<<"Yes"<<endl;
		for(int i = 2; i <= n; ++i)
			cout<<p[i]<<(i == n ? '\n' : ' ');
	}
}