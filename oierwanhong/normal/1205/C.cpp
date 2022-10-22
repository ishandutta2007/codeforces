#include<cstdio>
typedef long long ll;
ll ask(ll x1,ll y1,ll x2,ll y2)
{
    printf("? %lld %lld %lld %lld\n",x1,y1,x2,y2);fflush(stdout);
    ll x;scanf("%lld",&x);
    return x;
}
ll a[111][111];
void print(ll n,bool rev)
{
    puts("!");
    for(ll i=1;i<=n;++i)
    {
        for(ll j=1;j<=n;++j)
        {
            if(i+j&1)a[i][j]^=rev;
            putchar(a[i][j]+'0');
        }
        putchar('\n');
    }
    fflush(stdout);
}
int main()
{
    ll n;scanf("%lld",&n);
    a[1][1]=1,a[n][n]=0;
    for(ll j=3;j<=n;++j)a[1][j]=a[1][j-2]^(!ask(1,j-2,1,j));
    for(ll i=2;i<=n;++i)
    {
        for(ll j=n;j>1;--j)a[i][j]=a[i-1][j-1]^(!ask(i-1,j-1,i,j));
        a[i][1]=a[i][3]^(!ask(i,1,i,3));
    }
    bool rev=0;
    for(ll i=1;i<n-1;++i)
        if(a[i][i]&&!a[i+2][i+2])
        {
            if(ask(i,i,i+1,i+2))rev=a[i+1][i+2]^1;
            else if(ask(i,i+1,i+2,i+2))rev=a[i][i+1]^a[i+2][i+2];
            else if(a[i][i+1]==a[i+1][i+2])rev=a[i][i+1]^a[i][i+2]^1;
            else rev=a[i][i+1]^1;
            print(n,rev);return 0;
        }
    print(n,rev);return 0;
}