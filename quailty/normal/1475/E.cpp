#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
const int Mod=1000000007;
int C[MAXN][MAXN],cnt[MAXN];
int main()
{
    for(int i=(C[0][0]=1);i<MAXN;i++)
        for(int j=(C[i][0]=1);j<MAXN;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        memset(cnt,0,sizeof(cnt));
        for(int i=1,a;i<=n;i++)
            scanf("%d",&a),cnt[a]++;
        int res=1;
        for(int i=n;i>=1;i--)
        {
            int t=min(k,cnt[i]);
            res=1LL*res*C[cnt[i]][t]%Mod,k-=t;
        }
        printf("%d\n",res);
    }
    return 0;
}