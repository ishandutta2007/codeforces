#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN=100005;
int a[MAXN],dep[MAXN];
vector<int> e[MAXN];
void dfs(int u)
{
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        dep[v]=dep[u]+1;
        dfs(v);
    }
}
map<int,int> mp;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=2;i<=n;i++)
    {
        int p;
        scanf("%d",&p);
        e[p].push_back(i);
    }
    dfs(1);
    int mx=0,cnt[2]={0,0},sum=0;
    for(int i=1;i<=n;i++)
        mx=max(mx,dep[i]),cnt[dep[i]&1]++;
    for(int i=1;i<=n;i++)
        if(dep[i]%2==mx%2)sum^=a[i];
    long long res=0;
    if(sum==0)for(int i=0;i<2;i++)
        res+=1LL*cnt[i]*(cnt[i]-1)/2;
    for(int i=1;i<=n;i++)
        if(dep[i]%2==mx%2)mp[a[i]]++;
    for(int i=1;i<=n;i++)
        if(dep[i]%2!=mx%2)
            res+=mp[a[i]^sum];
    return 0*printf("%lld",res);
}