#include<bits/stdc++.h>
using namespace std;
const int MAXN=5005;
int a[MAXN];
bool dp[MAXN][MAXN],pre[MAXN][MAXN];
int main()
{
    int n,k,v,s=0;
    scanf("%d%d%d",&n,&k,&v);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),s+=a[i];
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<k;j++)
            dp[i][j]=dp[i-1][j];
        for(int j=0;j<k;j++)if(dp[i-1][j])
            dp[i][(j+a[i])%k]=pre[i][(j+a[i])%k]=1;
    }
    if(v>s || !dp[n][v%k])return 0*printf("NO\n");
    vector<int> cho,unc;
    for(int i=n,j=v%k;i>=1;i--)
    {
        if(pre[i][j])
        {
            cho.push_back(i);
            j=(j-a[i]%k+k)%k;
        }
        else unc.push_back(i);
    }
    printf("YES\n");
    for(int i=1;i<(int)cho.size();i++)if(a[cho[i]])
    {
        printf("%d %d %d\n",(a[cho[i]]+k-1)/k,cho[i],cho[0]);
        a[cho[0]]+=a[cho[i]],a[cho[i]]=0;
    }
    for(int i=1;i<(int)unc.size();i++)if(a[unc[i]])
    {
        printf("%d %d %d\n",(a[unc[i]]+k-1)/k,unc[i],unc[0]);
        a[unc[0]]+=a[unc[i]],a[unc[i]]=0;
    }
    int tar=(cho.empty() ? unc[1] : cho[0]),bin=(unc.empty() ? cho[1] : unc[0]);
    if(a[tar]<v)printf("%d %d %d\n",(v-a[tar])/k,bin,tar);
    else if(a[tar]>v)printf("%d %d %d\n",(a[tar]-v)/k,tar,bin);
    return 0;
}