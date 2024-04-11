
// Problem : E. Mike and Geometry Problem
// Contest : Codeforces - Codeforces Round #361 (Div. 2)
// URL : https://codeforces.com/problemset/problem/689/E
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
#define pii pair<ll,ll>
#define piii pair<ll,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
ll n,m,k,c[501],fac[200001],t,t1,i,j,a,b,res=0;
vector<pii> ch;
ll bow (ll a, ll x)
{
	if (!x) return 1;
	ll res=bow(a,x/2);
	res*=res;
	res%=MOD;
	if (x%2) res*=a;
	return (res%MOD);
}
ll cmb (ll n, ll k)
{
	if (n<k) return 0;
	else 
	{
		ll res=1;
		res*=fac[n];
		res*=bow(fac[k],MOD-2);
		res%=MOD;
		res*=bow(fac[n-k],MOD-2);
		return (res%MOD);
	}
}
int main(){
	fio;
	cin>>n>>k;
	fac[0]=1;
	for (i=1;i<=n;i++) {
		fac[i]=fac[i-1]*i; fac[i]%=MOD;
	}
	for (i=1;i<=n;i++)
	{
		cin>>a>>b;
		ch.push_back({a,1});
		ch.push_back({b+1,-1});
	}
	sort(ch.begin(),ch.end(),[](pii a, pii b){return (a.fi<b.fi);});
	t=1;
	for (i=1;i<2*n;i++)
	{
		res+=((ch[i].fi-ch[i-1].fi)*(cmb(t,k)))%MOD;
		t+=ch[i].se;
		res%=MOD;
	}
	cout<<res;
}