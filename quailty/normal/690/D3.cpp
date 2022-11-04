#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll Mod=1000003;
struct Matrix
{
    ll a[101][101];
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
            for(int k=0;k<=100;k++)
                for(int j=0;j<=100;j++)
                    (C.a[i][j]+=a[i][k]*B.a[k][j])%=Mod;
        return C;
    }
    Matrix operator ^ (const ll &t)const
    {
        ll p=t;
        Matrix A=(*this),res;
        res.init();
        while(p)
        {
            if(p&1)res=res*A;
            A=A*A;
            p>>=1;
        }
        return res;
    }
};
ll dp[105],f[105];
int main()
{
    ll C,W,H;
    scanf("%I64d%I64d%I64d",&C,&W,&H);
    for(int i=(f[0]=1);i<=W;i++)
        f[i]=H*f[i-1]%Mod;
    for(int i=0;i<=W;i++)
    {
        for(int j=0;j<i;j++)
            (dp[i]+=dp[i-j-1]*f[j])%=Mod;
        (dp[i]+=f[i])%=Mod;
    }
    if(C<=W)return 0*printf("%I64d",dp[C]);
    /*
    for(int i=W+1;i<=C;i++)
        for(int j=0;j<=W;j++)
            (dp[i]+=dp[i-j-1]*f[j])%=Mod;
    return 0*printf("%I64d",dp[C]);
    */
    Matrix A;
    for(int i=0;i<=W;i++)
        A.a[0][i]=f[i];
    for(int i=1;i<=W;i++)
        A.a[i][i-1]=1;
    A=A^(C-W);
    ll res=0;
    for(int i=0;i<=W;i++)
        (res+=dp[W-i]*A.a[0][i])%=Mod;
    return 0*printf("%I64d",res);
}