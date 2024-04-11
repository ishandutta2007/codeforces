
// Problem : C. Anniversary
// Contest : Codeforces - Codeforces Round #140 (Div. 1)
// URL : https://codeforces.com/problemset/problem/226/C
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
ll MOD;
vector<vector<ll>> trans={{1,1},{1,0}};
vector<ll> base(2);
vector<ll> vm_mul(vector<ll> a, vector<vector<ll>> b)
{
	ll i,j;
	vector<ll> c(2);
	for (i=0;i<=1;i++) for (j=0;j<=1;j++)
	{
		c[j]+=a[i]*b[i][j];
		c[j]%=MOD;
	}
	return c;
}
vector<vector<ll>> mm_mul(vector<vector<ll>> a, vector<vector<ll>> b)
{
	ll i,j,k;
	vector<vector<ll>> c=a;
	for (i=0;i<=1;i++) for (j=0;j<=1;j++)
	{
		c[i][j]=0;
	}
	for (i=0;i<=1;i++) for (j=0;j<=1;j++) for (k=0;k<=1;k++)
	{
		c[i][k]+=a[i][j]*b[j][k];
		c[i][k]%=MOD;
	}
	return c;
}
vector<vector<ll>> bow(vector<vector<ll>> a, ll x)
{
	if (x==1) return a;
	vector<vector<ll>> res=bow(a,x/2);
	res=mm_mul(res,res);
	if (x%2) res=mm_mul(res,a);
	return res;
}
ll get_fib (ll x)
{
	if (x<=2) return 1;
	base={1,1};
	base=vm_mul(base,bow(trans,x-2));
	return base[0];
}
ll n,m,k,c[501],pos[100001],t,t1,i,j,l,r,maxx;
int main()
{
//  ofile;
    fio;
    cin>>MOD>>l>>r>>k;
    l--;
    for (i=1;i<=1e6;i++) 
    if (r/i-l/i>=k) maxx=max(maxx,i);
    for (j=1;j<=1e6;j++)
    {
    	i=r/j;
    	if (!i) continue;
    if (r/i-l/i>=k) maxx=max(maxx,i);
    }
    for (j=1;j<=1e6;j++)
    {
    	i=(l)/j+1;
    	if (!i) continue;
    if (r/i-l/i>=k) maxx=max(maxx,i);
    }
//    cout<<maxx<<endl;
    cout<<get_fib(maxx)%MOD;
}