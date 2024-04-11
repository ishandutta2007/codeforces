#ifndef CPL_TEMPLATE
#define CPL_TEMPLATE
/*
	Normie's Template v2.4
	Changes:
    Added include-guards to help with writing in multiple source files.
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
#define fio ios::sync_with_stdio(0);cin.tie(0)
#define nfio cin.tie(0)
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
#endif
vector<int> vec;
string s;
int kmp[1001];
int trans[1001][2];
ll dp[201][201][201][2];
int n,m,i,j,k,t,t1,u,v,a,b;
int main()
{
	fio;
    cin>>n;
    cin>>s;
    m=s.length();
    for (i=1;i<m;i++)
    {
        u=kmp[i-1];
        while(true)
        {
            if (u==0)
            {
                if (s[i]!=s[u]) {kmp[i]=0; break;}
                else {kmp[i]=1; break;}
            }
            else
            {
                if (s[i]!=s[u]) {u=kmp[u-1]; }
                else {kmp[i]=u+1; break;}
            }
        }
    //    cout<<"kmp "<<i<<' '<<kmp[i]<<endl;
    }
    for (i=0;i<m;i++)
    {
        if (s[i]=='(') 
        {
            trans[i][0]=i+1;            
            if (i==0) trans[i][1]=i;
            else
            {
            u=kmp[i-1];

            while(true)
            {
                if (u==0)
                {
                    if (')'!=s[u]) {trans[i][1]=0; break;}
                    else {trans[i][1]=1; break;}
                }
                else
                {
                    if (')'!=s[u]) {u=kmp[u-1]; }
                    else {trans[i][1]=u+1; break;}
                }
            }
            }
        }
        else
        {
            trans[i][1]=i+1;            
            u=kmp[i-1];
            if (i==0) trans[i][0]=i;
            else
            {

            while(true)
            {
                if (u==0)
                {
                    if ('('!=s[u]) {trans[i][0]=0; break;}
                    else {trans[i][0]=1; break;}
                }
                else
                {
                    if ('('!=s[u]) {u=kmp[u-1]; }
                    else {trans[i][0]=u+1; break;}
                }
            }
            }
        }
    //    cout<<trans[i][0]<<' '<<trans[i][1]<<endl;
    }
    i=m;
    {
        {
            u=kmp[i-1];
            while(true)
            {
                if (u==0)
                {
                    if (')'!=s[u]) {trans[i][1]=0; break;}
                    else {trans[i][1]=1; break;}
                }
                else
                {
                    if (')'!=s[u]) {u=kmp[u-1]; }
                    else {trans[i][1]=u+1; break;}
                }
            }
        }
        {
            u=kmp[i-1];
            while(true)
            {
                if (u==0)
                {
                    if ('('!=s[u]) {trans[i][0]=0; break;}
                    else {trans[i][0]=1; break;}
                }
                else
                {
                    if ('('!=s[u]) {u=kmp[u-1]; }
                    else {trans[i][0]=u+1; break;}
                }
            }
        }
     //   cout<<trans[i][0]<<' '<<trans[i][1]<<endl;
    }
    dp[0][0][0][0]=1;
    for (i=0;i<2*n;i++) for (j=0;j<=i;j++) for (k=0;k<=m;k++) for (t=0;t<2;t++)
    {
        dp[i][j][k][t]%=MOD;
    //    if (dp[i][j][k][t])    cout<<dp[i][j][k][t]<<i<<' '<<j<<' '<<k<<' '<<t<<endl;
        if (trans[k][0]==m)
        {
            dp[i+1][j+1][trans[k][0]][1]+=dp[i][j][k][t];
        }
        else
        {
            dp[i+1][j+1][trans[k][0]][t]+=dp[i][j][k][t];
        }
        if (j)
        {
        if (trans[k][1]==m)
        {
            dp[i+1][j-1][trans[k][1]][1]+=dp[i][j][k][t];
        }
        else
        {
            dp[i+1][j-1][trans[k][1]][t]+=dp[i][j][k][t];
        }
        }
    }
    int res=0;
    for (i=0;i<=m;i++) res=(res+dp[2*n][0][i][1]%MOD)%MOD;
    cout<<res;
}