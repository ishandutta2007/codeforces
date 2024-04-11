
// Problem : B. Game with modulo
// Contest : Codeforces - Codeforces Round #534 (Div. 1)
// URL : https://codeforces.com/contest/1103/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
#define bi BigInt
typedef long long ll;
//---------END-------//

const ll mod=1000000007;
 
struct matrix
{
    ll v[100][100];
};
ll c[50][50],n,k;
matrix bin,res;
 
void init()
{
    for(int i=0;i<=k;i++)
        for(int j=0;j<=i;j++)
            if(j==0||i==j)
                c[i][j]=1;
            else
                c[i][j]=c[i-1][j]+c[i-1][j-1];
}
 
void getstates()
{
    memset(bin.v,0,sizeof(bin.v));
    for(int i=0;i<=k;i++)
        for(int j=0;j<=i;j++)
            bin.v[i][j]=bin.v[i][j+k+1]=bin.v[i+k+1][j]=c[i][j];
    bin.v[2*k+2][k]=bin.v[2*k+2][2*k+2]=1;
 
    memset(res.v,0,sizeof(res.v));
    for(int i=0;i<=2*k+2;i++)
        res.v[i][i]=1;
}
 
matrix mult(matrix &a,matrix &b)
{
    matrix temp;
    for(int i=0;i<=2*k+2;i++)
        for(int j=0;j<=2*k+2;j++)
        {
            temp.v[i][j]=0;
            for(int l=0;l<=2*k+2;l++)
                temp.v[i][j]=(temp.v[i][j]+a.v[i][l]*b.v[l][j])%mod;//,printf("wethura%d\n",l);
        }
 
    return temp;
}
 
matrix quick(matrix &a,matrix &b,ll len)
{
    while(len)
    {
        if(len&1)
            b=mult(a,b);
        a=mult(a,a);
        len>>=1;
    }
    return b;
}
int main()
{
    fio;
    cin>>n>>k;
    init();
 
    getstates();
    res=quick(bin,res,n);
    ll Res=0;
    for(int i=0;i<2*k+2;i++)
        Res=(Res+res.v[2*k+2][i])%mod;
    printf("%lld\n",Res);
}