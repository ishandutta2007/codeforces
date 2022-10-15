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
#endif
vector<int> vec;
int n,m,i,j,k,t,t1,u,v,a,b,ii,jj,iii,jjj;
int atb[10001],bta[715];
int red[10001];
int dp[2001][715][10];
int cur[4];
int tmp[4];
int p10[4]={1000,100,10,1};
int s[2000],tt[2000];
int main()
{
//	fio;
    cin>>n;
    u=0;
    for (i=0;i<=9;i++) for (j=i;j<=9;j++) for (k=j;k<=9;k++) for (t=k;t<=9;t++)
    {
        atb[i*1000+j*100+k*10+t]=u;
        bta[u]=i*1000+j*100+k*10+t;
        u++;
    }


    for (i=0;i<10000;i++)
    {
        for (j=0;j<4;j++) cur[j]=(i/p10[j])%10;
        sort(cur,cur+4);
        u=0;
        for (j=0;j<4;j++) u+=cur[j]*p10[j];
        red[i]=u;
    }


    for (i=0;i<n;i++) cin>>s[i]>>tt[i];
    for (i=0;i<=n;i++) for (j=0;j<715;j++) for (k=1;k<=9;k++) dp[i][j][k]=1e6;
    dp[0][0][1]=0;
    for (i=0;i<=n;i++) for (j=714;j>=0;j--) for (k=1;k<=9;k++)
    {
        u=bta[j];
    //    if (dp[i][j][k]<1e6) cout<<i<<' '<<j<<' '<<u<<' '<<k<<' '<<dp[i][j][k]<<endl;
        for (ii=0;ii<4;ii++) cur[ii]=(u/p10[ii])%10;
        for (ii=0;ii<4;ii++) if (cur[ii])
        {
            v=dp[i][j][k];
            v+=abs(cur[ii]-k);
            v++;
            memcpy(tmp,cur,sizeof(cur));
            cur[ii]=0;
            iii=i;
            jjj=0;
            sort(cur,cur+4);
            
            jj=cur[0]*p10[0]+cur[1]*p10[1]+cur[2]*p10[2]+cur[3]*p10[3];
            dp[iii][atb[jj]][tmp[ii]]=min(dp[iii][atb[jj]][tmp[ii]],v);
            memcpy(cur,tmp,sizeof(cur));
        }
        if (i<n)
        {
            v=dp[i][j][k];
            v+=abs(s[i]-k);
            memcpy(tmp,cur,16);
            iii=i;
            jjj=0;
            while((iii<n)and(jjj<4))
            {
                if (s[iii]!=s[i]) break;
                else if (cur[jjj]) jjj++;
                else
                {
                    cur[jjj]=tt[iii];
                    iii++;
                    jjj++;
                    v++;
                }
            }
            sort(cur,cur+4);
            jj=cur[0]*p10[0]+cur[1]*p10[1]+cur[2]*p10[2]+cur[3]*p10[3];
            dp[iii][atb[jj]][s[i]]=min(dp[iii][atb[jj]][s[i]],v);
            memcpy(cur,tmp,16);
        }
    }

    int res=1e6;
    for (j=1;j<=9;j++) res=min(res,dp[n][0][j]);
    cout<<res;
}