#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const ll Mod=1000000007;
vector<pair<int,ll> >e[MAXN];
ll val[MAXN];
vector<ll>base,path;
void dfs(int u,ll now)
{
    if(val[u]>=0)
    {
        base.push_back(now^val[u]);
        return;
    }
    path.push_back(val[u]=now);
    for(int i=0;i<(int)e[u].size();i++)
        dfs(e[u][i].first,now^e[u][i].second);
}
void gauss()
{
    for(int i=0,j=0;i<60 && j<(int)base.size();i++)
    {
        int mx=j;
        for(int k=j;k<(int)base.size();k++)
            if(base[k]&(1LL<<(59-i)))mx=k;
        if(~base[mx]&(1LL<<(59-i)))continue;
        swap(base[mx],base[j]);
        for(int k=j+1;k<(int)base.size();k++)
            if(base[k]&(1LL<<(59-i)))base[k]^=base[j];
        j++;
    }
    int tot=0;
    for(int i=0;i<(int)base.size();i++)
        if(base[i]>0)base[tot++]=base[i];
    base.erase(base.begin()+tot,base.end());
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        ll t;
        scanf("%d%d%I64d",&u,&v,&t);
        e[u].push_back(make_pair(v,t));
        e[v].push_back(make_pair(u,t));
    }
    for(int i=1;i<=n;i++)val[i]=-1;
    ll res=0;
    for(int i=1;i<=n;i++)if(val[i]<0)
    {
        base.clear(),path.clear();
        dfs(i,0);
        gauss();
        int siz=(int)base.size(),blk=(int)path.size();
        for(int j=0;j<60;j++)
        {
            int has=0,cnt[2]={0,0};
            for(int k=0;k<siz;k++)
                if(base[k]&(1LL<<j))has=1;
            for(int k=0;k<blk;k++)
                cnt[path[k]>>j&1]++;
            ll now=0;
            if(!has)now=(now+(1LL<<siz)%Mod*cnt[0]%Mod*cnt[1])%Mod;
            else now=(now+(1LL<<(siz-1))%Mod*(1LL*blk*(blk-1)/2LL%Mod))%Mod;
            res=(res+(1LL<<j)%Mod*now)%Mod;
        }
    }
    printf("%I64d\n",res);
    return 0;
}