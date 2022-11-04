#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        if(n%4)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        for(int i=1;i<=n/2;i++)
            printf("%d ",2*i);
        for(int i=1;i<n/2;i++)
            printf("%d ",2*i-1);
        printf("%d\n",n/2*3-1);
    }
    return 0;
}