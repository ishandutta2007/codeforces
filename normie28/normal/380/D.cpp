 
// Problem : E. Neatness
// Contest : Codeforces - Codeforces Round #209 (Div. 2)
// URL : https://codeforces.com/contest/359/problem/E
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
 
inline ll read()
{
    ll S=0; char ch=' '; bool f=0;
    while(!isdigit(ch)) {f|=(ch=='-'); ch=getchar();}
    while(isdigit(ch)) {S=(S<<3)+(S<<1)+(ch-'0'); ch=getchar();}
    return (f)?(-S):(S);
}
#define R(x) x=read()
inline void write(ll x)
{
    if(x<0){putchar('-'); x=-x;}
    if(x<10){putchar(x+'0'); return;}
    write(x/10); putchar(x%10+'0'); return;
}
#define W(x) write(x),putchar(' ')
#define Wl(x) write(x),putchar('\n')
const ll Mod=1000000007;
const int N=100005;
int n,a[N],jfm[N];
ll fac[N],invf[N],bin[N];
inline void Ad(ll &x,ll y){x+=y; x-=(x>=Mod)?Mod:0;}
inline ll ksm(ll x,ll y)
{
    ll jyl=1;
    for(;y;y>>=1,x=x*x%Mod)
    {
        if(y&1) jyl=jyl*x%Mod;
    }
    return jyl;
}
inline ll C(int n,int m)
{
    if(n<m) return 0ll;
    return fac[n]*invf[m]%Mod*invf[n-m]%Mod;
}
inline ll solve(int l,int r)
{
    if(jfm[r]-jfm[l-1]==0) return bin[r-l];
    int p1=0,p2=0,lef,rig;
    for(p1=l;p1<=r;p1++) if(a[p1]) break;
    for(p2=r;p2>=l;p2--) if(a[p2]) break;
    if(p1==p2&&a[p1]==1) return C(r-l,p1-l);
    ll jyl=0;
    if(a[p1]>=a[p2])
    {
    	lef=p1; rig=p1+a[p1]-1;
    	if(rig>=p2&&rig<=r) Ad(jyl,1ll*solve(lef+1,rig)*C(r-l-(rig-lef),lef-l)%Mod);
	}
	if(a[p2]>=a[p1])
	{
		lef=p2-a[p2]+1; rig=p2;
		if(lef<=p1&&lef>=l) Ad(jyl,1ll*solve(lef,rig-1)*C(r-l-(rig-lef),lef-l)%Mod);
	}
	return jyl;
}
int main()
{
    int i;
    R(n);
    fac[0]=bin[0]=1;
    for(i=1;i<=n;i++)
    {
        fac[i]=fac[i-1]*i%Mod; bin[i]=(bin[i-1]<<1ll)%Mod;
    }
    invf[n]=ksm(fac[n],Mod-2); for(i=n-1;i>=0;i--) invf[i]=invf[i+1]*(i+1)%Mod;
    for(i=1;i<=n;i++) R(a[i]);
    jfm[0]=0; for(i=1;i<=n;i++) jfm[i]=jfm[i-1]+(bool)(a[i]);
    Wl(solve(1,n));
}