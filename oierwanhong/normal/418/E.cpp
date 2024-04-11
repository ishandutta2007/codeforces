#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
typedef long long ll;
typedef unsigned un;
//typedef std::string str;
typedef std::pair<ll,ll> pll;
typedef std::pair<int,int> pii;
typedef std::pair<double,double> pd;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
void umax(ll& a,ll t){if(t>a)a=t;}
bool umin(ll& a,ll t){if(t<a)return a=t,1;return 0;}
const ll INF=1ll<<28;
#define MAXN 200011
const int B=1000;
int cnt=0,a[MAXN];
int c[211][MAXN],f[211][MAXN],fx[MAXN];
std::map<int,int>p;
void add(int x)
{
    if(!p.count(x))p[x]=++cnt,fx[cnt]=x;
}
int main()
{
    int m=read();
    for(int i=1;i<=m;++i)
    {
        add(a[i]=read());
        int now=(i-1)/B;
        if((i-1)%B==0&&now)
            for(int j=0;j<MAXN;++j)c[now][j]=c[now-1][j],f[now][j]=f[now-1][j];
        a[i]=p[a[i]];
        ll t=a[i];
        ++c[now][t],++f[now][c[now][t]];
    }
    int k=read();
    int all=(m-1)/B;
    while(k--)
    {
        int type=read();
        if(type==1)//modify 
        {
            int val=read(),pos=read(),now=(pos-1)/B;
            add(val);
            int t=a[pos];
            for(int i=now;i<=all;++i)--f[i][c[i][t]],--c[i][t];
            a[pos]=t=p[val];
            for(int i=now;i<=all;++i)++c[i][t],++f[i][c[i][t]];
        }
        else
        {
            int x=read(),y=read();
            if(x==1){printf("%d\n",fx[a[y]]);continue;}
            int now=(y-1)/B;
            for(int i=y+1;i<=min((now+1)*B,m);++i)
            {
                //printf("erase %d\n",fx[a[i]]);
                --f[now][c[now][a[i]]],--c[now][a[i]];
            }
            //printf("row2=%d,row3=%d\n",c[now][a[y]],f[now][c[now][a[y]]]);
            printf("%d\n",x&1?f[now][c[now][a[y]]]:c[now][a[y]]);
            for(int i=y+1;i<=min((now+1)*B,m);++i)
            {
                //printf("insert %d\n",fx[a[i]]);
                ++c[now][a[i]],++f[now][c[now][a[i]]];
            }
        }
    }
    return 0;
}