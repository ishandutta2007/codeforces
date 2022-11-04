#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const db PI=acos(-1.0);
struct Complex
{
    db x,y;
    Complex(db x=0.0,db y=0.0):x(x),y(y){}
    Complex operator + (const Complex &b)const
    {
        return Complex(x+b.x,y+b.y);
    }
    Complex operator - (const Complex &b)const
    {
        return Complex(x-b.x,y-b.y);
    }
    Complex operator * (const Complex &b)const
    {
        return Complex(x*b.x-y*b.y,x*b.y+y*b.x);
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
                Complex t=w*y[k+h/2];
                y[k]=u+t;
                y[k+h/2]=u-t;
                w=w*wn;
            }
        }
    }
    if(on==-1)
        for(int i=0;i<len;i++)
            y[i].x/=len;
}
Complex x1[2000005],x2[2000005];
void multiply(int p[],int &dp,int q[],int dq)
{
    int len=1;
    while(len<=dp+dq)len<<=1;
    for(int i=0;i<=dp;i++)
        x1[i]=Complex(p[i],0);
    for(int i=dp+1;i<len;i++)
        x1[i]=Complex(0,0);
    for(int i=0;i<=dq;i++)
        x2[i]=Complex(q[i],0);
    for(int i=dq+1;i<len;i++)
        x2[i]=Complex(0,0);
    fft(x1,len,1);
    fft(x2,len,1);
    for(int i=0;i<len;i++)
        x1[i]=x1[i]*x2[i];
    fft(x1,len,-1);
    for(int i=0;i<=dp+dq;i++)
        p[i]=(int)(x1[i].x+0.5);
    for(int i=0;i<=dp+dq;i++)
        if(p[i]>0)p[i]=1;
    dp+=dq;
}
int a[1005],p[1000005],q[1000005];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    p[0]=1;
    for(int i=0;i<n;i++)
        q[a[i]]=1;
    int dp=0,dq=1000;
    while(k)
    {
        if(k&1)multiply(p,dp,q,dq);
        if(k>1)multiply(q,dq,q,dq);
        k>>=1;
    }
    for(int i=1;i<=1000000;i++)
        if(p[i]>0)printf("%d ",i);
    return 0;
}