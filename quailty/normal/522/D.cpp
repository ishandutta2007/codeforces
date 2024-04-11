#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN=500005;
const int INF=0x3f3f3f3f;
int rt[MAXN],tot;
struct node
{
    int v,ls,rs;
}s[MAXN*30];
void push_up(int n)
{
    s[n].v=min(s[s[n].ls].v,s[s[n].rs].v);
}
void build(int l,int r,int &n)
{
    n=++tot;
    if(r-l==1)
    {
        s[n].v=INF;
        return;
    }
    int m=(l+r)>>1;
    build(l,m,s[n].ls);
    build(m,r,s[n].rs);
    push_up(n);
}
void update(int tl,int tr,int p,int v,int ln,int &n)
{
    s[n=++tot]=s[ln];
    if(tl==p && tr==p+1)
    {
        s[n].v=min(s[n].v,v);
        return;
    }
    int tm=(tl+tr)>>1;
    if(p<tm)update(tl,tm,p,v,s[ln].ls,s[n].ls);
    else update(tm,tr,p,v,s[ln].rs,s[n].rs);
    push_up(n);
}
int query(int tl,int tr,int l,int r,int n)
{
    if(tl==l && tr==r)return s[n].v;
    int tm=(tl+tr)>>1;
    if(r<=tm)return query(tl,tm,l,r,s[n].ls);
    if(l>=tm)return query(tm,tr,l,r,s[n].rs);
    return min(query(tl,tm,l,tm,s[n].ls),query(tm,tr,tm,r,s[n].rs));
}
map<int,int>mp;
int ans=0;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    tot=0;
    build(1,n+1,rt[0]);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        rt[i]=rt[i-1];
        if(mp[a])update(1,n+1,mp[a],i-mp[a],rt[i-1],rt[i]);
        mp[a]=i;
    }
    while(m--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        //l^=ans,r^=ans;
        ans=query(1,n+1,l,r+1,rt[r]);
        ans=(ans==INF ? -1 : ans);
        printf("%d\n",ans);
    }
    return 0;
}