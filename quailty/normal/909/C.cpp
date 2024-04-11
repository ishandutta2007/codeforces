#include<bits/stdc++.h>
using namespace std;
const int MAXN=5005;
const int Mod=1000000007;
char str[MAXN][5];
vector<int> a;
int dp[MAXN][MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%s",str[i]);
    for(int i=1,j=0;i<=n;i++)
    {
        if(*str[i]=='s')a.push_back(j),j=0;
        else j++;
    }
    n=(int)a.size();
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=MAXN-2;j>=0;j--)
            dp[i-1][j]=(dp[i-1][j]+dp[i-1][j+1])%Mod;
        for(int j=a[i-1];j<MAXN;j++)
            dp[i][j]=dp[i-1][j-a[i-1]];
    }
    int res=0;
    for(int j=0;j<MAXN;j++)
        res=(res+dp[n][j])%Mod;
    printf("%d\n",res);
    return 0;
}