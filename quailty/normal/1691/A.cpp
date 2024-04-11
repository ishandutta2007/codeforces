#include<bits/stdc++.h>
using namespace std;
int solve()
{
    int n,cnt[2]={0};
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        cnt[a&1]++;
    }
    return 0*printf("%d\n",min(cnt[0],cnt[1]));
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}