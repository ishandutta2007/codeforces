
// Problem : A. Elections
// Contest : Codeforces - Codeforces Round #503 (by SIS, Div. 1)
// URL : https://codeforces.com/contest/1019/problem/A
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
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
ll n,m,k,c[501],pos[100001],t,t1,i,j;
ll res=1e18;
vector<ll> price[3001],remain;
void check (ll x)
{
	remain.clear();
	ll cur=0,bought=0;
	for (ll i=2;i<=m;i++) 
	for (ll j=0;j<price[i].size();j++)
	{
		if (j<max(price[i].size()-(x-1),0)) {cur+=price[i][j]; bought++;}
		else
		{
			remain.push_back(price[i][j]);
		}
	}
	if (price[1].size()+bought>x) return;
	sort(remain.begin(),remain.end());
	for (ll i=0;i<x-(price[1].size()+bought);i++) cur+=remain[i];
	res=min(cur,res);
}
int main()
{
//  ofile;
    fio;
    cin>>n;
    cin>>m;
    for (i=1;i<=n;i++)
    {
    	cin>>t>>t1;
    	price[t].push_back(t1);
    }
    for (i=1;i<=m;i++) sort(price[i].begin(),price[i].end());
    for (i=price[1].size();i<=n;i++) check(i);
    cout<<res;
}