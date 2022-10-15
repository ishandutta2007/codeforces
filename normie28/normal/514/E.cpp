
// Problem : E. Darth Vader and Tree
// Contest : Codeforces - Codeforces Round #291 (Div. 2)
// URL : https://codeforces.com/problemset/problem/514/E
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
vector<vector<ll>> trans(102,vector<ll>(102));
vector<ll> base(102);
vector<ll> vm_mul(vector<ll> a, vector<vector<ll>> b)
{
	ll i,j;
	vector<ll> c(102);
	for (i=0;i<=101;i++) for (j=0;j<=101;j++)
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
	for (i=0;i<=101;i++) for (j=0;j<=101;j++)
	{
		c[i][j]=0;
	}
	for (i=0;i<=101;i++) for (j=0;j<=101;j++) for (k=0;k<=101;k++)
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
ll n,m,k,c[501],pos[100001],t,t1,i,j;
int main()
{
//  ofile;
    fio;
    cin>>n>>k;
    if (k==0) 
    {
    	cout<<1; return 0;
    }
    for (i=0;i<101;i++) trans[i][i+1]=1;
    trans[101][101]=1;
    for (i=1;i<=n;i++)
    {
    	cin>>m;
    	trans[m-1][0]++;
    }
    base[0]=1;
    base=vm_mul(base,bow(trans,k));
    t=0;
    for (ll g:base) t+=g;
    cout<<t%MOD;
}