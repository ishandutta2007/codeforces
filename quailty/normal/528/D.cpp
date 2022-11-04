#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const db PI=acos(-1.0);
struct Complex
{
    db x,y;
    Complex(db _x=0.0,db _y=0.0):x(_x),y(_y){}
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
const char ch[4]={'A','C','G','T'};
int lens,lent,k;
char s[200005],t[200005];
int es[200005],ps[200005];
Complex ss[600005],tt[600005];
int cnt[4][200005];
void work(int id)
{
    memset(es,0,sizeof(es));
    memset(ps,0,sizeof(ps));
    memset(ss,0,sizeof(ss));
    memset(tt,0,sizeof(tt));
    for(int i=0;i<lens;i++)
        if(s[i]==ch[id])
        {
            es[max(i-k,0)]++;
            es[min(i+k+1,lens)]--;
        }
    ps[0]=es[0];
    for(int i=1;i<lens;i++)ps[i]=es[i]+ps[i-1];
    for(int i=0;i<lens;i++)ss[i].x=(ps[i]>0);
    for(int i=0;i<lent;i++)tt[i].x=(t[i]==ch[id]);
    reverse(tt,tt+lent);
    int len=1;
    while(len<2*lens || len<2*lent)len<<=1;
    fft(ss,len,1);
    fft(tt,len,1);
    for(int i=0;i<len;i++)ss[i]=ss[i]*tt[i];
    fft(ss,len,-1);
    for(int i=0;i<lens;i++)cnt[id][i]=(int)(ss[i+lent-1].x+0.5);
}
int main()
{
    scanf("%d%d%d",&lens,&lent,&k);
    scanf("%s%s",s,t);
    for(int i=0;i<4;i++)work(i);
    int ans=0;
    for(int i=0;i<lens;i++)
    {
        int tot=0;
        for(int j=0;j<4;j++)tot+=cnt[j][i];
        ans+=(tot==lent);
    }
    printf("%d\n",ans);
    return 0;
}