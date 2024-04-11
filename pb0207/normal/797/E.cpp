#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10;
const int maxm=317;
int a[maxn],n,q,dp[maxn][maxm];
vector<int> G[maxn];

void init(void)
{
    for(int j=1;j<maxm;j++)
    {
        for(int i=n;i>=1;i--)
        {
            if(i+j+a[i]>n)
                dp[i][j]=1;
            else
                dp[i][j]=1+dp[i+j+a[i]][j];
        }
    }
}
int solve(int p,int k)
{
    int cnt=0;
    while(p<=n)
    {
        p=a[p]+p+k;
        cnt++;
    }
    return cnt;
}
int main(void)
{
    int p,k;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    init();
    cin>>q;
    while(q--)
    {
        scanf("%d%d",&p,&k);
        if(k>315)
            printf("%d\n",solve(p,k));
        else
            printf("%d\n",dp[p][k]);
    }

    return 0;
}