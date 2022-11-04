#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll Mod=1000000007;
struct Matrix
{
    ll a[100][100];
    Matrix()
    {
        memset(a,0,sizeof(a));
    }
    void init()
    {
        for(int i=0;i<100;i++)a[i][i]=1;
    }
    Matrix operator * (const Matrix &B)const
    {
        Matrix C;
        for(int i=0;i<100;i++)
            for(int k=0;k<100;k++)
                for(int j=0;j<100;j++)
                    (C.a[i][j]+=a[i][k]*B.a[k][j])%=Mod;
        return C;
    }
    Matrix operator ^ (const ll &t)const
    {
        Matrix A=(*this),res;
        res.init();
        ll p=t;
        while(p)
        {
            if(p&1)res=res*A;
            A=A*A;
            p>>=1;
        }
        return res;
    }
};
ll a[105];
int main()
{
    ll n,k;
    scanf("%I64d%I64d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%I64d",&a[i]);
    Matrix A;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(__builtin_popcountll(a[i]^a[j])%3==0)
                A.a[i][j]++;
    A=A^(k-1);
    ll res=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            (res+=A.a[i][j])%=Mod;
    return 0*printf("%I64d",res);
}