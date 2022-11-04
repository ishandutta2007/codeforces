#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
const int MAXN=1000005;
int fa[MAXN],dp[MAXN];
multiset<int>mp[MAXN];
void add(int u,int v)
{
    mp[u].insert(v);
}
void del(int u,int v)
{
    mp[u].erase(mp[u].lower_bound(v));
}
int get(int u)
{
    if((int)mp[u].size()==0)return 0;
    if((int)mp[u].size()==1)return *mp[u].rbegin();
    return max(*mp[u].rbegin(),*++mp[u].rbegin()+1);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n+1;i++)
    {
        int p;
        scanf("%d",&p);
        fa[i]=p;
        dp[i]=1;
        for(int j=i;j!=1;j=fa[j])
        {
            if(j!=i)del(fa[j],dp[j]);
            bool isok=0;
            if(dp[j]==get(j))isok=1;
            else dp[j]=get(j);
            add(fa[j],dp[j]);
            if(isok)break;
        }
        printf("%d ",*mp[1].rbegin()+1);
    }
    return 0;
}