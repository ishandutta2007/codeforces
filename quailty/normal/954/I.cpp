#include<bits/stdc++.h>
using namespace std;

const int MAXN=125005;

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
    Complex operator / (const db &b)const
    {
        return Complex(x/b,y/b);
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
    if(on==-1)for(int i=0;i<len;i++)
        y[i]=y[i]/len;
}

int id[6][6];
pair<int,int> ty[30];
void build()
{
    int cnt=0;
    for(int i=0;i<6;i++)
        for(int j=0;j<6;j++)if(i!=j)
            ty[id[i][j]=cnt++]={i,j};
}

char s[MAXN],t[MAXN];
int sta[MAXN];

struct DSU
{
    int fa[6];
    void init(int n)
    {
        for(int i=0;i<n;i++)fa[i]=i;
    }
    int find(int x)
    {
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }
    void merge(int x,int y)
    {
        x=find(x),y=find(y);
        if(x!=y)fa[x]=y;
    }
}dsu;
int solve(int mask)
{
    dsu.init(6);
    for(int i=0;i<30;i++)
        if(mask>>i&1)
        {
            int u=ty[i].first,v=ty[i].second;
            dsu.merge(u,v);
        }
    int res=6;
    for(int i=0;i<6;i++)
        res-=(dsu.find(i)==i);
    return res;
}

Complex x1[MAXN<<2],x2[MAXN<<2];

void work(int n,int m,int a,int b)
{
    int len=1;
    while(len<2*n)len<<=1;
    for(int i=0;i<len;i++)
    {
        x1[i]=(i<n ? s[i]==a+'a' : 0);
        x2[i]=(i<m ? t[i]==b+'a' : 0);
    }
    reverse(x2,x2+m);
    fft(x1,len,1),fft(x2,len,1);
    for(int i=0;i<len;i++)
        x1[i]=x1[i]*x2[i];
    fft(x1,len,-1);
    for(int i=0;i<n;i++)
        if((int)(x1[i+m-1].x+0.5)>0)
            sta[i]|=(1<<id[a][b]);
}

int main()
{
    build();
    scanf("%s%s",s,t);
    int n=strlen(s),m=strlen(t);
    for(int i=0;i<6;i++)
        for(int j=0;j<6;j++)if(i!=j)
            work(n,m,i,j);
    for(int i=0;i<=n-m;i++)
        printf("%d%c",solve(sta[i])," \n"[i==n-m]);
    return 0;
}