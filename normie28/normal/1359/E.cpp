
// Problem : E. Modular Stability
// Contest : Codeforces - Educational Codeforces Round 88 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1359/problem/E
// Memory Limit : 512 MB
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
#define MOD (ll(998244353))
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
ll n,m,k,pos[100001],t,t1,i,j,fac[1000001],dp[1000001],res;
ll bow (ll a, ll x)
{
	if (x==0)
	return 1;
	ll res=bow(a,x/2);
	res*=res; res%=MOD;
	if (x%2) res*=a;
	return res%MOD;
}
ll c (ll k, ll n)
{
	ll res=fac[n];
	res*=bow(fac[k],MOD-2); res%=MOD;
	res*=bow(fac[n-k],MOD-2); res%=MOD;
	return res;
}
int main()
{
//  ofile;
    fio;
    cin>>n>>k;
    fac[0]=1;
    for (i=1;i<=n;i++) {fac[i]=fac[i-1]*i; fac[i]%=MOD;}
    for (i=n;i>=1;i--)
    {
    	ll avail=(n)/i;
    	if ((avail-1)<(k-1)) dp[i]=0;
    	else
    	{
   // 		cout<<i<<' '<<c(k,avail)<<endl;
    		dp[i]=c(k-1,avail-1);
    		for (j=i*2;j<=n;j+=i) 
    		{
    //		dp[i]+=MOD-dp[j];
    //		dp[i]%=MOD;
    		}
    	}
    	res+=dp[i];
    }
    cout<<res%MOD;
}