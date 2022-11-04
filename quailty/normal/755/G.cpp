#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXK=1<<15;
const int Mod=998244353;
const int g=3;
int fp(int a,int k)
{
    if(k<0)a=fp(a,Mod-2),k=-k;
    int res=1;
    while(k)
    {
        if(k&1)res=1LL*res*a%Mod;
        a=1LL*a*a%Mod;
        k>>=1;
    }
    return res;
}
void change(int y[],int len)
{
    for(int i=1,j=len/2;i<len-1;i++)
    {
        if(i<j)swap(y[i],y[j]);
        int k=len/2;
        while(j>=k)
        {
            j-=k;
            k/=2;
        }
        if(j<k)j+=k;
    }
}
void fft(int y[],int len,int on)
{
    change(y,len);
    for(int h=2;h<=len;h<<=1)
    {
        int wn=fp(g,-on*(Mod-1)/h);
        for(int j=0;j<len;j+=h)
        {
            int w=1;
            for(int k=j;k<j+h/2;k++)
            {
                int u=y[k],v=1LL*w*y[k+h/2]%Mod;
                y[k]=(u+v)%Mod;
                y[k+h/2]=(u-v+Mod)%Mod;
                w=1LL*w*wn%Mod;
            }
        }
    }
    if(on==-1)
    {
        int t=fp(len,-1);
        for(int i=0;i<len;i++)
            y[i]=1LL*y[i]*t%Mod;
    }
}
int a[2][2][MAXK],b[2][2][MAXK],t[2][2][MAXK];
int da[2][2][MAXK<<1],db[2][2][MAXK<<1],dt[2][2][MAXK<<1];
void solve(int n)
{
    a[0][0][0]=a[1][1][0]=1;
    b[0][0][0]=b[0][0][1]=1;
    b[0][1][1]=b[1][0][0]=1;
    while(n)
    {
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
            {
                for(int k=0;k<(MAXK<<1);k++)
                    db[i][j][k]=(k<MAXK ? b[i][j][k] : 0);
                fft(db[i][j],MAXK<<1,1);
            }
        if(n&1)
        {
            for(int i=0;i<2;i++)
                for(int j=0;j<2;j++)
                {
                    for(int k=0;k<(MAXK<<1);k++)
                        da[i][j][k]=(k<MAXK ? a[i][j][k] : 0);
                    fft(da[i][j],MAXK<<1,1);
                }
            memset(dt,0,sizeof(dt));
            for(int i=0;i<2;i++)
                for(int j=0;j<2;j++)
                    for(int k=0;k<2;k++)
                        for(int _=0;_<(MAXK<<1);_++)
                            dt[i][j][_]=(dt[i][j][_]+1LL*da[i][k][_]*db[k][j][_])%Mod;
            for(int i=0;i<2;i++)
                for(int j=0;j<2;j++)
                {
                    fft(dt[i][j],MAXK<<1,-1);
                    for(int _=0;_<MAXK;_++)
                        t[i][j][_]=dt[i][j][_];
                }
            memcpy(a,t,sizeof(t));
        }
        memset(dt,0,sizeof(dt));
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    for(int _=0;_<(MAXK<<1);_++)
                        dt[i][j][_]=(dt[i][j][_]+1LL*db[i][k][_]*db[k][j][_])%Mod;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
            {
                fft(dt[i][j],MAXK<<1,-1);
                for(int _=0;_<MAXK;_++)
                    t[i][j][_]=dt[i][j][_];
            }
        memcpy(b,t,sizeof(t));
        n>>=1;
    }
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    solve(n);
    for(int i=1;i<=k;i++)
        printf("%d ",a[0][0][i]);
    return 0;
}