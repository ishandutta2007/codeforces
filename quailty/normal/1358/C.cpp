#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int x[2],y[2];
        for(int i=0;i<2;i++)
            scanf("%d%d",&x[i],&y[i]);
        int dx=x[1]-x[0],dy=y[1]-y[0];
        printf("%lld\n",1LL*dx*dy+1);
    }
    return 0;
}