//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<set>
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
const ll INF=1ll<<58;
/**********/
struct node
{
    ll t,num;
    bool operator <(const node& p)const{return t>p.t;}
};
std::priority_queue<node>q;
#define MAXN 200011
std::set<ll>s;
ll a[MAXN];
int main()
{
    ll n=read(),k=read();
    for(ll i=1;i<=n;++i)
    {
        ll x=read();
        if(s.count(x))continue;
        else
        {
            if(q.size()<k)q.push({i,x});
            else
            {
                s.erase(q.top().num);q.pop();
                q.push({i,x});
            }
            s.insert(x);
        }
    }
    ll len=0;
    while(!q.empty())a[++len]=q.top().num,q.pop();
    printf("%lld\n",len);
    while(len)printf("%lld ",a[len--]);
    return 0;
}