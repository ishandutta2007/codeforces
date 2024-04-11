#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int MOD=1e9+7;
vector<pair<int,int>>g[100010];
int n,k[100010],b[100010];
int mypow(int x,int n){int ans=1;for(;n;n>>=1,x=1ll*x*x%MOD)if(n&1)ans=1ll*ans*x%MOD;return ans;}
void dfs(int p,int fa,int fl)
{
    if(g[p].size()==1)return;
    k[p]=0;b[p]=fl;
    for(auto i:g[p])if(i.first!=fa)dfs(i.first,p,i.second),k[p]=(k[p]+k[i.first])%MOD,b[p]=(0ll+b[p]+b[i.first]+i.second)%MOD;
    int inv=mypow(g[p].size(),MOD-2);
    k[p]=(1-1ll*k[p]*inv%MOD+MOD)%MOD;
    b[p]=1ll*b[p]*inv%MOD*mypow(k[p],MOD-2)%MOD;
    k[p]=1ll*inv*mypow(k[p],MOD-2)%MOD;
    //printf("%d %d %d\n",p,k[p],b[p]);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);x++;y++;
        g[x].push_back(make_pair(y,z));g[y].push_back(make_pair(x,z));
    }
    dfs(1,0,0);
    printf("%d\n",b[1]);
    return 0;
}