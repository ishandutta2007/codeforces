#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
#include<stack>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
const int N=1000010;
int h[N],n,k;
vector<int>g[N];
pair<int,int>f[N];
void dfs(int p)
{
    if(!g[p].size())
    {
        f[p]=mp(k,1);
        h[p]=1;
    }
    for(auto i:g[p])
    {
        dfs(i);
        if(f[i].first)f[p].first=max(f[p].first,f[i].first-1),f[p].second+=f[i].second;
    }
    for(auto i:g[p])if(f[i].first)h[p]=max(h[p],f[p].second-f[i].second+h[i]);else h[p]=max(h[p],f[p].second+h[i]);
}
int main()
{
    scanf("%d%d",&n,&k);
    rep(i,n-1){int x;scanf("%d",&x);g[x].pb(i+1);}
    dfs(1);
    printf("%d\n",max(f[1].second,h[1]));
	return 0;
}