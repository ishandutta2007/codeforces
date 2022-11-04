#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int a[MAXN],dp[MAXN],pre[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    map<int,int> la;
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[la[a[i]-1]]+1;
        pre[i]=la[a[i]-1];
        la[a[i]]=i;
    }
    int mx=0;
    for(int i=1;i<=n;i++)
        if(dp[mx]<dp[i])mx=i;
    vector<int> loc;
    while(mx)
    {
        loc.push_back(mx);
        mx=pre[mx];
    }
    int res=(int)loc.size();
    printf("%d\n",res);
    for(int i=res-1;i>=0;i--)
        printf("%d%c",loc[i]," \n"[i==0]);
    return 0;
}