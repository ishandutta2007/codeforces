
// Problem : G. Two Merged Sequences
// Contest : Codeforces - Codeforces Round #550 (Div. 3)
// URL : https://codeforces.com/problemset/problem/1144/G
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

int n,tot,pri[9]={2,3,5,7,11,13,17,19,23},top;
ll m,x,a[50005],b[50005],f[50005],l[50005],prime[105];
std::map<ll,int> id;
 
ll gcd(ll x,ll y)
{
    if (!y) return x;
    else return gcd(y,x%y);
}
 
ll mul(ll x,ll y,ll mo)
{
    x%=mo;y%=mo;
    ll ans=(x*y-(ll)((double)x*y/mo+0.1)*mo)%mo;
    ans+=ans<0?mo:0;
    return ans;
}
 
ll ksm(ll x,ll y,ll mo)
{
    ll ans=1;
    while (y)
    {
        if (y&1) ans=mul(ans,x,mo);
        x=mul(x,x,mo);y>>=1;
    }
    return ans;
}
 
bool MR(ll n)
{
    if (n==2) return 1;
    if (n%2==0) return 0;
    ll w=n-1;int lg=0;
    while (w%2==0) w/=2,lg++;
    for (int i=0;i<9;i++)
    {
        if (n==pri[i]) return 1;
        ll x=ksm(pri[i],w,n);
        for (int j=0;j<lg;j++)
        {
            ll y=mul(x,x,n);
            if (x!=1&&x!=n-1&&y==1) return 0;
            x=y;
        }
        if (x!=1) return 0;
    }
    return 1;
}
 
ll rho(ll n)
{
    ll c=rand()*rand()%(n-1)+1,x1=rand()*rand()%n,x2=x1,k=1,p=1;
    for (int i=1;p==1;i++)
    {
        x1=(mul(x1,x1,n)+c)%n;
        if (x1==x2) return 1;
        p=gcd(n,abs(x1-x2));
        if (i==k) k<<=1,x2=x1;
    }
    return p;
}
 
void divi(ll n)
{
    if (n==1) return;
    if (MR(n)) {b[++tot]=n;return;}
    ll p=1;
    while (p==1) p=rho(n);
    divi(p);divi(n/p);
}
 
void pre()
{
    for (ll i=1;i*i<=m;i++)
        if (m%i==0)
        {
            a[++n]=i;
            if (m/i!=i) a[++n]=m/i;
        }
    std::sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) id[a[i]]=i;
    ll tmp=m;
    for (ll i=2;i*i<=tmp;i++)
        if (tmp%i==0)
        {
            prime[++top]=i;
            while (tmp%i==0) tmp/=i;
        }
    if (tmp>1) prime[++top]=tmp;
}
 
int main()
{
    scanf("%lld%lld",&m,&x);
    pre();
    for (int i=1;i<=n;i++) f[i]=m/a[i]-1;
    for (int j=1;j<=top;j++)
        for (int i=1;i<=n;i++)
            if (a[i]%prime[j]==0) f[id[a[i]/prime[j]]]-=f[i];
    for (int i=n;i>=1;i--)
    {
        l[i]=a[i];
        for (int j=1;j<=top;j++)
            if (l[i]%prime[j]==0) l[i]=l[i]/prime[j]*(prime[j]-1);
        tot=0;divi(l[i]);
        std::sort(b+1,b+tot+1);
        tot=std::unique(b+1,b+tot+1)-b-1;
        for (int j=1;j<=tot;j++)
            while (l[i]%b[j]==0&&ksm(x,l[i]/b[j],a[i])==1) l[i]/=b[j];
    }
    ll ans=1;
    for (int i=1;i<n;i++)
    {
        int j;
        for (j=1;a[j]!=m/a[i];j++);
        ans+=f[i]/l[j];
    }
    printf("%lld\n",ans);
    return 0;
}