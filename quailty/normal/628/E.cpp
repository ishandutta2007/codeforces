#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=3005;
char str[MAXN][MAXN];
int l[MAXN][MAXN],r[MAXN][MAXN],d[MAXN][MAXN];
void prepare(int n,int m)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(str[i][j]=='z')l[i][j]=l[i][j-1]+1;
            else l[i][j]=0;
        }
    for(int i=1;i<=n;i++)
        for(int j=m;j>=1;j--)
        {
            if(str[i][j]=='z')r[i][j]=r[i][j+1]+1;
            else r[i][j]=0;
        }
    for(int i=n;i>=1;i--)
        for(int j=1;j<=m;j++)
        {
            if(str[i][j]=='z')d[i][j]=d[i+1][j-1]+1;
            else d[i][j]=0;
        }
}
int rt[MAXN],tot;
struct node
{
    int v,ls,rs;
}s[MAXN*20];
void push_up(int n)
{
    s[n].v=s[s[n].ls].v+s[s[n].rs].v;
}
void build(int l,int r,int &n)
{
    n=++tot;
    int m=(l+r)>>1;
    if(r-l==1)
    {
        s[n].v=0;
        return;
    }
    build(l,m,s[n].ls);
    build(m,r,s[n].rs);
    push_up(n);
}
void update(int tl,int tr,int p,int ln,int &n)
{
    s[n=++tot]=s[ln];
    if(tl==p && tr==p+1)
    {
        s[n].v++;
        return;
    }
    int tm=(tl+tr)>>1;
    if(p<tm)update(tl,tm,p,s[ln].ls,s[n].ls);
    else update(tm,tr,p,s[ln].rs,s[n].rs);
    push_up(n);
}
int query(int tl,int tr,int l,int r,int n)
{
    if(tl==l && tr==r)return s[n].v;
    int tm=(tl+tr)>>1;
    if(r<=tm)return query(tl,tm,l,r,s[n].ls);
    if(l>=tm)return query(tm,tr,l,r,s[n].rs);
    return query(tl,tm,l,tm,s[n].ls)+query(tm,tr,tm,r,s[n].rs);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",str[i]+1);
    prepare(n,m);
    ll res=0;
    for(int i=2;i<=n+m;i++)
    {
        tot=0;
        build(1,n+m,rt[0]);
        int x=1,y=i-1;
        if(y>=m)
        {
            x+=y-m;
            y=m;
        }
        for(int c=1,tx=x,ty=y;tx<=n && ty>=1;c++,tx++,ty--)
        {
            rt[c]=rt[c-1];
            if(str[tx][ty]=='z')update(1,n+m,r[tx][ty]-c+n,rt[c-1],rt[c]);
        }
        for(int c=1,tx=x,ty=y;tx<=n && ty>=1;c++,tx++,ty--)
        {
            int len=min(l[tx][ty],d[tx][ty]);
            res+=query(1,n+m,n+1-c,n+m,rt[c+len-1])-query(1,n+m,n+1-c,n+m,rt[c-1]);
        }
    }
    printf("%I64d",res);
    return 0;
}