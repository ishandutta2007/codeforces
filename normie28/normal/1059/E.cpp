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
#define mod 998244353
int static const N = 200010;
 
int n, leng, br, maxx[N], res;
ll s, w[N], niz[N];
vector<int> a[N]; 
 
void dfs(int x)
{
	niz[br] = niz[br-1] + w[x];
	br++;
	for(int i=0;i<a[x].size();i++)
		dfs(a[x][i]);
	
	int l = 0, d = br-2;
	while(d-l > 1)
	{
		int m = (l+d)/2;
		if(niz[br-1] - niz[m] > s)
			l = m+1;
		else
			d = m;
	}	
	if(niz[br-1] - niz[l] > s)
		l++;
	int dubina;
	dubina = min(br-2-l, leng-1);
	int maks = 0;		
	for(int i=0;i<a[x].size();i++)
		maks = max(maks, maxx[a[x][i]]);
	if(maks)
		maxx[x] = maks-1;
	else
	{
		maxx[x] = dubina;
		res++;
	}
	br--;
}
 
int main()
{	
	niz[br++] = 0;	
	int t = 1;
	cin>>n>>leng>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
		if(w[i] > s)
			t = 0;
	}
	for(int i=2;i<=n;i++)
	{
		int x;
		cin>>x;
		a[x].push_back(i);
	}
	if(!t)
		printf("-1\n");
	else
	{
		dfs(1);
		cout<<res<<endl;	
	}
	
 
	return 0;
}