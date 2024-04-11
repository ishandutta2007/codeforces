#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll Mod=998244353;
const ll pmr=3;
ll fp(ll a,ll k)
{
    if(k<0)a=fp(a,Mod-2),k=-k;
    ll res=1;
    while(k)
    {
        if(k&1)res=res*a%Mod;
        a=a*a%Mod;
        k>>=1;
    }
    return res;
}
void change(ll y[],int len)
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
void fft(ll y[],int len,int on)
{
    change(y,len);
    for(int h=2;h<=len;h<<=1)
    {
        ll wn=fp(pmr,-on*(Mod-1)/h);
        for(int j=0;j<len;j+=h)
        {
            ll w=1;
            for(int k=j;k<j+h/2;k++)
            {
                ll u=y[k],v=w*y[k+h/2]%Mod;
                y[k]=(u+v)%Mod;
                y[k+h/2]=(u-v+Mod)%Mod;
                w=w*wn%Mod;
            }
        }
    }
    if(on==-1)
    {
        ll tmp=fp(len,-1);
        for(int i=0;i<len;i++)
            y[i]=y[i]*tmp%Mod;
    }
}
ll tmp[1<<10];
void fft2D(ll y[][1<<10],int len,int on)
{
    for(int i=0;i<len;i++)
        fft(y[i],len,on);
    for(int j=0;j<len;j++)
    {
        for(int i=0;i<len;i++)
            tmp[i]=y[i][j];
        fft(tmp,len,on);
        for(int i=0;i<len;i++)
            y[i][j]=tmp[i];
    }
}
ll x1[1<<10][1<<10],x2[1<<10][1<<10],val[1<<10][1<<10];
char s[1<<10][1<<10],t[1<<10][1<<10];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    int r,c;
    scanf("%d%d",&r,&c);
    for(int i=0;i<r;i++)
        scanf("%s",t[i]);
    for(int i=0;i<(1<<10);i++)
        for(int j=0;j<(1<<10);j++)
            x1[i][j]=s[i%n][j%m];
    memset(x2,0,sizeof(x2));
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            x2[((1<<10)-i)%(1<<10)][((1<<10)-j)%(1<<10)]=t[i][j];
    fft2D(x1,1<<10,1),fft2D(x2,1<<10,1);
    for(int i=0;i<(1<<10);i++)
        for(int j=0;j<(1<<10);j++)
            x1[i][j]=x1[i][j]*x2[i][j]%Mod;
    fft2D(x1,1<<10,-1);
    for(int i=0;i<(1<<10);i++)
        for(int j=0;j<(1<<10);j++)
            val[i][j]=(val[i][j]+2*x1[i][j]*'?')%Mod;
    for(int i=0;i<(1<<10);i++)
        for(int j=0;j<(1<<10);j++)
            x1[i][j]=1LL*s[i%n][j%m]*s[i%n][j%m];
    memset(x2,0,sizeof(x2));
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            x2[((1<<10)-i)%(1<<10)][((1<<10)-j)%(1<<10)]=t[i][j];
    fft2D(x1,1<<10,1),fft2D(x2,1<<10,1);
    for(int i=0;i<(1<<10);i++)
        for(int j=0;j<(1<<10);j++)
            x1[i][j]=x1[i][j]*x2[i][j]%Mod;
    fft2D(x1,1<<10,-1);
    for(int i=0;i<(1<<10);i++)
        for(int j=0;j<(1<<10);j++)
            val[i][j]=(val[i][j]+x1[i][j])%Mod;
    for(int i=0;i<(1<<10);i++)
        for(int j=0;j<(1<<10);j++)
            x1[i][j]=s[i%n][j%m];
    memset(x2,0,sizeof(x2));
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            x2[((1<<10)-i)%(1<<10)][((1<<10)-j)%(1<<10)]=1LL*t[i][j]*t[i][j];
    fft2D(x1,1<<10,1),fft2D(x2,1<<10,1);
    for(int i=0;i<(1<<10);i++)
        for(int j=0;j<(1<<10);j++)
            x1[i][j]=x1[i][j]*x2[i][j]%Mod;
    fft2D(x1,1<<10,-1);
    for(int i=0;i<(1<<10);i++)
        for(int j=0;j<(1<<10);j++)
            val[i][j]=(val[i][j]-2*x1[i][j])%Mod;
    for(int i=0;i<n+r;i++)
        for(int j=0;j<m+c;j++)
            x1[i][j]=1LL*s[i%n][j%m]*s[i%n][j%m];
    for(int i=0;i<n+r;i++)
        for(int j=0;j<m+c;j++)
        {
            if(i)x1[i][j]+=x1[i-1][j];
            if(j)x1[i][j]+=x1[i][j-1];
            if(i && j)x1[i][j]-=x1[i-1][j-1];
            x1[i][j]%=Mod;
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            ll now=x1[i+r-1][j+c-1];
            if(i)now-=x1[i-1][j+c-1];
            if(j)now-=x1[i+r-1][j-1];
            if(i && j)now+=x1[i-1][j-1];
            val[i][j]=(val[i][j]-now*'?')%Mod;
        }
    ll sum=0;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            sum-=1LL*t[i][j]*t[i][j]*'?',sum+=1LL*t[i][j]*t[i][j]*t[i][j];
    for(int i=0;i<n;i++,printf("\n"))
        for(int j=0;j<m;j++)
            printf("%d",(val[i][j]+sum)%Mod==0);
    return 0;
}