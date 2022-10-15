
// Problem : E. The Top Scorer
// Contest : Codeforces - Educational Codeforces Round 57 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1096/E
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
const int mod=998244353;
int pow1(int a,int b)
{
    int r=1;
    while(b)
    {
        if(b&1)
            r=1LL*r*a%mod;
        a=1LL*a*a%mod;
        b/=2;
    }
    return r;
}
const int maxn=5111;
int c[maxn][maxn],inv[maxn];
void init()
{
    c[0][0]=1;
    for(int i=1;i<maxn;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=i;j++)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    }
    inv[1]=1;
    for(int i=2;i<maxn;i++)
        inv[i]=mod-1LL*(mod/i)*inv[mod%i]%mod;
}
int C(int n,int m)
{
    if(n<0||m<0||m>n)
        return 0;
    return c[n][m];
}
int work(int s,int n,int limit)
{
    if(s<0)
        return 0;
    if(s==0)
        return 1;
    int res=0;
    for(int i=0;i<=n;i++)
    {
        int tmp=1LL*C(s-i*limit+n-1,n-1)*C(n,i)%mod;
        if(i%2) res=(res-tmp+mod)%mod;
        else res=(res+tmp)%mod;
    }
    return res;
}
int main()
{
	fio;
    int p,s,r;
    cin>>p>>s>>r;
    init();
    int res=0;
    for(int x=r;x<=s;x++)
    {
        for(int i=1;i<=p;i++)
        {
            if((p-i)*(x-1)+i*x<s)continue;
            res=(res+1LL*C(p-1,i-1)*work(s-x*i,p-i,x)%mod*inv[i])%mod;
        }
    }
    res=1LL*res*pow1(C(s-r+p-1,p-1),mod-2)%mod;
    cout<<res;
}