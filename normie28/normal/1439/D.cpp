/*
    this submission was made after reading editorial
	Normie's Template v2.2
	Changes:
	Added modulo binpow and inverse.
*/
 
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;
 
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

// Fast min/max assigns to use with AVX.
// Requires g++ 9.2.0.
template<typename T>
__attribute__((always_inline)) void chkmin(T& a, const T& b) {
    a=(a<b)?a:b;
}

template<typename T>
__attribute__((always_inline)) void chkmax(T& a, const T& b) {
    a=(a>b)?a:b;
}
 
//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
const long double PI=3.14159265358979;
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;

// Binpow and stuff
ll BOW(ll a, ll x, ll p)
{
	if (!x) return 1;
	ll res=BOW(a,x/2,p);
	res*=res;
	res%=p;
	if (x%2) res*=a;
	return res%p;
}
ll INV(ll a, ll p)
{
	return BOW(a,p-2,p);
}
//---------END-------//
vector<ll> vec;
ll n,m,i,pr,j,k,t,t1,u,v,a,b;
ll ways1[501],ways2[501][501][2];
ll summ1[501],summ2[501][501][2];
ll fac[501],inv[501];
int main()
{
	fio;
    cin>>n>>m>>pr;
    fac[0]=1;
    inv[0]=1;
    for (i=1;i<=n;i++)
    {
        fac[i]=(fac[i-1]*i)%pr;
        inv[i]=INV(fac[i],pr);
    }
    
    ways1[0]=1;
    summ1[0]=0;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=i;j++)
        {
            u=ways1[j-1]*ways1[i-j]%pr*fac[i-1]%pr*inv[j-1]%pr*inv[i-j]%pr;
            v=((ways1[j-1]*summ1[i-j])+(ways1[i-j]*summ1[j-1]))%pr*fac[i-1]%pr*inv[j-1]%pr*inv[i-j]%pr*(i+1)%pr;
            v+=u*(j*(j-1)/2+(i-j+1)*(i-j)/2)%pr;
            u*=(i+1)%pr;
            v%=pr;
            u%=pr;
            ways1[i]+=u;
            ways1[i]%=pr;
            summ1[i]+=v;
            summ1[i]%=pr;
        }
  //      cout<<i<<' '<<ways1[i]<<' '<<summ1[i]<<endl;
    }
    
    ways2[0][0][1]=1;
    ways2[0][0][0]=0;
    summ2[0][0][1]=0;
    summ2[0][0][0]=0;
    for (i=0;i<n;i++) for (j=0;j<=m;j++) for (k=0;k<2;k++)
    {
        ways2[i][j][k]%=pr;
        summ2[i][j][k]%=pr;
        ways2[i+1][j][1]+=ways2[i][j][k];
        summ2[i+1][j][1]+=summ2[i][j][k];
        if (k==1) for (t=1;((j+t<=m)and(i+t<=n));t++)
        {
            a=fac[j+t]%pr*inv[j]%pr*inv[t]%pr;
            u=ways2[i][j][k]*ways1[t]%pr*a%pr;
            v=((ways2[i][j][k]*summ1[t])+(ways1[t]*summ2[i][j][k]))%pr*a%pr;
            ways2[i+t][j+t][0]+=u;
            summ2[i+t][j+t][0]+=v;
        }
    }
    /*
    */
    cout<<(summ2[n][m][0]+summ2[n][m][1])%pr;
}