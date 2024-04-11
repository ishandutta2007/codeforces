#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e5+1e3+7;

int n,q;

int a[N],b[N],c[N],s[N];

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

pii d[N][21];

pii operator +(pii a,pii b)
{
    return mp(min(a.fs,b.fs),max(a.sd,b.sd));
}

int LOG[N];

void pre()
{
    LOG[0]=-1;
    for(int i=1;i<=n;i++)
        d[i][0]=mp(s[i],s[i]),LOG[i]=LOG[i>>1]+1;
    for(int j=1;j<=20;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            d[i][j]=(d[i][j-1]+d[i+(1<<(j-1))][j-1]);
}

pii qry(int l,int r)
{
    int k=LOG[r-l+1];
    return d[l][k]+d[r-(1<<k)+1][k];
}

signed main()
{
    scanf("%lld%lld",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%lld",&b[i]);
    for(int i=1;i<=n;i++)
        c[i]=a[i]-b[i],s[i]=s[i-1]+c[i];
    pre();
    while(q--)
    {
        int l,r;
        scanf("%lld%lld",&l,&r);
        pii ret=qry(l,r);
        int mn=ret.fs,mx=ret.sd;
        if(s[r]!=s[l-1]||mx>s[l-1])
            puts("-1");
        else
            printf("%lld\n",s[l-1]-mn);
    }
}