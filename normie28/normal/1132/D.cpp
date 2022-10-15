 
// Problem : D. Stressful Training
// Contest : Codeforces - Educational Codeforces Round 61 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1132/D
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
 
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
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
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
#define pii pair<ll,ll>
#define piii pair<ll,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
ll n,m,k,c[501],pos[100001],t,t1,i,j;
ll arr[200001]; int brr[200001];
int maxx[200001]; int remain[200001];
int length (int a)
{
	return (maxx[a]+1);
}
struct cmp
{
	bool operator()(int a, int b)
	{
		return (maxx[a]>maxx[b]);
	}
};
priority_queue<int,vector<int>,cmp> bruh;
ll check (ll x)
{
	while(bruh.size()) bruh.pop();
	for (int i=1;i<=n;i++)
	{
	if (arr[i]/brr[i]>=200000) maxx[i]=200000;
	else maxx[i]=arr[i]/brr[i];
	remain[i]=arr[i]%brr[i];
	bruh.push(i);
	}
	for (int i=0;i<k;i++)
	{
	    if (!bruh.size()) return 1;
		int pp=bruh.top();
		if (maxx[pp]+1<=i) return 0;
		else 
		{
		    ll fucc=remain[pp]+x;
		    if (fucc/brr[pp]+maxx[pp]>=200000) maxx[pp]=200000;
		    else maxx[pp]+=fucc/brr[pp];
		    remain[pp]=fucc%brr[pp];
			bruh.pop();
			if (maxx[pp]<=k-2) bruh.push(pp);
		}
	}
	return 1;
}
ll bs (ll l, ll r)
{
	if (l==r) return l;
	ll mid=(l+r)/2;
	if (check(mid)) return bs(l,mid); else return bs(mid+1,r);
}
int main()
{
//  ofile;
    fio;
    cin>>n>>k;
    for (i=1;i<=n;i++) cin>>arr[i];
    for (i=1;i<=n;i++) cin>>brr[i];
    t=bs(0,2e12+1);
    if (t==2e12+1) cout<<-1; else cout<<t;
}