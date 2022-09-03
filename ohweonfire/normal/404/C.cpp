#include <stdio.h>
#include <cmath>
#include <vector>
#define pb push_back
using namespace std;
vector<int> g[100005];
int ma[100005];
int main()
{
    int n,k,m,maxn=0;
    scanf("%d%d",&n,&k);
    int n0=0;
    for(int i=1;i<=n;i++)
    {
            int x;
            scanf("%d",&x);
            maxn=max(maxn,x);
            ma[x]++;
            g[x].pb(i);
    }
    if(ma[0]!=1){puts("-1");return 0;}
    for(int i=0;i<maxn;i++)if(ma[i]==0){puts("-1");return 0;}
    for(int i=0;i<maxn;i++)if((ma[i+1]+ma[i]-1)/ma[i]+(i>0)>k){puts("-1");return 0;}
    printf("%d\n",n-1);
    int t=1;
    for(int i=1;i<=maxn;i++)
    {
            t=0;
            for(int j=0;j<g[i].size();j++){printf("%d %d\n",g[i-1][t],g[i][j]);t=(t+1)%g[i-1].size();}
    }
    return 0;
}