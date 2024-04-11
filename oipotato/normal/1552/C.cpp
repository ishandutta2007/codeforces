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
bool vis[210];
int x[210],y[210],n,k;
bool check(int i,int j)
{
    int a=x[i],flag=0;
    for(;;)
    {
        a=a%n+1;
        if(a==x[j]||a==y[j])flag^=1;
        if(a==y[i])return flag;
    }
}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        scanf("%d%d",&n,&k);n<<=1;
        rep(i,n)vis[i]=0;
        rep(i,k)scanf("%d%d",&x[i],&y[i]),vis[x[i]]=vis[y[i]]=1;
        rep(i,n)if(!vis[i])
        {
            int now=i,cnt=0;
            for(;cnt<(n-2*k)/2;now=now%n+1,cnt+=!vis[now]);
            k++;x[k]=i;y[k]=now;vis[x[k]]=vis[y[k]]=1;
        }
        int ans=0;
        rep(i,k)rep(j,i-1)if(check(i,j))ans++;
        printf("%d\n",ans);
    }
    return 0;
}