#include <bits/stdc++.h>
using namespace std;
const int N=100050;
const int k=201;
const int mod=998244353;
int dp[N][k][2],a[N],pre[k][2];
int add(int a,int b)
{
    a+=b;
    if(a>mod)
        a-=mod;
    return a;
}
int sub(int a,int b)
{
    a-=b;
    if(a<0)
        a+=mod;
    return a;
}
/// 0- a[i] <= a[i-1]
/// 1- a[i] >  a[i-1]
int main()
{
    int n;
    scanf("%i",&n);
    vector<int> niz(n);
    for(int i=0;i<n;i++)
        scanf("%i",&niz[i]);
    if(niz[0]==-1)
    {
        for(int i=1;i<k;i++)
        {
            dp[0][i][1]=1;
        }
    }
    else
        dp[0][niz[0]][1]=1;
    for(int j=1;j<n;j++)
    {
        //printf("usao za %i %i\n",j,niz[j]);
        for(int i=1;i<k;i++)
        {
            pre[i][0]=add(pre[i-1][0],dp[j-1][i][0]);
            pre[i][1]=add(pre[i-1][1],dp[j-1][i][1]);
        }
        if(niz[j]==-1){
            for(int i=1;i<k;i++)
            {
                dp[j][i][0]=add(sub(pre[i][1],pre[i-1][1]),sub(pre[k-1][0],pre[i-1][0]));
                dp[j][i][1]=add(pre[i-1][1],pre[i-1][0]);
            }
        }
        else
        {
            //printf("Nije -1\n");
            int i=niz[j];
            dp[j][i][0]=add(sub(pre[i][1],pre[i-1][1]),sub(pre[k-1][0],pre[i-1][0]));
            dp[j][i][1]=add(pre[i-1][1],pre[i-1][0]);
        }
    }
    //printf("zavrsio");
    int ans=0;
    for(int i=1;i<k;i++)
        ans=add(ans,dp[n-1][i][0]);
    printf("%i\n",ans);
}