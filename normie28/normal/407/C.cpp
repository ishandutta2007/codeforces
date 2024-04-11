
// Problem : C. Curious Array
// Contest : Codeforces - Codeforces Round #239 (Div. 1)
// URL : https://codeforces.com/problemset/problem/407/C
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
const int mod=1000000007;
const int N=200100;
const int M=200000;
int ori[N],n,m;
ll cf[110][100100],jc[N],inv[N],tmp[N];
ll C(int x,int y)
{
	return ((jc[x]*inv[y])%mod*inv[x-y])%mod;
}
ll ksm(ll x,int y)
{
	ll res=1;
	while(y)
	{
		if(y&1)res=(res*x)%mod;
		x=(x*x)%mod;y>>=1;
	}
	return res;
}
void ycl()
{
	int i;
	jc[0]=1;
	for(i=1;i<=M;i++)jc[i]=(jc[i-1]*(ll)i)%mod;
	inv[M]=ksm(jc[M],mod-2);
	for(i=M-1;i>=0;i--)inv[i]=(inv[i+1]*(ll)(i+1))%mod;
}
int main()
{
	fio;
	int i,j,k,x,y,z,nw;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>ori[i];
	ycl();
	
	while(m--)
	{
		cin>>x>>y>>z;
		cf[z][x]=(cf[z][x]+1)%mod;
		nw=y+1;
		for(i=0;((i<=z)&&(nw<=n));i++,nw++)cf[i][nw]=(cf[i][nw]-C(z+y-x+1,z-i)+mod)%mod;
	}
	
	for(i=100;i>=0;i--)
		for(j=1;j<=n;j++)cf[i][j]=(cf[i][j]+cf[i+1][j]+cf[i][j-1])%mod;
	for(i=1;i<=n;i++) cout<<(ori[i]+cf[0][i])%mod<<' ';
}