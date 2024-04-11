#include<bits/stdc++.h>
using namespace std;

const int N=2e3+1e2+7;

int n,m;

char s[N][N];

long long ans[N][N],g[N][N];

int le[N];

struct Line{
    int k,b;

    long long eval(int x)
    {
        return k*x+b;
    }
};

int cnt;

struct T{
    int l,r,ls,rs;
    Line v;
}t[N*2+1];

int build(int l,int r)
{
    int x=++cnt;
    t[x].v.k=0,t[x].v.b=1e9;
    t[x].l=l,t[x].r=r;
    if(l==r)
        return x;
    int mid=(l+r)>>1;
    t[x].ls=build(l,mid);
    t[x].rs=build(mid+1,r);
    return x;
}

void change(int x,Line v)
{
    if(!t[x].v.k)
    {
        t[x].v=v;
        return;
    }
    int mid=(t[x].l+t[x].r)>>1;
    if(t[x].v.eval(mid)>v.eval(mid))
        swap(t[x].v,v);
    if(t[x].ls&&v.eval(t[x].l)<t[x].v.eval(t[x].l))
        change(t[x].ls,v);
    if(t[x].rs&&v.eval(t[x].r)<t[x].v.eval(t[x].r))
        change(t[x].rs,v);
}

long long qry(int x,int p)
{
    if(t[x].l==t[x].r)
        return t[x].v.eval(p);
    int mid=(t[x].l+t[x].r)>>1;
    if(p<=mid)
        return min(t[x].v.eval(p),qry(t[x].ls,p));
    else
        return min(t[x].v.eval(p),qry(t[x].rs,p));
}

void solve()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            g[i][j]=1e9;
    for(int j=1;j<=m;j++)
    {
        int la=-1;
        for(int i=1;i<=n;i++)
        {
            if(s[i][j]=='1')
                la=i;
            if(la!=-1)
                g[i][j]=min(g[i][j],1ll*(i-la)*(i-la));
        }
        la=-1;
        for(int i=n;i>=1;i--)
        {
            if(s[i][j]=='1')
                la=i;
            if(la!=-1)
                g[i][j]=min(g[i][j],1ll*(i-la)*(i-la));
        }
    }
    for(int i=1;i<=n;i++)
        le[i]=0;
    for(int j=2;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
            le[i]=(s[i][j-1]=='1'?j-1:le[i]);
        /*
        (j - le[p])^2 + - 2 * p * i + p * p + i * i
        */
        cnt=0;
        build(1,n);
        for(int p=1;p<=n;p++)
            if(le[p])
                change(1,{-2*p,p*p+(j-le[p])*(j-le[p])});
        for(int i=1;i<=n;i++)
            g[i][j]=min(g[i][j],qry(1,i)+i*i);
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    n++,m++;
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            ans[i][j]=1e9;
    solve();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            ans[i][j]=min(ans[i][j],g[i][j]);
    for(int i=1;i<=n;i++)
        reverse(s[i]+1,s[i]+m+1);
    solve();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            ans[i][j]=min(ans[i][j],g[i][m-j+1]);
    long long sum=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            sum+=ans[i][j];
            // printf("%lld%c",ans[i][j]," \n"[j==m]);
        }
    printf("%lld\n",sum);
}