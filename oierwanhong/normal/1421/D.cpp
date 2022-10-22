//Wan Hong 3.1
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
// static char buf[10000000],*p1=buf,*p2=buf;
// #define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,10000000,stdin),p1==p2)?EOF:*p1++
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(int& a,int b){if(b>a)return a=b,1;return 0;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
bool umin(int& a,int b){if(b<a)return a=b,1;return 0;}
int abs(int x){return x>0?x:-x;}
/**********/
#define MAXN 11
ll d[MAXN][MAXN];
void add(ll a,ll b,ll w){umin(d[a][b],w);}
int main()
{
    int task=read();
    while(task--)
    {
        memset(d,0x3f,sizeof d);
        ll x=read(),y=read();
        ll c1=read();add(7,1,c1),add(3,2,c1),add(4,7,c1),add(5,6,c1);
        ll c2=read();add(6,1,c2),add(7,2,c2),add(5,7,c2),add(4,3,c2);
        ll c3=read();add(1,2,c3),add(7,3,c3),add(5,4,c3),add(6,7,c3);
        ll c4=read();add(1,7,c4),add(2,3,c4),add(7,4,c4),add(6,5,c4);
        ll c5=read();add(1,6,c5),add(2,7,c5),add(7,5,c5),add(3,4,c5);
        ll c6=read();add(2,1,c6),add(3,7,c6),add(4,5,c6),add(7,6,c6);
        for(int k=1;k<=7;++k)
            for(int i=1;i<=7;++i)
                for(int j=1;j<=7;++j)umin(d[i][j],d[i][k]+d[k][j]);
        c1=d[7][1],c2=d[7][2],c3=d[7][3],c4=d[7][4],c5=d[7][5],c6=d[7][6];
        ll ans=0;
        if(x>=0&&y>=0){ll t=min(x,y);ans=t*c1+(x-t)*c6+(y-t)*c2;}
        else if(x>=0&&y<0){ans=x*c6+(-y)*c5;}
        else if(x<0&&y>=0){ans=(-x)*c3+y*c2;}
        else{x=-x,y=-y;ll t=min(x,y);ans=t*c4+(x-t)*c3+(y-t)*c5;}
        printf("%lld\n",ans);
    }
    return 0;
}