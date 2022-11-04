#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN=100005;
const int MAXT=1000000000;
map<int,int>mp;
int get_id(int x)
{
    return mp[x] ? mp[x] : mp[x]=(int)mp.size();
}
struct node
{
    int v,lson,rson;
}s[MAXN<<5];
int root[MAXN],tot=0;
void push_up(int n)
{
    s[n].v=s[s[n].lson].v+s[s[n].rson].v;
}
void update(int p,int v,int tl,int tr,int n)
{
    if(tl==p && tr==p+1)
    {
        s[n].v+=v;
        return;
    }
    int tm=(tl+tr)>>1;
    if(p<tm)
    {
        if(!s[n].lson)s[n].lson=++tot;
        update(p,v,tl,tm,s[n].lson);
    }
    else
    {
        if(!s[n].rson)s[n].rson=++tot;
        update(p,v,tm,tr,s[n].rson);
    }
    push_up(n);
}
int query(int l,int r,int tl,int tr,int n)
{
    if(!n)return 0;
    if(l==tl && r==tr)return s[n].v;
    int tm=(tl+tr)>>1;
    if(r<=tm)return query(l,r,tl,tm,s[n].lson);
    if(l>=tm)return query(l,r,tm,tr,s[n].rson);
    return query(l,tm,tl,tm,s[n].lson)+query(tm,r,tm,tr,s[n].rson);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        root[i]=++tot;
    for(int i=1;i<=n;i++)
    {
        int a,t,x;
        scanf("%d%d%d",&a,&t,&x);
        x=get_id(x);
        if(a<=2)update(t,3-a*2,1,MAXT+1,root[x]);
        else printf("%d\n",query(1,t+1,1,MAXT+1,root[x]));
    }
    return 0;
}