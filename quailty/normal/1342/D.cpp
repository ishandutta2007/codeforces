#include <bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int c[MAXN],cnt[MAXN];
vector<int> e[MAXN];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1,m;i<=n;i++)
    {
        scanf("%d",&m);
        cnt[m]++;
    }
    for(int i=1;i<=k;i++)
        scanf("%d",&c[i]);
    int res=0;
    for(int i=k,s=0;i>=1;i--)
    {
        s+=cnt[i];
        res=max(res,(s+c[i]-1)/c[i]);
    }
    printf("%d\n",res);
    for(int i=1,j=0;i<=k;i++)
        for(int t=0;t<cnt[i];t++)
            e[j++%res].push_back(i);
    for(int i=0;i<res;i++)
    {
        printf("%d",(int)e[i].size());
        for(auto &t:e[i])
            printf(" %d",t);
        printf("\n");
    }
    return 0;
}