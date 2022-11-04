#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=300005;
ll a[MAXN];
int cmp(ll a,ll b)
{
    if(a<b)return 0;
    if(a>b)return 2;
    return 1;
}
struct info
{
    ll v[2];
    int len[4],ud[2];
    info(){}
    info(ll vl,ll vr,int lenl,int lenr,int lenm,int lent,int udl,int udr)
    {
        v[0]=vl,v[1]=vr;
        len[0]=lenl,len[1]=lenr,len[2]=lenm,len[3]=lent;
        ud[0]=udl,ud[1]=udr;
    }
    info operator + (const ll &t)const
    {
        return info(v[0]+t,v[1]+t,len[0],len[1],len[2],len[3],ud[0],ud[1]);
    }
    info operator + (const info &t)const
    {
        int tlen[4]={len[0],t.len[1],max(len[2],t.len[2]),len[3]+t.len[3]};
        if(len[0]==len[3])
        {
            if(ud[1]&1)
            {
                if(v[1]<t.v[0])tlen[0]=len[0]+t.len[0];
                if(v[1]>t.v[0])tlen[0]=len[0]+(t.ud[0]&4 ? t.len[0] : 1);
            }
            else if((ud[1]&4)&&(v[1]>t.v[0]))
                tlen[0]=len[0]+(t.ud[0]&4 ? t.len[0] : 1);
        }
        if(t.len[1]==t.len[3])
        {
            if(t.ud[0]&4)
            {
                if(v[1]>t.v[0])tlen[1]=t.len[1]+len[1];
                if(v[1]<t.v[0])tlen[1]=t.len[1]+(ud[1]&1 ? len[1] : 1);
            }
            else if((t.ud[0]&1)&&(v[1]<t.v[0]))
                tlen[1]=t.len[1]+(ud[1]&1 ? len[1] : 1);
        }
        tlen[2]=max(tlen[2],tlen[0]);
        tlen[2]=max(tlen[2],tlen[1]);
        tlen[2]=max(tlen[2],len[1]);
        tlen[2]=max(tlen[2],t.len[0]);
        if(v[1]<t.v[0])
            tlen[2]=max(tlen[2],(ud[1]&1 ? len[1] : 1)+t.len[0]);
        if(v[1]>t.v[0])
            tlen[2]=max(tlen[2],len[1]+(t.ud[0]&4 ? t.len[0] : 1));
        int tud[2]={ud[0],t.ud[1]};
        if(tud[0]==7)tud[0]=1<<cmp(v[0],t.v[0]);
        if(tud[1]==7)tud[1]=1<<cmp(v[1],t.v[1]);
        return info(v[0],t.v[1],tlen[0],tlen[1],tlen[2],tlen[3],tud[0],tud[1]);
    }
}s[MAXN<<2];
ll lz[MAXN<<2];
void pushUp(int n)
{
    s[n]=s[n<<1]+s[n<<1|1];
}
void pushDown(int n)
{
    if(!lz[n])return;
    s[n<<1]=s[n<<1]+lz[n];
    s[n<<1|1]=s[n<<1|1]+lz[n];
    lz[n<<1]+=lz[n];
    lz[n<<1|1]+=lz[n];
    lz[n]=0;
}
void build(int l,int r,int n)
{
    int m=(l+r)/2;
    lz[n]=0;
    if(l==r)
    {
        s[n]=info(a[l],a[l],1,1,1,1,7,7);
        return;
    }
    build(l,m,n<<1);
    build(m+1,r,n<<1|1);
    pushUp(n);
}
void update(int ql,int qr,int l,int r,ll v,int n)
{
    if(ql==l && qr==r)
    {
        s[n]=s[n]+v;
        lz[n]+=v;
        return;
    }
    pushDown(n);
    int m=(l+r)/2;
    if(qr<=m)update(ql,qr,l,m,v,n<<1);
    else if(ql>m)update(ql,qr,m+1,r,v,n<<1|1);
    else
    {
        update(ql,m,l,m,v,n<<1);
        update(m+1,qr,m+1,r,v,n<<1|1);
    }
    pushUp(n);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    build(1,n,1);
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int l,r;
        ll d;
        scanf("%d%d%I64d",&l,&r,&d);
        update(l,r,1,n,d,1);
        printf("%d\n",s[1].len[2]);
    }
    return 0;
}