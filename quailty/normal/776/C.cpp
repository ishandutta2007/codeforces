#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
map<ll,int>mp,vis;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    ll res=0,sum=0;
    mp[0]++;
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        mp[sum+=a]++;
        vis.clear();
        ll now=1;
        for(int j=0;abs(now)<1e15 && !vis[now];j++)
        {
            vis[now]=1;
            if(mp.find(sum-now)!=mp.end())res+=mp[sum-now];
            now*=k;
        }
    }
    return 0*printf("%lld",res);
}