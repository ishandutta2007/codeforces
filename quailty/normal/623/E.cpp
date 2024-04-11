#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef long double db;
const int MAXN=30005;
const int MAXL=65536;
const db PI=acos(-1.0);
struct Complex
{
    db x,y;
    Complex(db _x=0,db _y=0):x(_x),y(_y){}
    Complex operator + (const Complex &t)const
    {
        return Complex(x+t.x,y+t.y);
    }
    Complex operator - (const Complex &t)const
    {
        return Complex(x-t.x,y-t.y);
    }
    Complex operator * (const Complex &t)const
    {
        return Complex(x*t.x-y*t.y,x*t.y+y*t.x);
    }
    Complex operator / (const db &t)const
    {
        return Complex(x/t,y/t);
    }
};
void change(Complex y[],int len)
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
void fft(Complex y[],int len,int on)
{
    change(y,len);
    for(int h=2;h<=len;h<<=1)
    {
        Complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j=0;j<len;j+=h)
        {
            Complex w(1,0);
            for(int k=j;k<j+h/2;k++)
            {
                Complex u=y[k];
                Complex v=w*y[k+h/2];
                y[k]=u+v;
                y[k+h/2]=u-v;
                w=w*wn;
            }
        }
    }
    if(on==-1)for(int i=0;i<len;i++)
        y[i]=y[i]/len;
}
const ll Mod=1000000007;
const ll Pat=sqrt(Mod);
Complex p[3][MAXL],q[2][MAXL];
void multiply(ll f[],int lenf,ll g[],int leng)
{
    int len=1;
    while(len<lenf+leng)len<<=1;
    for(int i=0;i<len;i++)
    {
        p[0][i]=(i<lenf ? f[i]/Pat : 0);
        p[1][i]=(i<lenf ? f[i]%Pat : 0);
        q[0][i]=(i<leng ? g[i]/Pat : 0);
        q[1][i]=(i<leng ? g[i]%Pat : 0);
    }
    for(int i=0;i<2;i++)
    {
        fft(p[i],len,1);
        fft(q[i],len,1);
    }
    for(int i=0;i<len;i++)
    {
        p[2][i]=p[0][i]*q[1][i]+p[1][i]*q[0][i];
        p[0][i]=p[0][i]*q[0][i];
        p[1][i]=p[1][i]*q[1][i];
    }
    for(int i=0;i<3;i++)
        fft(p[i],len,-1);
    for(int i=0;i<len;i++)
    {
        ll tmp[3];
        for(int j=0;j<3;j++)
            tmp[j]=(ll)(p[j][i].x+0.5)%Mod;
        f[i]=(tmp[0]*Pat*Pat+tmp[1]+tmp[2]*Pat)%Mod;
    }
}
ll fac[MAXN],inv[MAXN];
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
ll C(ll n,ll k)
{
    if(k>n)return 0;
    return fac[n]*inv[k]%Mod*inv[n-k]%Mod;
}
ll f[MAXL],g[MAXL],h[MAXL];
int main()
{
    for(int i=(fac[0]=1);i<MAXN;i++)
        fac[i]=i*fac[i-1]%Mod;
    for(int i=0;i<MAXN;i++)
        inv[i]=fp(fac[i],-1);
    ll n,k,r=1;
    scanf("%I64d%I64d",&n,&k);
    if(n>k)return 0*printf("0\n");
    for(int i=(f[0]=1);i<=k;i++)g[i]=inv[i];
    while(n)
    {
        if(n&1)
        {
            for(int i=0;i<=k;i++)
                f[i]=f[i]*fp(2,i*r)%Mod;
            multiply(f,k+1,g,k+1);
        }
        for(int i=0;i<=k;i++)
        {
            h[i]=g[i];
            g[i]=g[i]*fp(2,i*r)%Mod;
        }
        multiply(g,k+1,h,k+1);
        n>>=1,r<<=1;
    }
    ll res=0;
    for(int i=1;i<=k;i++)
        res=(res+f[i]*fac[i]%Mod*C(k,i))%Mod;
    return 0*printf("%I64d",res);
}