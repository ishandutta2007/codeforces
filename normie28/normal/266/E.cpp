/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "input.txt"
#define FILE_OUT "output.txt"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define mod (ll(1000000007))
#define MAX 300001
#define mag 320
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define bi BigInt
#define pi 3.1415926535897
typedef long long ll;
//------------xc xch normie tm muoi tm phan tram no----------//
int n,m,a[100005],c[6][6],pw[6][100005],t[6][400005],lz[6][400005];
void build(int j,int i,int l,int r)
{
    lz[j][i]=-1;
    if (l==r)
    {
        t[j][i]=(ll)pw[j][l]*a[l]%mod;
        return;
    }
    int mid=l+r>>1;
    build(j,i<<1,l,mid),build(j,i<<1|1,mid+1,r),t[j][i]=(t[j][i<<1]+t[j][i<<1|1])%mod;
}
void psd(int j,int i,int l,int r)
{
    if (lz[j][i]!=-1)
    {
        int mid=l+r>>1,li=i<<1,ri=li|1;
        t[j][li]=(ll)lz[j][i]*(pw[j][mid]-pw[j][l-1])%mod;
        t[j][ri]=(ll)lz[j][i]*(pw[j][r]-pw[j][mid])%mod;
        lz[j][li]=lz[j][i],lz[j][ri]=lz[j][i],lz[j][i]=-1;
    }
}
int query(int j,int i,int l,int r,int x,int y)
{
    if (x<=l&&y>=r) return t[j][i];
    psd(j,i,l,r);
    int mid=l+r>>1;
    if (y<=mid) return query(j,i<<1,l,mid,x,y);
    if (x>mid) return query(j,i<<1|1,mid+1,r,x,y);
    return (query(j,i<<1,l,mid,x,y)+query(j,i<<1|1,mid+1,r,x,y))%mod;
}
void mdf(int j,int i,int l,int r,int x,int y,int z)
{
    if (x<=l&&y>=r)
    {
        t[j][i]=(ll)z*(pw[j][r]-pw[j][l-1])%mod,lz[j][i]=z;
        return;
    }
    psd(j,i,l,r);
    int mid=l+r>>1;
    if (x<=mid) mdf(j,i<<1,l,mid,x,y,z);
    if (y>mid) mdf(j,i<<1|1,mid+1,r,x,y,z);
    t[j][i]=(t[j][i<<1]+t[j][i<<1|1])%mod;
}
int main()
{
    fio;
    cin>>n>>m;
    pw[0][0]=1;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];pw[0][i]=1;
        for (int j=1;j<6;j++) pw[j][i]=(ll)pw[j-1][i]*i%mod;
    }
    for (int i=0;i<6;i++)
    {
        build(i,1,1,n),c[i][0]=1;
        for (int j=1;j<=n;j++) pw[i][j]=(pw[i][j]+pw[i][j-1])%mod;
        for (int j=1;j<=i;j++) c[i][j]=c[i-1][j-1]+c[i-1][j];
    }
    while (m--)
    {
        char ch;
        cin>>ch;
        int x,y,z;
        cin>>x>>y>>z;
        if (ch=='?')
        {
            int ans=0;
            if (x==1) ans=query(z,1,1,n,1,y);
            else for (int i=0;i<=z;i++)
                if ((i^z)&1) ans=(ans-(ll)query(i,1,1,n,x,y)*(pw[z-i][x-1]-pw[z-i][x-2])%mod*c[z][i])%mod;
                else ans=(ans+(ll)query(i,1,1,n,x,y)*(pw[z-i][x-1]-pw[z-i][x-2])%mod*c[z][i])%mod;
            cout<<((ans+mod)%mod)<<endl;
        }
        else for (int i=0;i<6;i++) mdf(i,1,1,n,x,y,z);
    }
}