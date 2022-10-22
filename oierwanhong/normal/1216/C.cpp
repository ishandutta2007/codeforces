//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
ll abs(ll x){return x>0?x:-x;}
const ll INF=1ll<<28;
/**********/
struct mat
{
    ll x1,y1,x2,y2;
    void in(){x1=read(),y1=read(),x2=read(),y2=read();}
    bool inc(ll x,ll y){return x1<=x&&x<=x2&&y1<=y&&y<=y2;}
}w;
bool in(ll x,ll y,ll x1,ll y1,ll x2,ll y2){return (x1<=x&&x<=x2&&y1<=y&&y<=y2);}
void no(){puts("NO");exit(0);}
void solve(mat a,mat b)
{
    if(a.inc(w.x1,w.y1)&&a.inc(w.x2,w.y1))
    {
        if(a.inc(w.x1,w.y2)&&a.inc(w.x2,w.y2))no();
        if(b.y1<=a.y2&&b.inc(w.x1,w.y2)&&b.inc(w.x2,w.y2))no();
    }
    if(a.inc(w.x1,w.y1)&&a.inc(w.x1,w.y2))
    {
        if(a.inc(w.x2,w.y1)&&a.inc(w.x2,w.y2))no();
        if(b.x1<=a.x2&&b.inc(w.x2,w.y1)&&b.inc(w.x2,w.y2))no();
    }
}
int main()
{
    w.in();
    mat a,b;a.in(),b.in();
    solve(a,b),solve(b,a);
    puts("YES");
    
}