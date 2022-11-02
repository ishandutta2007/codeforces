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
int cnt[110],num[110],pos[110][110],id[110][110],n,k;
pair<int,int>ans[110];
bool vis[110];
int main()
{
    scanf("%d%d",&n,&k);
    rep(i,n)cnt[i]=0;
    rep(i,k)num[i]=0;
    rep(i,n*k){int x;scanf("%d",&x);pos[x][++cnt[x]]=i;id[cnt[x]][++num[cnt[x]]]=x;}
    rep(i,n)vis[i]=0;
    rep(i,k)
    {
        if(i==1)continue;
        int rest=(n-1)/(k-1)+1;
        rep(j,n)if(rest&&!vis[id[i][j]]){rest--;int x=id[i][j];ans[x]=mp(pos[x][i-1],pos[x][i]);vis[x]=1;}
    }
    rep(i,n)printf("%d %d\n",ans[i].first,ans[i].second);
    return 0;
}