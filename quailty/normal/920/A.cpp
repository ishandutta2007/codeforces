#include<bits/stdc++.h>
using namespace std;
const int MAXN=205;
int x[MAXN];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=k;i++)
            scanf("%d",&x[i]);
        int res=0;
        for(int i=1;i<=n;i++)
        {
            int mi=n;
            for(int j=1;j<=k;j++)
                mi=min(mi,abs(i-x[j]));
            res=max(res,mi);
        }
        printf("%d\n",res+1);
    }
    return 0;
}