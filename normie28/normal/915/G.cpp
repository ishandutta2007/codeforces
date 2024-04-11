
// Problem : G. Coprime Arrays
// Contest : Codeforces - Educational Codeforces Round 36 (Rated for Div. 2)
// URL : https://codeforces.com/contest/915/problem/G
// Memory Limit : 256 MB
// Time Limit : 3500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
	Normie's Template v2.0
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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
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

//Constants.
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
 
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
//---------END-------//
ll res[2000001];
int mobius[2000001];
ll n,m,i,j,k,t,t1,u,v,a,b;
ll pwn[2000001];
ll diff[2000001];
int isq[2000001];
ll bow(ll a, ll x, ll p)
{
	if (!x) return 1;
	ll res=bow(a,x/2,p);
	res*=res;
	res%=p;
	if (x%2) res*=a;
	return res%p;
}
int main()
{
    fio;
    cin>>n>>m;
    for (i=1;i*i<=m;i++) isq[i*i]=1;
    for (i=1;i<=m;i++)
    for (j=i;j<=m;j+=i)
    {
        mobius[j]++;
        if ((isq[i])and(i>1)) mobius[j]=-1e9;
    }
    
    for (i=0;i<=m;i++) pwn[i]=bow(i,n,MOD);
    for (i=1;i<=m;i++)
    {
        diff[i]=(pwn[i]-pwn[i-1]+MOD)%MOD;
    }
    for (i=1;i<=m;i++)
    {
        if (mobius[i]<0) mobius[i]=0;
        else 
        {
            v=0;
            while(mobius[i]%2==0)
            {
                v++;
                mobius[i]/=2;
            }
            if (v%2) mobius[i]=MOD-1;
            else mobius[i]=1;
        }
    }
    u=0;
    a=0;
    for (i=1;i<=m;i++)
    for (j=i;j<=m;j+=i)
    {
        	res[j]+=mobius[i]*(diff[j/i])%MOD;
        	res[j]%=MOD;
    }
    for (i=1;i<=m;i++)
    {
        u+=res[i];
        u%=MOD;
        a+=u^i;
    }
    cout<<a%MOD;
}