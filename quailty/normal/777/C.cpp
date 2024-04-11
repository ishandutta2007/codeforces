#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
vector<int>a[MAXN],dp[MAXN];
int len[MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        a[i].resize(m+1);
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    }
    for(int i=1;i<=n;i++)
    {
        dp[i].resize(m+1,1);
        if(i>1)for(int j=1;j<=m;j++)
            dp[i][j]+=(a[i][j]>=a[i-1][j] ? dp[i-1][j] : 0);
        for(int j=1;j<=m;j++)
            len[i]=max(len[i],dp[i][j]);
    }
    int k;
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%s\n",(len[r]>=r-l+1 ? "Yes" : "No"));
    }
    return 0;
}