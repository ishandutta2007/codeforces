#include<bits/stdc++.h>
using namespace std;

const int N=2e2+1e1+7,P=998244353;

int n,m,k,t;

struct Matrix{

    int a[N][N];

    void init()
    {
        for(int i=1;i<=t;i++)
            a[i][i]=1;
    }

    void clear()
    {
        for(int i=1;i<=t;i++)
            for(int j=1;j<=t;j++)
                a[i][j]=0;
    }
}A,G,B;

void inc(int &a,int b)
{
    a+=b;
    a>=P?a-=P:0;
}

Matrix operator *(const Matrix &a,const Matrix &b)
{
    Matrix ret;
    ret.clear();
    for(int i=1;i<=t;i++)
        for(int j=1;j<=t;j++)
            for(int k=1;k<=t;k++)
                inc(ret.a[i][j],1ll*a.a[i][k]*b.a[k][j]%P);
    return ret;
}

Matrix qpow(Matrix a,int b)
{
    Matrix ret;
    ret.clear(),ret.init();
    while(b)
    {
        if(b&1)
            ret=ret*a;
        b>>=1;
        a=a*a;
    }
    return ret;
}

int deg[N];

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    t=n*2;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        deg[u]++,deg[v]++;
        G.a[u][v]=G.a[v][u]=1;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            A.a[i][j+n]=G.a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            B.a[i][j]=G.a[i][j];
    for(int i=1;i<=n;i++)
        B.a[i][i+n]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            B.a[i+n][j]=(i==j?(1+P-deg[i])%P:0);
    G=G*G;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            A.a[i][j]=(G.a[i][j]-(i==j?deg[i]:0))%P;
    if(k==1)
        puts("0");
    else
    {
        Matrix ans=A*qpow(B,k-2);
        int f=0;
        for(int i=1;i<=n;i++)
            inc(f,ans.a[i][i]);
        printf("%d\n",f);
    }
}