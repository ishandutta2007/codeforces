#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int MAXN=200005;
ll a[MAXN],pre[MAXN],res[MAXN];
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(a==0 && b==0)return -1;
    if(b==0)return x=1,y=0,a;
    ll d=exgcd(b,a%b,y,x);
    return y-=a/b*x,d;
}
ll go[MAXN],id[MAXN];
int main()
{
    int n;
    ll T;
    scanf("%lld%d",&T,&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=2;i<=n+1;i++)
        pre[i]=pre[i-1]+a[(i-1)%n+1];
    ll x,y,d=exgcd(pre[n+1]%T,T,x,y),t=T/d;
    x=(x%t+t)%t;
    map<ll,vector<int> > mp;
    map<ll,int> vis;
    for(int i=1;i<=n;i++)
    {
        if(vis[pre[i]%T])continue;
        vis[pre[i]%T]=1;
        mp[pre[i]%d].push_back(i);
    }
    for(auto itr=mp.begin();itr!=mp.end();itr++)
    {
        vector<int> tmp=itr->second;
        int cnt=(int)tmp.size();
        for(int i=0;i<cnt;i++)
        {
            go[i]=((x*(pre[tmp[0]]%T-pre[tmp[i]]%T)/d)%t+t-1)%t+1;
            id[i]=i;
        }
        sort(id,id+cnt,[](ll a,ll b){return go[a]<go[b];});
        for(int i=0;i<cnt;i++)
            res[tmp[id[i]]]=go[id[i]]-(i>0 ? go[id[i-1]] : 0);
    }
    for(int i=1;i<=n;i++)
        printf("%lld ",res[i]);
    return 0;
}