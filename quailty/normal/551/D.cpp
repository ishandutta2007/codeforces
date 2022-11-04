#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll Mod;
struct Matrix
{
    ll a[2][2];
    Matrix()
    {
        memset(a,0,sizeof(a));
    }
    void init()
    {
        for(int i=0;i<2;i++)a[i][i]=1;
    }
    Matrix operator * (const Matrix &B)const
    {
        Matrix C;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    C.a[i][j]=(C.a[i][j]+a[i][k]*B.a[k][j])%Mod;
        return C;
    }
    Matrix operator ^ (const ll &t)const
    {
        Matrix res,A=(*this);
        res.init();
        ll p=t;
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
    ll n,k;
    int l;
    scanf("%I64d%I64d%d%I64d",&n,&k,&l,&Mod);
    if(l>=63 || k<(1LL<<l))
    {
        Matrix F,B;
        F.a[0][0]=F.a[0][1]=F.a[1][0]=1;
        F=F^(n+1);
        B.a[0][0]=2;
        B=B^n;
        ll ans=1LL%Mod;
        for(int i=0;i<min(62,l);i++)
        {
            if(k&(1LL<<i))
            {
                ans=ans*(B.a[0][0]-F.a[0][0])%Mod;
                ans=(ans+Mod)%Mod;
            }
            else
            {
                ans=ans*F.a[0][0]%Mod;
            }
        }
        for(int i=min(62,l);i<l;i++)
        {
            ans=ans*F.a[0][0]%Mod;
            ans=(ans+Mod)%Mod;
        }
        //printf("%I64d %I64d\n",B.a[0][0],F.a[0][0]);
        printf("%I64d\n",ans);
    }
    else printf("0\n");
    return 0;
}