/*
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
#define MOD (ll(1000000007))
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
vector<int> vec;
int n,m,i,j,k,t,t1,u,v,a,b,c,d,s,lim;
int fac[51];
vector<int> buc[3];
int dp[51][51][51][3];
int tri[3][51][51][2501];
int tri12[51][51][2501];
int main()
{
	fio;
    cin>>n>>m;
    t=m;
    lim=ceil(ld(n)/2);
    for (i=1;i<=n;i++)
    {
        cin>>u>>v;
        buc[v-1].push_back(u);
    }
    dp[1][0][0][0]=1;
    dp[0][1][0][1]=1;
    dp[0][0][1][2]=1;
    for (a=0;a<=buc[0].size();a++)
    for (b=0;b<=buc[1].size();b++)
    for (c=0;c<=buc[2].size();c++)
    for (s=0;s<3;s++)
    if (dp[a][b][c][s])
    {
    //    cout<<a<<' '<<b<<' '<<c<<' '<<s<<" | "<<dp[a][b][c][s]<<endl;
        if ((s!=0)and(a<buc[0].size())) dp[a+1][b][c][0]=(dp[a+1][b][c][0]+dp[a][b][c][s])%MOD;
        if ((s!=1)and(b<buc[1].size())) dp[a][b+1][c][1]=(dp[a][b+1][c][1]+dp[a][b][c][s])%MOD;
        if ((s!=2)and(c<buc[2].size())) dp[a][b][c+1][2]=(dp[a][b][c+1][2]+dp[a][b][c][s])%MOD;
    }
    fac[0]=1;
    for (i=1;i<=n;i++) fac[i]=((ll)fac[i-1]*i)%MOD;
    for (i=0;i<3;i++)
    {
        tri[i][0][0][0]=1;
        for (a=0;a<buc[i].size();a++) for (b=0;b<=min(a,lim);b++) for (c=0;c<=b*50;c++)
        {
            tri[i][a+1][b][c]+=tri[i][a][b][c];
            tri[i][a+1][b][c]%=MOD;
            tri[i][a+1][b+1][c+buc[i][a]]+=tri[i][a][b][c];
            tri[i][a+1][b+1][c+buc[i][a]]%=MOD;
    //        cout<<i<<' '<<a<<' '<<b<<' '<<c<<" | "<<tri[i][a][b][c]<<endl;
        }
    }
    int x,y,z;
    x=buc[0].size();
    y=buc[1].size();
    z=buc[2].size();
    for (a=0;a<=min(x,lim);a++)
    for (b=0;b<=min(y,lim);b++)
    for (c=0;c<=min(a*50,t);c++)
    for (d=0;d<=min(b*50,t-c);d++)
    {
    //    cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<" | "<<tri[0][x][a][c]<<' '<<tri[1][y][b][d]<<endl;
        tri12[a][b][c+d]+=(ll)tri[0][x][a][c]*tri[1][y][b][d]%MOD;
        tri12[a][b][c+d]%=MOD;
    }
    ll res=0;
    for (a=0;a<=min(x,lim);a++) for (b=0;b<=min(y,lim);b++) for (c=0;c<=min(z,lim);c++)
    {
     //   cout<<a<<' '<<b<<' '<<c<<' '<<" | "<<dp[a][b][c][0]<<' '<<dp[a][b][c][1]<<' '<<dp[a][b][c][2]<<endl;
        u=(ll)((ll)dp[a][b][c][0]+dp[a][b][c][1]+dp[a][b][c][2])%MOD*fac[a]%MOD*fac[b]%MOD*fac[c]%MOD;
    for (d=max(0,t-c*50);d<=min(t,(a+b)*50);d++) 
    {
        res+=(ll)tri12[a][b][d]*tri[2][z][c][t-d]%MOD*u%MOD;
        res%=MOD;
    }
    }
    cout<<res;
}