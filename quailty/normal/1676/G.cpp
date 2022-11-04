#include<bits/stdc++.h>
using namespace std;
const int MAXN=4005;
int solve()
{
    int n;
    scanf("%d",&n);
    vector<int> a(n+1);
    for(int i=2;i<=n;i++)
        scanf("%d",&a[i]);
    static char col[MAXN];
    scanf("%s",col+1);
    vector<int> dp(n+1,0);
    for(int i=1;i<=n;i++)
        dp[i]=(col[i]=='W' ? 1 : -1);
    for(int i=n;i>=2;i--)
        dp[a[i]]+=dp[i];
    int res=0;
    for(int i=1;i<=n;i++)
        res+=(dp[i]==0);
    return 0*printf("%d\n",res);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}