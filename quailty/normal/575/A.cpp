#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=50005;
ll Mod;
struct Matrix
{
    ll a[2][2];
    void clear()
    {
        memset(a,0,sizeof(a));
    }
    void init()
    {
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                a[i][j]=(i==j)%Mod;
    }
    Matrix operator * (const Matrix &B)const
    {
        Matrix C;
        C.clear();
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    C.a[i][j]=(C.a[i][j]+a[i][k]*B.a[k][j])%Mod;
        return C;
    }
    Matrix operator ^ (const ll &p)const
    {
        Matrix res,A=(*this);
        res.init();
        ll k=p;
        while(k)
        {
            if(k&1)res=res*A;
            A=A*A;
            k>>=1;
        }
        return res;
    }
}v[MAXN<<2];
ll s[MAXN],now[MAXN];
void pushUp(int n)
{
    v[n]=v[n<<1|1]*v[n<<1];
}
void build(int l,int r,int n)
{
    if(l==r)
    {
        v[n]=Matrix{now[l+1],now[l],1,0};
        return;
    }
    int m=(l+r)/2;
    build(l,m,n<<1);
    build(m+1,r,n<<1|1);
    pushUp(n);
}
void update(int p,Matrix c,int l,int r,int n)
{
    if(l==r)
    {
        v[n]=c;
        return;
    }
    int m=(l+r)/2;
    if(p<=m)update(p,c,l,m,n<<1);
    else update(p,c,m+1,r,n<<1|1);
    pushUp(n);
}
struct val
{
    ll p,q,v;
    bool operator < (const val &rhs)const
    {
        return p<rhs.p;
    }
}t[MAXN<<1];
int main()
{
    ll k;
    scanf("%lld%lld",&k,&Mod);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",&s[i]);
    int m,cnt=0;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        ll b,c;
        scanf("%lld%lld",&b,&c);
        if(b>k)continue;
        t[cnt++]=val{b/n,b%n,c};
        if(b%n==n-1)t[cnt++]=val{b/n+1,-1,c};
    }
    m=cnt;
    if(k==0)return 0*printf("0");
    Matrix res;
    res.init();
    for(int i=1;i<n && i<k;i++)
        res=Matrix{s[i],s[i-1],1,0}*res;
    if(k<=n)return 0*printf("%lld",res.a[0][0]);
    for(int i=0;i<=n;i++)
        now[i]=s[(i+n-1)%n];
    Matrix cir;
    cir.init();
    for(int i=0;i<n;i++)
        cir=Matrix{now[i+1],now[i],1,0}*cir;
    build(0,n-1,1);
    sort(t,t+m);
    ll la=0,ed=k/n;
    for(int i=0,j=0;i<m && t[i].p<ed;i=j)
    {
        res=(cir^(t[i].p-la-1))*res;
        la=t[i].p;
        while(j<m && t[i].p==t[j].p)j++;
        for(int k=i;k<j;k++)
            now[t[k].q+1]=t[k].v;
        for(int k=i;k<j;k++)
        {
            ll loc=t[k].q;
            if(loc>=0)update(loc,Matrix{now[loc+1],now[loc],1,0},0,n-1,1);
            if(loc<n-1)update(loc+1,Matrix{now[loc+2],now[loc+1],1,0},0,n-1,1);
        }
        res=v[1]*res;
        for(int k=i;k<j;k++)
            now[t[k].q+1]=s[(t[k].q+n)%n];
        for(int k=i;k<j;k++)
        {
            ll loc=t[k].q;
            if(loc>=0)update(loc,Matrix{now[loc+1],now[loc],1,0},0,n-1,1);
            if(loc<n-1)update(loc+1,Matrix{now[loc+2],now[loc+1],1,0},0,n-1,1);
        }
    }
    res=(cir^(ed-la-1))*res;
    for(int i=m-1;i>=0 && t[i].p==ed;i--)
        now[t[i].q+1]=t[i].v;
    k%=n;
    for(int i=0;i<k;i++)
        res=Matrix{now[i+1],now[i],1,0}*res;
    printf("%lld",res.a[0][0]);
    return 0;
}