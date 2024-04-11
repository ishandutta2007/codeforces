#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Mod=1000000007;
int t[105];
ll dp[105];
struct Matrix
{
    ll a[105][105];
    Matrix()
    {
        memset(a,0,sizeof(a));
    }
    void init()
    {
        for(int i=0;i<=100;i++)a[i][i]=1;
    }
    Matrix operator * (const Matrix &B)const
    {
        Matrix C;
        for(int i=0;i<=100;i++)
            for(int j=0;j<=100;j++)
                for(int k=0;k<=100;k++)
                    C.a[i][j]=(C.a[i][j]+a[i][k]*B.a[k][j])%Mod;
        return C;
    }
    Matrix operator ^ (const int &t)const
    {
        Matrix res,A=(*this);
        res.init();
        int p=t;
        while(p>0)
        {
            if(p&1)res=res*A;
            A=A*A;
            p>>=1;
        }
        return res;
    }
};
int main()
{
    int n,x;
    scanf("%d%d",&n,&x);
    int d;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&d);
        t[d]++;
    }
    for(int i=0;i<100;i++)
    {
        dp[i]=1;
        for(int j=1;j<=i;j++)
        {
            dp[i]=(dp[i]+t[j]*dp[i-j])%Mod;
        }
    }
    if(x<100)printf("%I64d\n",dp[x]);
    else
    {
        Matrix A;
        for(int i=0;i<100;i++)A.a[0][i]=t[i+1];
        A.a[0][100]=1;
        for(int i=1;i<100;i++)A.a[i][i-1]=1;
        A.a[100][100]=1;
        A=A^(x-99);
        ll ans=0;
        for(int i=0;i<100;i++)
        {
            ans=(ans+A.a[0][i]*dp[99-i])%Mod;
        }
        ans=(ans+A.a[0][100])%Mod;
        printf("%I64d\n",ans);
    }
    return 0;
}