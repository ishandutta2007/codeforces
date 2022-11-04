#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll Mod=1000000007;
int x;
struct Matrix
{
    ll a[100][100];
    Matrix()
    {
        memset(a,0,sizeof(a));
    }
    void init()
    {
        for(int i=0;i<x;i++)a[i][i]=1;
    }
    Matrix operator * (const Matrix &B)const
    {
        Matrix C;
        for(int i=0;i<x;i++)
            for(int j=0;j<x;j++)
                for(int k=0;k<x;k++)
                    C.a[i][j]=(C.a[i][j]+a[i][k]*B.a[k][j])%Mod;
        return C;
    }
    Matrix operator ^ (const int &t)const
    {
        Matrix res,A=(*this);
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
int cnt[10];
int main()
{
    int n,b,k;
    scanf("%d%d%d%d",&n,&b,&k,&x);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        cnt[a]++;
    }
    Matrix A;
    for(int i=0;i<x;i++)
        for(int j=0;j<10;j++)
            A.a[i][(i*10+j)%x]+=cnt[j];
    A=A^b;
    printf("%I64d",A.a[0][k]);
    return 0;
}