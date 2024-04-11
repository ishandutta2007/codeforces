/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "text.out"
#define FILE_OUT "result.out"
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
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define bi BigInt
#define pi 3.1415926535897
typedef long long ll;
//------------xc xch normie tm muoi tm phan tram no----------//
ll n,m,k,c[1001],t,t1,i,j,minn,maxx,cur,lu,lv;
vector<ll> buc[1000002];
ll up[1000002],down[1000002];
ordered_set se;
int main() {
//	ofile;
	fio;
	long long n, i,j;
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>k;
		buc[k].push_back(i);
	}
	maxx=0;
	for (i=0;i<=m+1;i++)
	{
		for (ll g : buc[i])
		if (g>maxx) maxx=g;
		else maxx=1e9;
		up[i]=maxx; 
	}
	
	maxx=n+1;
	for (i=m+1;i>=0;i--)
	{
		for (j=buc[i].size()-1;j>=0;j--)
		{
		ll g = buc[i][j];
		if (g<maxx) maxx=g;
		else maxx=-1e9;
	}
		down[i]=maxx;
	}
	for (i=2;i<=m+1;i++)
	{
//		cout<<up[i-2]<<' '<<down[i]<<endl;
		se.insert(up[i-2]*1e9+i-2);
		lv+=se.order_of_key(down[i]*1e9);
//		cout<<se.order_of_key(down[i]*1e9)<<endl;
	}
	cout<<lv;
}