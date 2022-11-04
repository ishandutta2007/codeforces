#include<bits/stdc++.h>
using namespace std;
typedef long double db;
const int MAXN=100005;
db val[MAXN<<2],add[MAXN<<2],mul[MAXN<<2];
int a[MAXN],len[MAXN<<2];
void push_up(int n)
{
    val[n]=val[n<<1]+val[n<<1|1];
}
void push_down(int n)
{
    val[n<<1]=val[n<<1]*mul[n]+add[n]*len[n<<1];
    val[n<<1|1]=val[n<<1|1]*mul[n]+add[n]*len[n<<1|1];
    add[n<<1]=add[n<<1]*mul[n]+add[n];
    add[n<<1|1]=add[n<<1|1]*mul[n]+add[n];
    mul[n<<1]=mul[n<<1]*mul[n];
    mul[n<<1|1]=mul[n<<1|1]*mul[n];
    add[n]=0.0L,mul[n]=1.0L;
}
void build(int l,int r,int n)
{
    len[n]=r-l+1;
    add[n]=0.0L,mul[n]=1.0L;
    if(l==r)
    {
        val[n]=a[l];
        return;
    }
    int m=(l+r)/2;
    build(l,m,n<<1);
    build(m+1,r,n<<1|1);
    push_up(n);
}
void update(int ql,int qr,db tad,db tmu,int l,int r,int n)
{
    if(ql==l && qr==r)
    {
        val[n]=val[n]*tmu+tad*len[n];
        add[n]=add[n]*tmu+tad;
        mul[n]=mul[n]*tmu;
        return;
    }
    push_down(n);
    int m=(l+r)/2;
    if(qr<=m)update(ql,qr,tad,tmu,l,m,n<<1);
    else if(ql>m)update(ql,qr,tad,tmu,m+1,r,n<<1|1);
    else
    {
        update(ql,m,tad,tmu,l,m,n<<1);
        update(m+1,qr,tad,tmu,m+1,r,n<<1|1);
    }
    push_up(n);
}
db query(int ql,int qr,int l,int r,int n)
{
    if(ql==l && qr==r)return val[n];
    push_down(n);
    int m=(l+r)/2;
    if(qr<=m)return query(ql,qr,l,m,n<<1);
    if(ql>m)return query(ql,qr,m+1,r,n<<1|1);
    return query(ql,m,l,m,n<<1)+query(m+1,qr,m+1,r,n<<1|1);
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build(1,n,1);
    for(int i=1;i<=q;i++)
    {
        int ty;
        scanf("%d",&ty);
        if(ty==1)
        {
            int l[2],r[2];
            scanf("%d%d%d%d",&l[0],&r[0],&l[1],&r[1]);
            db lef=query(l[0],r[0],1,n,1)/(r[0]-l[0]+1);
            db rig=query(l[1],r[1],1,n,1)/(r[1]-l[1]+1);
//            printf("%.12f %.12f\n",(double)lef,(double)rig);
            update(l[0],r[0],rig/(r[0]-l[0]+1),1.0L*(r[0]-l[0])/(r[0]-l[0]+1),1,n,1);
            update(l[1],r[1],lef/(r[1]-l[1]+1),1.0L*(r[1]-l[1])/(r[1]-l[1]+1),1,n,1);
        }
        else
        {
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%.12f\n",(double)query(l,r,1,n,1));
        }
    }
    return 0;
}