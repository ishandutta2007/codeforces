#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n,k,cnt[31]={0};
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        for(int j=0;j<=30;j++)
            cnt[j]+=(a>>j&1);
    }
    int res=0;
    for(int j=30;j>=0;j--)
        if(n-cnt[j]<=k)
        {
            res+=(1<<j);
            k-=n-cnt[j];
        }
    printf("%d\n",res);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}