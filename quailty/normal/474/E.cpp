#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
ll h[MAXN],th[MAXN];
int nxt[MAXN];
struct data
{
    int len,loc;
    data(){}
    data(int _len,int _loc):len(_len),loc(_loc){}
    data operator + (const data &t)const
    {
        return len>=t.len ? *this : t;
    }
};
struct node
{
    int l,r,m;
    data v;
}s[MAXN<<2];
void push_up(int n)
{
    s[n].v=s[n<<1].v+s[n<<1|1].v;
}
void build(int l,int r,int n)
{
    int m=(l+r)>>1;
    s[n].l=l;
    s[n].r=r;
    s[n].m=m;
    if(r-l==1)
    {
        s[n].v=data(0,0);
        return;
    }
    build(l,m,n<<1);
    build(m,r,n<<1|1);
    push_up(n);
}
void update(int p,data v,int n)
{
    if(s[n].l==p && s[n].r==p+1)
    {
        s[n].v=s[n].v+v;
        return;
    }
    if(p<s[n].m)update(p,v,n<<1);
    else update(p,v,n<<1|1);
    push_up(n);
}
data query(int l,int r,int n)
{
    if(r<=l)return data(0,0);
    if(s[n].l==l && s[n].r==r)return s[n].v;
    if(r<=s[n].m)return query(l,r,n<<1);
    if(l>=s[n].m)return query(l,r,n<<1|1);
    return query(l,s[n].m,n<<1)+query(s[n].m,r,n<<1|1);
}
int main()
{
    int n;
    ll d;
    scanf("%d%I64d",&n,&d);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&h[i]);
    memcpy(th,h+1,n*sizeof(ll));
    sort(th,th+n);
    int tot=unique(th,th+n)-th;
    build(1,tot+1,1);
    int res=0,st=0;
    for(int i=n;i>=1;i--)
    {
        int l=upper_bound(th,th+tot,h[i]-d)-th;
        int r=lower_bound(th,th+tot,h[i]+d)-th+1;
        data t=query(1,l+1,1)+query(r,tot+1,1);
        nxt[i]=t.loc;
        if(res<t.len+1)
        {
            res=t.len+1;
            st=i;
        }
        int p=lower_bound(th,th+tot,h[i])-th+1;
        update(p,data(t.len+1,i),1);
    }
    printf("%d\n",res);
    for(int i=st;i;i=nxt[i])
        printf("%d ",i);
    return 0;
}