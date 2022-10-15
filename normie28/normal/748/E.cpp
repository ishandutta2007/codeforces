
// Problem : E. Santa Claus and Tangerines
// Contest : Codeforces - Technocup 2017 - Elimination Round 3
// URL : https://codeforces.com/problemset/problem/748/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
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
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
ll n,m,k,c[501],arr[1000001],t,t1,i,j;
ll dp[10000001];
ll check(ll x)
{
	ll res=0;
	for (ll i=0;i<x;i++) dp[i]=0;
	for (ll i=x;i<=10000000;i++)
	{
		dp[i]=max(1,dp[i/2]+dp[i-i/2]);
	}
	for (ll i=1;i<=n;i++)
	{
			res+=dp[arr[i]];
		
	}
	if (res>=k) return 1; else return 0;
}
ll bs(ll l, ll r)
{
	if (l==r) return l;
	ll mid=(l+r)/2+1;
	if (check(mid)) return bs(mid,r); else return bs(l,mid-1);
}
int main()
{
//  ofile;
    fio;
    cin>>n>>k;
    for (i=1;i<=n;i++)
    {
    	cin>>arr[i];
    }
    t1=bs(0,1e7+1);
    if (t1==0) cout<<-1;
    else cout<<t1;
}