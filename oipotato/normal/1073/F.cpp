#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
vector<int>g[200010];
pair<int,int>ans[200010][2];
bool key[200010];
int n,mxd,X,Y;
void work(int x)
{
    //cerr<<x<<":"<<endl;
    key[x]=0;
    int pre=x,now=g[x][0],cnt=1;
    for(;g[now].size()==2;)
    {
        //cerr<<now<<endl;
        //assert(key[now]);
        key[now]=0;
        int tmp=now;
        now=g[now][0]==pre?g[now][1]:g[now][0];
        pre=tmp;
        cnt++;
    }
    pair<int,int>tans=mp(cnt,x);
    if(tans>ans[now][0])ans[now][1]=ans[now][0],ans[now][0]=tans;
    else if(tans>ans[now][1])ans[now][1]=tans;
}
void dfs(int p,int fa,int dep,int&x)
{
    if(dep>mxd||(dep==mxd&&ans[p][0].first+ans[p][1].first>ans[x][0].first+ans[x][1].first))x=p,mxd=dep;
    for(auto i:g[p])if(key[i]&&i!=fa)dfs(i,p,dep+1,x);
}
int main()
{
    scanf("%d",&n);
    rep(i,n-1)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].pb(y);g[y].pb(x);
    }
    rep(i,n)key[i]=1;
    rep(i,n)if(g[i].size()==1)work(i);
    rep(i,n)if(key[i]){dfs(i,0,1,X);break;}
    mxd=0;
    dfs(X,0,1,Y);
    for(int i=0;i<2;i++)printf("%d %d\n",ans[X][i].second,ans[Y][i].second);
	return 0;
}