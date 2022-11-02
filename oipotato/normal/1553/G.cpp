#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int M=1e6;
const int N=150010;
bool notp[M+10];
int prime[N],tot;
int n,q,fa[N<<1],pos[M+10],tmp[N],cnt;
vector<int>g[M+10];
set<pair<int,int>>s;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main()
{
    for(int i=2;i<=M;i++)
    {
        if(!notp[i])prime[++tot]=i;
        for(int j=1;j<=tot&&1ll*i*prime[j]<=M;j++)
        {
            notp[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
    scanf("%d%d",&n,&q);
    rep(i,n){int x;scanf("%d",&x);pos[x]=i;}
    rep(i,n+tot)fa[i]=i;
    rep(i,tot)for(int j=prime[i];j<=M+1;j+=prime[i])g[j].pb(i);
    rep(i,M)if(pos[i])for(auto j:g[i])fa[find(j+n)]=find(pos[i]);
    rep(i,M)if(pos[i])
    {
        tmp[cnt=1]=find(pos[i]);
        for(auto j:g[i+1])tmp[++cnt]=find(j+n);
        sort(tmp+1,tmp+cnt+1);
        rep(i,cnt)rep(j,i-1)s.insert(mp(tmp[j],tmp[i]));
    }
    rep(i,q)
    {
        int x,y;scanf("%d%d",&x,&y);
        int a=find(x),b=find(y);if(a>b)swap(a,b);
        if(a==b)puts("0");
        else if(s.find(mp(a,b))!=s.end())puts("1");
        else puts("2");
    }
    return 0;
}