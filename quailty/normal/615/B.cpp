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
vector<int>e[MAXN];
int dp[MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<(int)e[i].size();j++)
            if(e[i][j]<i)
                dp[i]=max(dp[i],dp[e[i][j]]+1);
    ll res=0;
    for(int i=1;i<=n;i++)
        res=max(res,(dp[i]+1)*(ll)e[i].size());
    printf("%I64d\n",res);
    return 0;
}