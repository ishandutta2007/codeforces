#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
const int Mod=1000000007;
int a[MAXN];
struct Matrix
{
    int a[2][2];
    Matrix()
    {
        memset(a,0,sizeof(a));
    }
    void init()
    {
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                a[i][j]=(i==j);
    }
    Matrix operator + (const Matrix &B)const
    {
        Matrix C;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                C.a[i][j]=(a[i][j]+B.a[i][j])%Mod;
        return C;
    }
    Matrix operator * (const Matrix &B)const
    {
        Matrix C;
        for(int i=0;i<2;i++)
            for(int k=0;k<2;k++)
                for(int j=0;j<2;j++)
                    C.a[i][j]=(C.a[i][j]+1LL*a[i][k]*B.a[k][j])%Mod;
        return C;
    }
    Matrix operator ^ (const int &t)const
    {
        Matrix A=(*this),res;
        res.init();
        int p=t;
        while(p)
        {
            if(p&1)res=res*A;
            A=A*A;
            p>>=1;
        }
        return res;
    }
};
Matrix f,s[MAXN<<2],lz[MAXN<<2];
void pushUp(int n)
{
    s[n]=s[n<<1]+s[n<<1|1];
}
void pushDown(int n)
{
    s[n<<1]=lz[n]*s[n<<1];
    s[n<<1|1]=lz[n]*s[n<<1|1];
    lz[n<<1]=lz[n]*lz[n<<1];
    lz[n<<1|1]=lz[n]*lz[n<<1|1];
    lz[n].init();
}
void build(int l,int r,int n)
{
    lz[n].init();
    if(l==r)
    {
        s[n]=f^(a[l]-1);
        return;
    }
    int m=(l+r)/2;
    build(l,m,n<<1);
    build(m+1,r,n<<1|1);
    pushUp(n);
}
void update(int ql,int qr,int l,int r,Matrix v,int n)
{
    if(l==ql && r==qr)
    {
        s[n]=v*s[n];
        lz[n]=v*lz[n];
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
int query(int ql,int qr,int l,int r,int n)
{
    if(l==ql && r==qr)return s[n].a[0][0];
    pushDown(n);
    int m=(l+r)/2;
    if(qr<=m)return query(ql,qr,l,m,n<<1);
    if(ql>m)return query(ql,qr,m+1,r,n<<1|1);
    return (query(ql,m,l,m,n<<1)+query(m+1,qr,m+1,r,n<<1|1))%Mod;
}
void init()
{
    f.a[0][0]=1,f.a[0][1]=1;
    f.a[1][0]=1,f.a[1][1]=0;
}
int main()
{
    init();
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build(1,n,1);
    for(int i=1;i<=m;i++)
    {
        int tp,l,r;
        scanf("%d%d%d",&tp,&l,&r);
        if(tp==1)
        {
            int x;
            scanf("%d",&x);
            update(l,r,1,n,f^x,1);
        }
        else printf("%d\n",query(l,r,1,n,1));
    }
    return 0;
}